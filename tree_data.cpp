#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
#include<math.h>
#include"tree_data.h"
using namespace std;
void discrete_data::build_map(){
    size_t cnt=0;
    for(auto &c:db)
    {
        auto &d=*(c.end()-1);
        if(labelId.count(d)==0)
            labelId[d]=cnt++;
    }
}
tree_data::tree_data(ifstream&is){
    string line;
    int build_flag=1;
    while (getline(is,line)){
        istringstream s(line);
        string attributes;
        vector<string> sample;
        int cnt=0;
        while(s>>attributes){
            if(build_flag==1)
                {
                    feature_name.push_back(attributes);
                    feature_id[attributes]=cnt++;
                }
            else
                sample.push_back(attributes);
        }
        if(build_flag==0)
            db.push_back(sample);
        build_flag=0;
    }
    label_name=*(feature_name.end()-1);
    feature_name.pop_back();

    label_id=feature_id[label_name];
    feature_id.erase(label_name);
}

