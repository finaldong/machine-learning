#ifndef NAIVEBAYES_H_INCLUDED
#define NAIVEBAYES_H_INCLUDED
#include"TreeData.h"
#include<memory>
using namespace std;
struct NaiveBayes{
    shared_ptr<discrete_data> dataPoint;
    vector<map<string,double>> theta;//每个随机变量的参数
    vector<double>priori;//先验分布
    void learn();
    string predict();
};

#endif // NAIVEBAYES_H_INCLUDED
