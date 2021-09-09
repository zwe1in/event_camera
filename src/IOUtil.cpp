#include "IOUtil.h"


cv::Mat readFirstFrame(std::string path, double framerate)
{
    int width, height;
    std::ifstream file(path);
    if(!file.is_open())
    {
        throw "Can not open the file.";
    }
    file >> width;
    file >> height;
    std::cout<<width<<" X "<<height<<std::endl;

    double time = 0.0;
    double timeOut = 1 / framerate;
    int x,y,p;
    cv::Mat image(height, width, CV_8UC1);
    while (time < timeOut)
    {
        file >> time;
        file >> x;
        file >> y;
        file >> p;
        image.at<uchar>(y,x) = 1;
        printf("%lf %d %d %d\n", time, x, y, p);
    }
    file.close();
    
    return image;
}

std::vector<cv::Mat> readAllFrame(std::string path, double framerate)
{
    double timePerFrame = 1 / framerate;
    int width, height;
    std::ifstream file(path);
    if(!file.is_open())
    {
        throw "Can not open the file.";
    }
    file >> width;
    file >> height;
    std::vector<cv::Mat> result;
    double time = 0.0;
    double timeOut = timePerFrame;
    while(1)
    {
        int x, y, p;
        cv::Mat image(height, width, CV_8UC1);
        while (time < timeOut)
        {
            file >> time;
            file >> x;
            file >> y;
            file >> p;
            image.at<uchar>(y, x) = 1;
            printf("%lf %d %d %d\n", time, x, y, p);
            if(file.eof()){break;}
        }
        result.push_back(image);
        timeOut += timePerFrame;
        if(file.eof()){break;}
    }
    return result;
}

std::vector<Frame> readFrames(std::string path, double framerate)
{
    double timePerFrame = 1 / framerate;
    int width, height;
    std::ifstream file(path);
    if(!file.is_open())
    {
        throw "Can not open the file.";
    }
    file >> width;
    file >> height;

    double time = 0.0;
    double timeOut = timePerFrame;
    std::vector<Frame> frames;
    while(1)
    {
        int x, y, p;
        int count = 0;
        std::vector<Event> events;
        while (time < timeOut)
        {
            file >> time;
            file >> x;
            file >> y;
            file >> p;
            Event event(x,y);
            events.push_back(event);
            ++count;
            printf("%lf %d %d %d\n", time, x, y, p);
            if(file.eof()){break;}
        }
        Frame frame(events, count, width, height);
        frames.push_back(frame);
        timeOut += timePerFrame;
        if(file.eof()){break;}
    }
    return frames;
}

void regionSplit(cv::Mat &img, std::vector<region> &regions)
{
    int rows = img.rows;
    int cols = img.cols;
    
    std::map<int, region> regionMap;
    for(int i = 0; i < rows; i++)
    {
        int *imgPtr = img.ptr<int>(i);
        for(int j = 0; j < cols; j++)
        {
            int pixe = imgPtr[j];
            if(pixe == 0) continue;
            if(regionMap.count(pixe) <= 0)
            {
                std::vector<Event> events;
                Event e(j,i);
                events.push_back(e);
                region rg(1, events, pixe);
                regionMap[pixe] = rg;
            }
            else
            {
                Event e(j, i);
                regionMap[pixe].addEvent(e);
            }
        }
    }

    std::map<int, region>::iterator itor = regionMap.begin();
    while(itor != regionMap.end())
    {
        regions.push_back(itor->second);
        itor++;
    }
    // for(int i = 0; i < regions.size(); i++)
    // {
    //     std::cout<<regions[i].getEvents().size()<<" "<<regions[i].getCount()<<std::endl;
    // }
}

void eventFilter(cv::Mat& img, std::vector<Event>& src)
{
    std::vector<Event>::iterator itor = src.begin();
    while(itor != src.end())
    {
        int row = (*itor).y;
        int col = (*itor).x;
        if(img.at<uchar>(row,col) == 0)
        {
            itor = src.erase(itor);
        }
        else
        {
            ++itor;
        }
        std::cout<<row<<","<<col<<std::endl;
    }
}

void frameFilter(std::vector<cv::Mat>& imgs, std::vector<Frame>& src)
{
    if(imgs.size() != src.size())
        throw "The size of the two list must be the same";
    int count = 0;
    for(int i = 0; i < imgs.size(); i++)
    {
        cv::Mat img = imgs[i];
        std::vector<Event> events = src[i].getEvents();
        std::vector<Event>::iterator itor = events.begin();
        while(itor != events.end())
        {
            int row = (*itor).y;
            int col = (*itor).x;
            if(img.at<uchar>(row, col) == 0)
            {
                itor = events.erase(itor);
            }
            else
            {
                ++itor;
            }
        }
        src[i].setEvents(events);
        src[i].setCount(pointCount(img));
        std::cout<<"complete frame "<<++count<<std::endl;
        // 空间释放
        std::vector<Event> temp;
        temp.swap(events);
    }
}

void valueTransform(cv::Mat& src)
{
    int width = src.cols;
    int height = src.rows;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(src.at<uchar>(i,j) == 1)
                src.at<uchar>(i, j) = 255;
        }
    }
}

int pointCount(cv::Mat& src)
{
    int count = 0;
    int width = src.cols;
    int height = src.rows;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(src.at<uchar>(i,j) != 0)
                ++count;
        }
    }
    return count;
}

void linePointWriter(std::string path, parameter &px, parameter &py, int width, int height)
{
    std::ofstream ofile;
    ofile.open(path, std::ios::app);
    if(ofile.is_open())
    {
        double x,y,s;
        for(s = 0; s < 1000000; s +=1000)
        {   
            splint(px, s, x);
            splint(py, s, y);
            if(x < 0 || y < 0 || x > width || y > height) 
                continue;
            ofile << x;
            ofile << " ";
            ofile << y;
            ofile << "\n";
        }
    }
    ofile.close();
}

void lineDraw(std::string path, cv::Mat &dst)
{
    std::ifstream ifile(path);
    double x, y;
    if(ifile.is_open())
    {
        while(1)
        {
            ifile >> x;
            ifile >> y;
            cv::circle(dst, cv::Point(x,y), 1, cv::Scalar(255,255,255), -1);
            if(ifile.eof()) break;
        }
    }
    ifile.close();
}