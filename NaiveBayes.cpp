#include"NaiveBayes.h"
void NaiveBayes::learn(){
    int labelNums=dataPoint->labelId.size();
    for(int i=0;i<labelNums;i++){//空间预分配
        priori.push_back(0.0);
        theta.push_back(map<string,double>());
    }
    double sampleNums=0;
    for(auto&c:dataPoint->db)
    {
        for(auto d=c.begin();d<c.end()-1;d++)
        {
            ++sampleNums;
            string label=*(c.end()-1);
            priori[dataPoint->getId(*d)]+=1.0;
            auto res=theta[dataPoint->getId(*d)].insert({*d,1.0});
            if(!res.second)
                (res.first->second)+=1.0;
        }
    }
    for(size_t i=0;i<theta.size();i++)
    {
        for(auto &d:theta[i])
        {
            d.second/=priori[i];
        }
        priori[i]/=sampleNums;
    }
}

