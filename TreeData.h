#ifndef TREE_DATA_H_INCLUDED
#define TREE_DATA_H_INCLUDED
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<functional>
#include"matrix.h"
struct discrete_data{
    vector<vector<string>> db;//离散数据的普遍形式，默认最后一列是类标
    map<string,size_t> labelId;
    size_t getId(string&s){
        if(labelId.count(s)!=0)
            return labelId[s];
    }
    void build_map(); //生成类标向索引的映射
};
struct tree_data:discrete_data{

    vector<string> feature_name;
    string label_name;

    map<string,size_t> feature_id;
    size_t label_id;

    tree_data(ifstream&);//从输入数据构建
    string get_label(size_t i){return db[i][label_id];}
};

#endif // TREE_DATA_H_INCLUDED
