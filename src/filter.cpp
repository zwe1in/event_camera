#include "filter.h"

cv::Mat closeOperate(cv::Mat src, 
                    cv::Mat kernel)
{
    cv::cuda::GpuMat d_src, d_kernel, d_dst;
    cv::Mat dst;
    d_src.upload(src);
    d_kernel.upload(kernel);
cv::Ptr<cv::cuda::Filter> filter = cv::cuda::createMorphologyFilter(cv::MORPH_CLOSE, CV_8UC1, kernel);
    filter->apply(d_src, d_dst);
    d_dst.download(dst);
    return dst;
}

cv::Mat openOperate(cv::Mat src, 
                    cv::Mat kernel)
{
    cv::cuda::GpuMat d_src, d_kernel, d_dst;
    cv::Mat dst;
    d_src.upload(src);
    d_kernel.upload(kernel);
    cv::Ptr<cv::cuda::Filter> filter = cv::cuda::createMorphologyFilter(cv::MORPH_OPEN, CV_8UC1, kernel);
    filter->apply(d_src, d_dst);
    d_dst.download(dst);
    return dst;
}

void getThin(cv::Mat src, 
            cv::Mat dst, 
            int intera)
{
    if(src.type()!=CV_8UC1)
        {
        printf("只能处理二值或灰度图像\n");
        return;
        }
    //非原地操作时候，copy src到dst
    if(dst.data!=src.data)
        {
        src.copyTo(dst);
        }

    int i, j, n;
    int width, height;
    width = src.cols -1;
    //之所以减1，是方便处理8邻域，防止越界
    height = src.rows -1;
    int step = src.step;
    int  p2,p3,p4,p5,p6,p7,p8,p9;
    uchar* img;
    bool ifEnd;
    int A1;
    cv::Mat tmpimg;
    //n表示迭代次数
    for(n = 0; n<intera; n++)
        {
        dst.copyTo(tmpimg);
        ifEnd = false;
        img = tmpimg.data;
        for(i = 1; i < height; i++)
            {
            img += step;
            for(j =1; j<width; j++)
                {
                uchar* p = img + j;
                A1 = 0;
                if( p[0] > 0)
                    {
                    if(p[-step]==0&&p[-step+1]>0) //p2,p3 01模式
                        {
                        A1++;
                        }
                    if(p[-step+1]==0&&p[1]>0) //p3,p4 01模式
                        {
                        A1++;
                        }
                    if(p[1]==0&&p[step+1]>0) //p4,p5 01模式
                        {
                        A1++;
                        }
                    if(p[step+1]==0&&p[step]>0) //p5,p6 01模式
                        {
                        A1++;
                        }
                    if(p[step]==0&&p[step-1]>0) //p6,p7 01模式
                        {
                        A1++;
                        }
                    if(p[step-1]==0&&p[-1]>0) //p7,p8 01模式
                        {
                        A1++;
                        }
                    if(p[-1]==0&&p[-step-1]>0) //p8,p9 01模式
                        {
                        A1++;
                        }
                    if(p[-step-1]==0&&p[-step]>0) //p9,p2 01模式
                        {
                        A1++;
                        }
                    p2 = p[-step]>0?1:0;
                    p3 = p[-step+1]>0?1:0;
                    p4 = p[1]>0?1:0;
                    p5 = p[step+1]>0?1:0;
                    p6 = p[step]>0?1:0;
                    p7 = p[step-1]>0?1:0;
                    p8 = p[-1]>0?1:0;
                    p9 = p[-step-1]>0?1:0;
                    if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7  &&  A1==1)
                        {
                        if((p2==0||p4==0||p6==0)&&(p4==0||p6==0||p8==0)) //p2*p4*p6=0 && p4*p6*p8==0
                            {
                            dst.at<uchar>(i,j) = 0; //满足删除条件，设置当前像素为0
                            ifEnd = true;
                            }
                        }
                    }
                }
            }
        
        dst.copyTo(tmpimg);
        img = tmpimg.data;
        for(i = 1; i < height; i++)
            {
            img += step;
            for(j =1; j<width; j++)
                {
                A1 = 0;
                uchar* p = img + j;
                if( p[0] > 0)
                    {
                    if(p[-step]==0&&p[-step+1]>0) //p2,p3 01模式
                        {
                        A1++;
                        }
                    if(p[-step+1]==0&&p[1]>0) //p3,p4 01模式
                        {
                        A1++;
                        }
                    if(p[1]==0&&p[step+1]>0) //p4,p5 01模式
                        {
                        A1++;
                        }
                    if(p[step+1]==0&&p[step]>0) //p5,p6 01模式
                        {
                        A1++;
                        }
                    if(p[step]==0&&p[step-1]>0) //p6,p7 01模式
                        {
                        A1++;
                        }
                    if(p[step-1]==0&&p[-1]>0) //p7,p8 01模式
                        {
                        A1++;
                        }
                    if(p[-1]==0&&p[-step-1]>0) //p8,p9 01模式
                        {
                        A1++;
                        }
                    if(p[-step-1]==0&&p[-step]>0) //p9,p2 01模式
                        {
                        A1++;
                        }
                    p2 = p[-step]>0?1:0;
                    p3 = p[-step+1]>0?1:0;
                    p4 = p[1]>0?1:0;
                    p5 = p[step+1]>0?1:0;
                    p6 = p[step]>0?1:0;
                    p7 = p[step-1]>0?1:0;
                    p8 = p[-1]>0?1:0;
                    p9 = p[-step-1]>0?1:0;
                    if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7  &&  A1==1)
                        {
                        if((p2==0||p4==0||p8==0)&&(p2==0||p6==0||p8==0)) //p2*p4*p8=0 && p2*p6*p8==0
                            {
                            dst.at<uchar>(i,j) = 0; //满足删除条件，设置当前像素为0
                            ifEnd = true;
                            }
                        }
                    }
                }
            }

        //如果两个子迭代已经没有可以细化的像素了，则退出迭代
        if(!ifEnd) break;
        }
}

