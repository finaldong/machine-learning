#ifndef TREE_DATA_H_INCLUDED
#define TREE_DATA_H_INCLUDED
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<functional>
#include"matrix.h"
struct discrete_data{
    vector<vector<string>> db;//��ɢ���ݵ��ձ���ʽ��Ĭ�����һ�������
    map<string,size_t> labelId;
    size_t getId(string&s){
        if(labelId.count(s)!=0)
            return labelId[s];
    }
    void build_map(); //���������������ӳ��
};
struct tree_data:discrete_data{

    vector<string> feature_name;
    string label_name;

    map<string,size_t> feature_id;
    size_t label_id;

    tree_data(ifstream&);//���������ݹ���
    string get_label(size_t i){return db[i][label_id];}
};

#endif // TREE_DATA_H_INCLUDED
