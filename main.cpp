#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/cudafilters.hpp>
#include "IOUtil.h"
#include "filter.h"
#include "parameterize.h"

int main(void)
{
    // 数据读取
    std::vector<cv::Mat> images = readAllFrame("/home/zw/rotate/out.txt", 50.0);
    int cols = images[0].cols;
    int rows = images[0].rows;

    // 滤波、连通区域标记
    std::vector<cv::Mat> labelColorImgs;    // 每一帧经过彩色标记后的图片列表
    for(int i = 0; i < images.size(); i++)
    {
        cv::Mat labelFilt(rows, cols, CV_32SC1);
        cv::Mat labelImg(rows, cols, CV_32SC1);
        cv::Mat colorImg;
        seedFilling(images[i], labelFilt);
        labelFilter(labelFilt, 50);
        // 细化
        getThin(labelFilt, labelFilt, 1);
        // 连通标记，上色
        seedFilling(labelFilt, labelImg);
        images[i] = labelImg;
        labelColor(labelImg, colorImg);
        labelColorImgs.push_back(colorImg);
    }

    // 封装成点参数
    std::vector<std::vector<region>> frames;
    for(int i = 0; i < images.size(); i++)
    {// 每一帧
        std::vector<region> regions;
        regionSplit(images[i],regions);
        frames.push_back(regions);
    }
    std::cout<<"point complete"<<std::endl;
    
    // 参数曲线化
    for(int i = 0; i < frames.size(); i++)
    {
        std::vector<region> frame = frames[i];
        for(int j = 0; j < frame.size(); j++)
        {
            std::vector<Event> events = frame[j].getEvents();
            std::cout<<events.size()<<std::endl;
            parameter px(events.size());
            parameter py(events.size());
            getLineXY(events, px, py);
            std::cout<<"get line success"<<std::endl;
            std::string path = "/home/zw/rotate/rotate" + std::to_string(i) + "_r" + std::to_string(j);
            linePointWriter(path, px, py, cols, rows);
        }
    }

    cv::Mat lineImg(rows, cols, CV_8UC3);
    std::ifstream ifile;
    double x, y;
    for(int i = 0; i < frames[0].size(); i++)
    {
        std::string path_name = "/home/zw/rotate/rotate0_r" + std::to_string(i);
        ifile.open(path_name);
        cv::Scalar color = getColor();
        while(!ifile.eof())
        {
            ifile >> x;
            ifile >> y;
            cv::circle(lineImg, cv::Point(x,y), 1, color, -1);
        }
        ifile.close();
    }
    
    cv::imshow("color0", labelColorImgs[0]);
    cv::imshow("color1", labelColorImgs[1]);
    cv::imshow("color2", labelColorImgs[2]);
    cv::imshow("line", lineImg);
    cv::waitKey(0);
    return 0;
}