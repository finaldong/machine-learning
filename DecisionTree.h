#ifndef DECISION_TREE_H_INCLUDED
#define DECISION_TREE_H_INCLUDED
#include<set>
#include<map>
#include"TreeData.h"
struct DecisionTree{
    shared_ptr<TreeData> DataPointer;

    double treeEntropy;
    size_t _beg,_end;//子树的数据用起始结束下标来表示
    string featureSelect;//选择的特征
    string featureValue;//特征取值
    string labelValue;//代表的类值
    vector<shared_ptr<DecisionTree>> childList;//子树列表
    DecisionTree(const TreeData&p):DataPointer(new TreeData(p)),_beg(0),_end(p->db.size()){}//由于序列重构不支持直接传入
    DecisionTree(const DecisionTree&father,size_t a,size_t b):DataPointer(father.DataPointer),_beg(a),_end(b){}
    pair<double,bool> calEntropyAndisOneLabel();//计算节点熵并标记类别数最大的类别,第二个返回值说明是否只有一类
    double conditionalEntropy(const string&);
    void build(const set<string>&);
    string predict(const vector<string>&);
};


#endif // DECISION_TREE_H_INCLUDED
