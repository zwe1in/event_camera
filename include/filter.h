#pragma once
#ifndef FILTER_H
#define FILTER_H

#include <opencv2/opencv.hpp>
#include <opencv2/cudafilters.hpp>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

cv::Mat closeOperate(cv::Mat src, cv::Mat kernel);

cv::Mat openOperate(cv::Mat src, cv::Mat kernel);

void getThin(cv::Mat src, cv::Mat dst, int intera);

void framePredication(std::vector<cv::Mat>& src);

void seedFilling(cv::Mat &img, cv::Mat &labelImg);

cv::Scalar getColor();

void labelColor(const cv::Mat &labelImg, cv::Mat &colorImg);

void labelFilter(cv::Mat &labelImg, int standard);
#endif