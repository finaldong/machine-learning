#ifndef TREE_DATA_H_INCLUDED
#define TREE_DATA_H_INCLUDED
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<functional>
#include"matrix.h"
struct DiscreteData{
    vector<vector<string>> db;//��ɢ���ݿ�,Ĭ�����һ�д�������ȡֵ
    map<string,size_t> labelId;//�����ӳ�������id
    size_t getId(string&s){return labelId[s];}
    void buildMap();
};
struct TreeData:DiscreteData{

    vector<string> featureName;
    map<string,size_t> featureIndex;
    string labelName;
    size_t labelIndex;
    TreeData(ifstream&);//���������ݹ���
    string getLabel(size_t i){return db[i][labelIndex];}
};

#endif // TREE_DATA_H_INCLUDED
