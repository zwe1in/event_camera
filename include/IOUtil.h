#pragma once

#ifndef IOUTIL_H
#define IOUTIL_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <map>
#include "event.h"
#include "region.h"
#include "parameter.h"
#include "parameterize.h"

cv::Mat readFirstFrame(std::string path, double framerate);

std::vector<cv::Mat> readAllFrame(std::string path, double framerate);

std::vector<Frame> readFrames(std::string path, double framerate);

void regionSplit(cv::Mat &img, std::vector<region> &regions);

void eventFilter(cv::Mat& img, std::vector<Event>& src);

void frameFilter(std::vector<cv::Mat>& imgs, std::vector<Frame>& src);

void valueTransform(cv::Mat& src);

int pointCount(cv::Mat& src);

void linePointWriter(std::string path, parameter &px, parameter &py, int width, int height);

void lineDraw(std::string path, cv::Mat &dst);

#endif