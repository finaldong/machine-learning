#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include<iostream>
#include<memory>
#include"matrix.h"
#include<functional>
struct data{
    shared_ptr<vector<matrix>> X;
    shared_ptr<vector<string>> Y;
    data():X(new vector<matrix>),Y(new vector<string>){}
    data(ifstream&,int);
    data sub(function<bool(size_t)>);
};

#endif // DATA_H_INCLUDED
