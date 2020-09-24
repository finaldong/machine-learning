#ifndef DECISION_TREE_H_INCLUDED
#define DECISION_TREE_H_INCLUDED
#include<set>
#include<map>
#include"TreeData.h"
struct decision_tree{
    shared_ptr<tree_data> _data;

    double tree_entropy;
    size_t _beg,_end;//��������������ʼ�����±�����ʾ
    string feature;//ѡ�������
    string feature_value;//����ȡֵ
    string label;//�������ֵ
    vector<shared_ptr<decision_tree>> child_list;//�����б�

    decision_tree(ifstream&is):_data(new tree_data(is)),_beg(0),_end(_data->db.size()){}
    decision_tree(const decision_tree&dt,size_t a,size_t b):_data(dt._data),_beg(a),_end(b){}
    pair<double,bool> entropy();
    double conditional_entropy(const string&);
    void build(const set<string>&);
    string predict(const vector<string>&,shared_ptr<decision_tree>);
    void printf_tree();

};


#endif // DECISION_TREE_H_INCLUDED
