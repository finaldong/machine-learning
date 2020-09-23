#include<algorithm>
#include<iostream>
#include"decision_tree.h"
void decision_tree::build(const set<string>& A){
    auto res=entropy();//计算该节点属于的类别以及条件熵
    tree_entropy=res.first;
    if(A.size()==0)
        return;
    if(res.second)
        return;
    string best_feature;
    double best_gain=0;
    for(auto &feature: A)
    {
        double ce=tree_entropy-conditional_entropy(feature);
        if(ce>best_gain)
        {
            best_gain=ce;
            best_feature=feature;
        }
    }
    int id=_data->feature_id[best_feature];
    set<string> B(A);
    B.erase(best_feature);
    if(feature.size()==0)
        feature=best_feature;
    sort(_data->db.begin()+_beg,_data->db.begin()+_end,\
         [id](const vector<string>&a,const vector<string>&b){return a[id]<b[id];});
    size_t start=_beg;
    for(size_t i=_beg;i<_end;i++)
    {
        if((i+1==_end)||(i+1!=_end&&_data->db[i][id]!=_data->db[i+1][id]))
        {
            child_list.push_back(shared_ptr<decision_tree>(new decision_tree(*this,start,i+1)));
            start=i+1;
            auto &dt=*(child_list.end()-1);
            dt->feature=best_feature;
            dt->feature_value=_data->db[i][id];
            dt->build(B);
        }
    }
}

pair<double,bool> decision_tree::entropy(){
    map<string,int> temp;//构建类标到数字的映射
    double total=_end-_beg;//总数量
    double ans=0;
    size_t id=_data->label_id;
    for(size_t i=_beg;i<_end;i++)//子空间的基础扫描
    {
        auto res=temp.insert({_data->db[i][id],1});
        if(!res.second)
            ++res.first->second;
    }
    string max_nums;
    int nums=0;
    for(auto &c:temp)
    {
        double p=c.second/total;
        ans-=p*log(p);
        if(c.second>nums)
        {
            nums=c.second;
            max_nums=c.first;
        }
    }
    label=max_nums;
    bool flag=false;
    if(temp.size()==1)
        flag=true;
    return {ans,flag};
}
////
double decision_tree::conditional_entropy(const string &s){
    map<string,int> feature_map;
    map<string,int> label_map;
    int k1=0,k2=0;
    double total=_end-_beg;
    int id=_data->feature_id[s];//当前特征在数据集的编号
    vector<vector<int>> cal;//计算矩阵
    for(size_t i=_beg;i<_end;i++)
    {

        auto r1=feature_map.insert({_data->db[i][id],k1});
        auto r2=label_map.insert({_data->get_label(i),k2});
        if(r2.second)
            k2++;
        if(r1.second)
        {
            k1++;
            cal.push_back( vector<int>(k2,0));
        }
        for(size_t j=cal[r1.first->second].size();j<k2;j++)
            cal[r1.first->second].push_back(0);
        cal[r1.first->second][r2.first->second]+=1;
    }
    double ans=0;
    for(size_t i=0;i<k1;i++)
    {
        double temp=0,cnt=0;
        for(size_t j=0;j<cal[i].size();j++)
            cnt+=cal[i][j];
        for(size_t j=0;j<cal[i].size();j++)
        {
            if(cal[i][j]!=0)
            {
                double p=cal[i][j]/cnt;
                temp-=p*log(p);
            }
        }
        ans+=cnt*temp;
    }
    ans/=total;
    return ans;
}
string decision_tree::predict(const vector<string>& in,shared_ptr<decision_tree> root){
    size_t id=_data->feature_id[feature];
    shared_ptr<decision_tree> temp(root);
    while(temp->child_list.size()!=0)
    {
        for(int i=0;i<temp->child_list.size();i++)

            if(in[id]==temp->child_list[i]->feature_value)
                {temp=temp->child_list[i];break;}
    }
    return temp->label;
}

