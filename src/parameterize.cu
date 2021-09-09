#include "parameterize.h"

void getXY( std::vector<Event>& events, 
            thrust::device_vector<int>& x,
            thrust::device_vector<int>& y)
    {
        for(int i = 0; i < events.size(); i++)
        {
            x[i] = events[i].x;
            y[i] = events[i].y;
        }
    }

struct minus
{
    __host__ __device__
        int operator()(const int &a, const int &b)const{
            return a - b;
        }
};

void getMinux(thrust::device_vector<int>& src,
                 thrust::device_vector<int>& dst)
    {
        thrust::transform(src.begin()+1, src.end(), src.begin(),dst.begin(), minus());
    }

struct stepp
{
    __host__ __device__
        double operator()(const int &x_m, const int &y_m)const{
            return (double)(x_m*x_m + y_m*y_m);
        }
};

void getStep(thrust::device_vector<int>& x, 
                thrust::device_vector<int>& y,
                thrust::device_vector<double>& step)
    {
        thrust::transform(x.begin(), x.end(), y.begin(), step.begin(), stepp());
        for(int i = 0; i < step.size(); i++)
        {
            step[i] = sqrt(step[i]);
        }
        thrust::exclusive_scan(step.begin(), step.end(), step.begin());
    }

void test(std::vector<Event>& events,
            std::vector<int>& x, 
            std::vector<int>& y
            )
    {
        thrust::device_vector<int> _x(x.begin(), x.end());
        thrust::device_vector<int> _y(y.begin(), y.end());
        thrust::device_vector<double> step(events.size()-1);
        getXY(events, _x, _y);
        thrust::copy(_x.begin(), _x.end(), x.begin());
        thrust::copy(_y.begin(), _y.end(), y.begin());
        std::cout<<x[1]-x[0]<<std::endl;
        std::cout<<x[2]-x[1]<<std::endl;
        getMinux(_x, _x);
        getStep(_x, _y, step);
        std::cout<<sqrt(_x[0]*_x[0] + _y[0]*_y[0])<<std::endl;
        std::cout<<step[0]<<" "<<step[1]<<std::endl;
    }


void spline(thrust::device_vector<double>& x, 
            thrust::device_vector<int>& y,
            double bound1, 
            double boundn,
            parameter &p )
    {
        //总点数
        int n  = x.size();
        // h[i] = x[i+1] - x[i]
        thrust::device_vector<double> h(n - 1);
        thrust::transform(x.begin() + 1, x.end(), x.begin(), h.begin(), thrust::minus<double>());
        // 稀疏矩阵
        thrust::device_vector<double> a(n, 2);   // 中间一斜列, n个
        thrust::device_vector<double> c(n);      // 上方一斜列 n-1个
        c[0] = 1;
        for(int i = 1; i < n - 1; i++)
            c[i] = h[i] / (h[i-1] + h[i]);
        thrust::device_vector<double> b(n);      // 下方一斜列 n-1个
        for(int i = 1; i < n - 1; i++)
            b[i] = h[i-1] / (h[i-1] + h[i]);
        b[n-1] = 1; 
        b[0] = 0; //b[0]实际上不存在
        c[n-1] = 0; //c[n-1]实际上不存在

        // 右边的d
        thrust::device_vector<double> d(n);
        d[0] = 6*((y[1] - y[0])/h[0] - bound1)/h[0];
        d[n - 1] = 6*(boundn - (y[n-1] - y[n-2])/h[n-2])/h[n-2];
        for(int i = 1; i < n-1; i++)
            d[i] = 6*((y[i+1]-y[i])/h[i] - (y[i] - y[i-1])/h[i-1])/(h[i]+h[i-1]);

        // 追赶法解方程组
        thrust::device_vector<double> l(n); 
        thrust::device_vector<double> m(n);
        thrust::device_vector<double> u(n);
        l[0] = a[0];
        u[0] = c[0]/l[0];
        m[0] = 0;   //实际上不存在
        for(int i = 1; i < n; i++)
        {
            l[i] = a[i] - b[i]*u[i-1];
            u[i] = c[i]/l[i];
            m[i] = b[i];
        }
        //AM=d => LUM=Lt=d, 先解决Lt=d
        thrust::device_vector<double> t(n);
        t[0] = d[0]/l[0];
        for(int i = 1; i < n; i++)
            t[i] = d[i] - m[i]*t[i-1];
        
        //解决t=UM, M就是每个转折点的二阶导数
        thrust::device_vector<double> M(n);
        M[n-1] = t[n-1];
        for(int i = n-2; i >=0; i--)
            M[i] = t[i] - u[i]*M[i+1];
        
        double A[n-1], B[n-1], C[n-1], D[n-1];
        for(int i = 0; i < n-1; i++)
        {
            A[i] = y[i];
            B[i] = (y[i+1]-y[i])/h[i] - h[i]*M[i]/2 - h[i]*(M[i+1] - M[i])/6;
            C[i] = M[i]/2;
            D[i] = (M[i+1] - M[i])/h[i]/6;
        }
        double s[n];
        thrust::copy(x.begin(), x.end(),s);
        std::cout<<"reconstruct start"<<std::endl;
        p.reconstruct(n, s, A, B, C, D);
        p.paramWriter("/home/zw/rotate/param.txt");
        std::cout<<"reconstruct success"<<std::endl;
    }

