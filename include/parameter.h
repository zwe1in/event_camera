#pragma once
#ifndef PARAMETER_H
#define PARAMETER_H

#include <iostream>
#include <fstream>
#include <string>

class parameter
{
private:
    int size;
    double *S;
    double *A, *B, *C, *D;
public:
    parameter(int size);
    parameter(int size, double* s, double *a, double *b, double *c, double *d);
    ~parameter();
    void reconstruct(int size, double* s, double *a, double *b, double *c, double *d);
    int getSize();
    void getParam(double *s, double *a, double *b, double *c, double *d);
    void paramWriter(std::string path);
};



#endif