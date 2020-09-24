#ifndef DECISION_TREE_H_INCLUDED
#define DECISION_TREE_H_INCLUDED
#include<set>
#include<map>
#include"TreeData.h"
struct decision_tree{
    shared_ptr<tree_data> _data;

    double tree_entropy;
    size_t _beg,_end;//子树的数据用起始结束下标来表示
    string feature;//选择的特征
    string feature_value;//特征取值
    string label;//代表的类值
    vector<shared_ptr<decision_tree>> child_list;//子树列表

    decision_tree(ifstream&is):_data(new tree_data(is)),_beg(0),_end(_data->db.size()){}
    decision_tree(const decision_tree&dt,size_t a,size_t b):_data(dt._data),_beg(a),_end(b){}
    pair<double,bool> entropy();
    double conditional_entropy(const string&);
    void build(const set<string>&);
    string predict(const vector<string>&,shared_ptr<decision_tree>);
    void printf_tree();

};


#endif // DECISION_TREE_H_INCLUDED
