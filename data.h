#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include<iostream>
#include<map>
#include"matrix.h"
struct Data{
    vector<matrix> X;
    vector<string> Y;
    map<string,size_t> labelId;
    vector<string> labelName;
    size_t getLabelId(string&s){return labelId[s];}
    string getLabelName(size_t i){return labelName[i];}
    Data(ifstream&);
};
struct RegressData{
    vector<matrix> X;
    vector<double> Y;
};

#endif // DATA_H_INCLUDED
