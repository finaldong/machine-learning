#include<algorithm>
#include<iostream>
#include"DecisionTree.h"
void DecisionTree::build(const set<string>& A){
    auto res=calEntropyAndisOneLabel();//计算该节点属于的类别以及条件熵
    treeEntropy=res.first;
    if(A.size()==0)
        return;
    if(res.second)
        return;
    string bestFeature;
    double bestGain=0;
    for(auto &feature: A)
    {
        double gain=treeEntropy-conditionalEntropy(feature);
        if(gain>bestGain)
        {
            bestGain=gain;
            bestFeature=feature;
        }
    }
    int id=DataPointer->featureIndex[bestFeature];
    set<string> B(A);
    B.erase(bestFeature);

    if(featureSelect.size()==0)
        featureSelect=bestFeature;

    sort(DataPointer->db.begin()+_beg,DataPointer->db.begin()+_end,\
         [id](const vector<string>&a,const vector<string>&b){return a[id]<b[id];});
    size_t start=_beg;
    for(size_t i=_beg;i<_end;i++)
    {
        if((i+1==_end)||(i+1!=_end&&DataPointer->db[i][id]!=DataPointer->db[i+1][id]))
        {
            childList.push_back(shared_ptr<DecisionTree>(new DecisionTree(*this,start,i+1)));
            start=i+1;
            auto &dt=*(childList.end()-1);
            dt->featureSelect=bestFeature;
            dt->featureValue=DataPointer->db[i][id];
            dt->build(B);
        }
    }
}

pair<double,bool> DecisionTree::calEntropyAndisOneLabel(){
    map<string,int> LableNums;//每类有多少个
    double total=_end-_beg;//总数量
    for(size_t i=_beg;i<_end;i++)//扫描一遍看看每个类别取值有多少
    {
        auto res=LableNums.insert({DataPointer->getLabel(i),1});
        if(!res.second)
            ++res.first->second;
    }
    string maxNumLabel;
    int nums=0;
    double entropy=0;
    for(auto &element:LableNums)
    {
        double p=element.second/total;
        entropy-=p*log(p);
        if(element.second>nums)
        {
            nums=element.second;
            maxNumLabel=element.first;
        }
    }
    labelValue=maxNumLabel;
    if(LableNums.size()==1)
        return{entropy,true};
    else
        return{entropy,false};
}
////
double DecisionTree::conditionalEntropy(const string &s){
    map<string,int> featureNums;
    map<string,int> labelNums;
    int k1=0,k2=0;
    double total=_end-_beg;
    size_t id=DataPointer->featureIndex[s];//当前特征在数据集的编号
    size_t idLabel=DataPointer->labelIndex;
    vector<vector<int>> table;//动态构建计算矩阵
    vector<vector<string>> &D=DataPointer->db;
    for(size_t i=_beg;i<_end;i++)
    {
        auto r1=featureNums.insert({D[i][id],k1});
        auto r2=labelNums.insert({D[i][idLabel],k2});
        if(r2.second)
            k2++;
        if(r1.second)
        {
            k1++;
            table.push_back(vector<int>(k2,0));
        }
        for(size_t j=table[r1.first->second].size();j<k2;j++)
            table[r1.first->second].push_back(0);

        table[r1.first->second][r2.first->second]+=1;
    }
    double cEntropy=0;
    for(size_t i=0;i<k1;i++)
    {
        double temp=0,cnt=0;
        for(size_t j=0;j<table[i].size();j++)
            cnt+=table[i][j];
        for(size_t j=0;j<table[i].size();j++)
        {
            if(table[i][j]!=0)
            {
                double p=table[i][j]/cnt;
                temp-=p*log(p);
            }
        }
        cEntropy+=cnt*temp;
    }
    cEntropy/=total;
    return cEntropy;
}

