#pragma once

#ifndef PARAMETERIZE_H
#define PARAMETERIZE_H

#include<iostream>
#include<math.h>
#include<thrust/device_vector.h>
#include<thrust/host_vector.h>
#include<thrust/transform.h>
#include<thrust/reduce.h>
#include<thrust/transform_reduce.h>
#include<thrust/functional.h>
#include "event.h"
#include "parameter.h"

void getXY( std::vector<Event>& events, 
            thrust::device_vector<int>& x,
            thrust::device_vector<int>& y);

void getMinux(thrust::device_vector<int>& src,
                 thrust::device_vector<int>& dst);

void getStep(thrust::device_vector<int>& x, 
                thrust::device_vector<int>& y,
                thrust::device_vector<double>& step);

void test(std::vector<Event>& events, std::vector<int>& x, std::vector<int>&y);

void spline(thrust::device_vector<double>& x, 
            thrust::device_vector<int>& y,
            double bound1, 
            double boundn,
            parameter &p);

void splint(parameter& p, double &x, double &y);

void getLineXY(std::vector<Event> &events, parameter &px, parameter &py);

void least_square(thrust::device_vector<double>& x, 
                    thrust::device_vector<int>& y);

void fit(std::vector<Event>& events);
#endif