void framePredication(std::vector<cv::Mat>& src)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1,2));
    // cv::Mat element1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1,2));
    cv::Mat element2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7,7));
    for(int i = 0; i < src.size(); i++)
    {   
        cv::Mat close_out = closeOperate(src[i], element2);
        cv::Mat close_out1 = openOperate(close_out, element);
        //cv::Mat close_out2 = openOperate(close_out1, element1);
        cv::Mat thin_out(cv::Size(src[i].cols, src[i].rows), CV_8UC1);
        getThin(close_out1, thin_out, 1);
        src[i] = thin_out;
    }
    std::cout<<"predication success"<<std::endl;
}

void seedFilling(cv::Mat &img, 
            cv::Mat &labelImg)
{
    if(img.empty() || img.type() != CV_8UC1)
    {
        return;
    } 
    labelImg.release();
    img.convertTo(labelImg, CV_32SC1);

    int label = 1;
    int rows = img.rows;
    int cols = img.cols;

    for(int i = 1; i < rows - 1; i++)
    {
        int *data = labelImg.ptr<int>(i);
        for(int j = 1; j < cols - 1; j++)
        {
            if(data[j] == 1)
            {
                std::stack<std::pair<int,int>> neighbour;
                neighbour.push(std::pair<int, int>(i, j));
                label++;
                while(!neighbour.empty())
                {
                    std::pair<int, int> cur = neighbour.top();
                    int curRow = cur.first;
                    int curCol = cur.second;
                    labelImg.at<int>(curRow, curCol) = label;
                    neighbour.pop();

                    // 将相邻的元素加如栈堆
                    if(labelImg.at<int>(curRow - 1, curCol - 1) == 1)
                    {//左上角
                        neighbour.push(std::pair<int, int>(curRow - 1, curCol - 1));
                    }

                    if(labelImg.at<int>(curRow - 1, curCol + 1) == 1)
                    {//右上角
                        neighbour.push(std::pair<int, int>(curRow - 1, curCol + 1));
                    }

                    if(labelImg.at<int>(curRow + 1, curCol - 1) == 1)
                    {//左下角
                        neighbour.push(std::pair<int, int>(curRow + 1, curCol - 1));
                    }

                    if(labelImg.at<int>(curRow + 1, curCol + 1) == 1)
                    {//右下角
                        neighbour.push(std::pair<int, int>(curRow + 1, curCol + 1));
                    }

                    if(labelImg.at<int>(curRow - 1, curCol) == 1)
                    {//正上方
                        neighbour.push(std::pair<int, int>(curRow - 1, curCol));
                    }

                    if(labelImg.at<int>(curRow + 1, curCol) == 1)
                    {//正下方
                        neighbour.push(std::pair<int, int>(curRow + 1, curCol));
                    }

                    if(labelImg.at<int>(curRow, curCol - 1) == 1)
                    {//正左方
                        neighbour.push(std::pair<int, int>(curRow, curCol - 1));
                    }

                    if(labelImg.at<int>(curRow, curCol + 1) == 1)
                    {//正右方
                        neighbour.push(std::pair<int, int>(curRow, curCol + 1));
                    }
                }
            }
        }
    }
}

