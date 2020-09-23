#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include<iostream>
#include<memory>
#include"matrix.h"
#include<functional>
struct Data{
    vector<matrix> X;
    vector<string> Y;
    Data(ifstream&);
};

#endif // DATA_H_INCLUDED
