#ifndef TREE_DATA_H_INCLUDED
#define TREE_DATA_H_INCLUDED
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<functional>
#include"matrix.h"
struct DiscreteData{
    vector<vector<string>> db;//离散数据块,默认最后一行代表类别的取值
    map<string,size_t> labelId;//将类别映射成数字id
    size_t getId(string&s){return labelId[s];}
    void buildMap();
};
struct TreeData:DiscreteData{

    vector<string> featureName;
    map<string,size_t> featureIndex;
    string labelName;
    size_t labelIndex;
    TreeData(ifstream&);//从输入数据构建
    string getLabel(size_t i){return db[i][labelIndex];}
};

#endif // TREE_DATA_H_INCLUDED