cv::Scalar getColor()
{
    uchar r = 255 * (rand()/(1.0+RAND_MAX));
    uchar g = 255 * (rand()/(1.0+RAND_MAX));
    uchar b = 255 * (rand()/(1.0+RAND_MAX));
    return cv::Scalar(b,g,r);
}

void labelColor(const cv::Mat &labelImg, 
                cv::Mat &colorImg)
{
    if(labelImg.empty() || labelImg.type() != CV_32SC1)
    {
        return;
    }

    std::map<int, cv::Scalar> colorMap;
    int rows = labelImg.rows;
    int cols = labelImg.cols;

    colorImg.release();
    colorImg.create(rows, cols, CV_8UC3);
    colorImg = cv::Scalar::all(0);

    cv::Mat channels[3];
    cv::split(colorImg, channels);
    cv::Scalar color;
    for(int i = 0; i < rows; i++)
    {
        const int *src = labelImg.ptr<int>(i);
        for(int j = 0; j < cols; j++)
        {
            int pixe = src[j];
            if(pixe > 1)
            {
                // 颜色表赋值
                if(colorMap.count(pixe) <= 0)
                {
                    colorMap[pixe] = getColor();
                }
                color = colorMap[pixe];
                for(int ch = 0; ch < 3; ch++)
                {
                    uchar *dst = channels[ch].ptr<uchar>(i);
                    dst[j] = color[ch];
                }
            }
        }
    }
    cv::merge(channels, 3, colorImg);
}

void quickSort(int *arr, int low, int high)
{
    if(low > high)
    {
        return;
    }
    int i = low;
    int j = high;
    int temp = arr[low];
    while(i < j)
    {
        while(i < j && arr[j] >= temp)
            j--;
        arr[i] = arr[j];
        while(i < j && arr[i] <= temp)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = temp;
    quickSort(arr, low, i-1);
    quickSort(arr, i+1, high);
}

void labelFilter(cv::Mat &labelImg, int standard)
{
    if(labelImg.empty() || labelImg.type() != CV_32SC1)
    {
        std::cout<<"The input must be not empty and CV_32SC1 type";
        return;
    }
    std::map<int, int> pixeMap;
    int rows = labelImg.rows;
    int cols = labelImg.cols;
    std::cout<<"complete"<<std::endl;
    // 统计每个连通区域的点数量
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int pixe = labelImg.at<int>(i, j);
            if(pixeMap.count(pixe) <= 0)
            {
                pixeMap[pixe] = 1;
            }
            else
            {
                pixeMap[pixe] += 1;
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        int *p = labelImg.ptr<int>(i);
        for(int j = 0; j < cols; j++)
        {
            if(pixeMap[p[j]] >= standard && p[j] != 0)
                p[j] = 1;
            else p[j] = 0;
        }
    }
    labelImg.convertTo(labelImg, CV_8UC1);
}