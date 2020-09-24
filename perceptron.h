#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED
#include<string>
#include<map>
#include"Data.h"
#include<memory>
struct Perceptron{
    shared_ptr<Data> DataPointer;
    matrix w;
    double b=0;
    double learnRate=0.05;
    int maxIterations=10000;
    Perceptron(shared_ptr<Data> p):DataPointer(p),w(p->X[0].row,1){};//�Ƽ�ʹ��ָ�봫�빲������
    Perceptron(const Data&);//���Ƽ�������������
    int sign(const matrix&);
    void train();
    string predict(const matrix&);
};
#endif // PERCEPTRON_H_INCLUDED

