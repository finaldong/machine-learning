#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
#include<math.h>
#include"TreeData.h"
using namespace std;
void DiscreteData::buildMap(){
    size_t cnt=0;
    for(auto &c:db)
    {
        auto &d=*(c.end()-1);
        if(labelId.count(d)==0)
            labelId[d]=cnt++;
    }
}
TreeData::TreeData(ifstream&file){
    string line;
    //默认第一行是特征的名字和类别的名字
    getline(file,line);
    istringstream lineStream(line);
    string temp;
    int cnt=0;
    while(lineStream>>temp)
    {
        featureName.push_back(temp);
        featureIndex[temp]=cnt++;
    }
    labelName=*(featureName.end()-1);
    featureName.pop_back();
    labelIndex=featureIndex[labelName];
    featureIndex.erase(labelName);
    //开始读入数据
    while (getline(file,line)){
        istringstream dataLineStream(line);
        vector<string> sample;
        while(dataLineStream>>temp){
            sample.push_back(temp);
        }
        db.push_back(sample);
    }
}

