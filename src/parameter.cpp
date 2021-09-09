#include "parameter.h"

parameter::parameter(int size)
{
    this->size = size;
    this->S = new double[size];
    this->A = new double[size-1];
    this->B = new double[size-1];
    this->C = new double[size-1];
    this->D = new double[size-1];
    std::cout<<"success"<<std::endl;
    
}
parameter::parameter(int size, double* s, double *a, double *b, double *c, double *d)
{
    this->size = size;
    this->S = new double[size];
    this->A = new double[size-1];
    this->B = new double[size-1];
    this->C = new double[size-1];
    this->D = new double[size-1];
    for(int i = 0; i < size -1; i++)
    {
        this->S[i] = s[i];
        this->A[i] = a[i];
        this->B[i] = b[i];
        this->C[i] = c[i];
        this->D[i] = d[i];
    }
    this->S[size - 1] = s[size - 1];
}
parameter::~parameter()
{
    delete this->S;
    delete this->A;
    delete this->B;
    delete this->C;
    delete this->D;
}

void parameter::reconstruct(int size, double* s, double *a, double *b, double *c, double *d)
{
    this->size = size;
    this->S = new double[size];
    this->A = new double[size-1];
    this->B = new double[size-1];
    this->C = new double[size-1];
    this->D = new double[size-1];
    for(int i = 0; i < size -1; i++)
    {
        this->S[i] = s[i];
        this->A[i] = a[i];
        this->B[i] = b[i];
        this->C[i] = c[i];
        this->D[i] = d[i];
    }
    this->S[size - 1] = s[size - 1];
}

int parameter::getSize()
{
    return this->size;
}

void parameter::getParam(double *s, double *a, double *b, double *c, double *d)
{
    for(int i = 0; i < size -1; i++)
    {
        s[i] = this->S[i];
        a[i] = this->A[i];
        b[i] = this->B[i];
        c[i] = this->C[i];
        d[i] = this->D[i];
    }
    s[size-1] = this->S[size-1];
}

void parameter::paramWriter(std::string path)
{
    std::ofstream ofile(path);
    if(ofile.is_open())
    {
        int size = this->size;
        for(int i = 0; i < size - 1; i++)
        {
            ofile << this->S[i];
            ofile << " ";
            ofile << this->A[i];
            ofile << " ";
            ofile << this->B[i];
            ofile << " ";
            ofile << this->C[i];
            ofile << " ";
            ofile << this->D[i];
            ofile << "\n";
            std::cout<<this->S[i]<<" "<<this->A[i]<<" "<<this->B[i]<<" "<<this->C[i]<<" "<<this->D[i]<<std::endl;
        }
        ofile << this->S[size - 1];
    }
    ofile.close();
}