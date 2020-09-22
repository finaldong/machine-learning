#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED
#include<string>
#include<map>
#include"data.h"
struct perceptron{
    shared_ptr<vector<matrix>> X;
    shared_ptr<vector<string>> Y;
    string label[2];
    map<string,int> label_map;
    matrix w;
    double b=0;
    double learn_rate=0.05;
    int max_iterations=10000;
    perceptron(const data&);
    virtual ~perceptron() = default;
    virtual int sign(const matrix&);
    void train();
    string predict(const matrix&);
    double accuracy();
};

#endif // PERCEPTRON_H_INCLUDED
