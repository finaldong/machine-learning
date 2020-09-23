#ifndef TREE_DATA_H_INCLUDED
#define TREE_DATA_H_INCLUDED
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<functional>
#include"matrix.h"
struct tree_data{
    vector<vector<string>> db;
    vector<string> feature_name;
    string label_name;

    map<string,size_t> feature_id;
    size_t label_id;

    tree_data(ifstream&);//从输入数据构建
    string get_label(size_t i){return db[i][label_id];}
};

#endif // TREE_DATA_H_INCLUDED