void splint(parameter& p, double &x, double &y)
    {
        //二分法查找x点所在区间
        int start, end, mid;
        int size = p.getSize();
        double *S, *A, *B, *C, *D;
        S = new double[size];
        A = new double[size -1];
        B = new double[size -1];
        C = new double[size -1];
        D = new double[size -1];
        p.getParam(S, A, B, C, D);
        start = 0; end = size - 1;

        while (end - start > 1)
        {
            mid = (end + start)/2;
            if(S[mid] > x) end = mid;
            else start = mid;
        }
        int index = S[mid] > x?(mid-1):mid;
        y = A[index] + B[index]*(x - S[index])+C[index]*(x-S[index])*(x-S[index])+D[index]*(x-S[index])*(x-S[index])*(x-S[index]);        
        delete S;
        delete A;
        delete B;
        delete C;
        delete D;
    }

void getLineXY(std::vector<Event> &events, parameter &px, parameter &py)
{
    int n = events.size();
    thrust::device_vector<int> x(n);
    thrust::device_vector<int> y(n);
    getXY(events, x, y);
    thrust::device_vector<double> step(n);
    getStep(x, y, step);
    spline(step, x, 0, 0, px);
    spline(step, y, 0, 0, py);
}

template <typename T>
struct triple
{
    __host__ __device__
        T operator()(const T& x) const { 
            return x * x * x;
        }
};

template <typename T>
struct power
{
    int time;

    power(int _time) : time(_time){}

    __host__ __device__
        T operator()(const T& x) const{
            T temp = 1;
            for(int i = 0; i < time; i++)
            {
                temp *= x;
            }
            return temp;
        }
};


struct power_xy
{
    int time;

    power_xy(int _time) : time(_time){}

    __host__ __device__
        double operator()(const double& x, const int& y) const{
            double temp = 1.0;
            for(int i = 0; i < time; i++)
            {
                temp *= x;
            }
            return temp * y;
            
        }
};

void least_square(thrust::device_vector<double>& x, 
                    thrust::device_vector<int>& y)
    {
        int n = x.size();
        double _x[7], _xy[4];
        for(int i = 0; i < 7; i++)
        {
            _x[i] = thrust::transform_reduce(x.begin(), x.end(), power<double>(i), 0, thrust::plus<double>()) / n;
        }
        for(int i = 0; i < 4; i++)
        {
            thrust::device_vector<double> temp(n);
            thrust::transform(x.begin(), x.end(), y.begin(), temp.begin(), power_xy(i));
            _xy[i] = thrust::reduce(temp.begin(), temp.end()) / n;
        }

    }