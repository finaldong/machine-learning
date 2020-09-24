#ifndef DECISION_TREE_H_INCLUDED
#define DECISION_TREE_H_INCLUDED
#include<set>
#include<map>
#include"TreeData.h"
struct DecisionTree{
    shared_ptr<TreeData> DataPointer;

    double treeEntropy;
    size_t _beg,_end;//��������������ʼ�����±�����ʾ
    string featureSelect;//ѡ�������
    string featureValue;//����ȡֵ
    string labelValue;//�������ֵ
    vector<shared_ptr<DecisionTree>> childList;//�����б�
    DecisionTree(const TreeData&p):DataPointer(new TreeData(p)),_beg(0),_end(p->db.size()){}//���������ع���֧��ֱ�Ӵ���
    DecisionTree(const DecisionTree&father,size_t a,size_t b):DataPointer(father.DataPointer),_beg(a),_end(b){}
    pair<double,bool> calEntropyAndisOneLabel();//����ڵ��ز����������������,�ڶ�������ֵ˵���Ƿ�ֻ��һ��
    double conditionalEntropy(const string&);
    void build(const set<string>&);
    string predict(const vector<string>&);
};


#endif // DECISION_TREE_H_INCLUDED
