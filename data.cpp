#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include<string>
#include"data.h"

using namespace std;
data::data(ifstream&f,int nums):X(new vector<matrix>),Y(new vector<string>){
    string line;
    while (getline(f,line)){
        istringstream s(line);
        double temp;
        matrix sample;
        string label;
        sample.row=nums;
        sample.col=1;
        for(int i=0;i<nums;i++){
            s>>temp;
            sample.m.push_back(temp);
        }
        s>>label;
        X->push_back(sample);
        Y->push_back(label);
    }
}
data data::sub(function<bool(size_t)> f){
    data d;
    for(size_t i=0;i<X->size();i++)
    {
        if(f(i))
        {
            d.X->push_back(*(X->begin()+i));
            d.Y->push_back(*(Y->begin()+i));
        }

    }
    return d;
}
