#include<math.h>
#include"LogsticRegress.h"
double LogsticRegress::conditionalProbability(const matrix&a){
    double temp=exp(a*w+b);
    return temp/(1+temp);
}
void LogsticRegress::MaxLikelihood(){
    vector<matrix> &X=DataPointer->X;
    vector<string> &Y=DataPointer->Y;
    int cnt=0;
    while(cnt<=MaxIterations)
    {
        cnt++;
        for(size_t i=0;i<X.size();i++){
            double p=conditionalProbability(X[i]);
            double learnCoeff=(DataPointer->getLabelId(Y[i])-p)*learnRate;
            w+=learnCoeff*X[i].transpose();
        }
    }
}
