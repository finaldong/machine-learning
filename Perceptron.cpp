#include<random>
#include<ctime>
#include"Perceptron.h"
int Perceptron::sign(const matrix&a){
    return (a*w+b)>0?1:-1;
}
void Perceptron::train(){
        vector<matrix> &X=DataPointer->X;
        vector<string> &Y=DataPointer->Y;
        int l=X.size(),cnt=0,wrongTimes=1;
        while(cnt<maxIterations&&wrongTimes>0)
        {
            wrongTimes=0;
            for(int i=0;i<l;i++)
            {
                cnt++;
                int y=sign(X[i]);
                int ydata=DataPointer->getLabelId(Y[i]);
                if(ydata==0)
                    ydata=1;
                else
                    ydata=-1;
                if(y*ydata<=0)
                {
                  ++wrongTimes;
                  w+=learnRate*ydata*(X[i].transpose());
                  b+=learnRate*ydata;
                }
            }
        }
    };
string Perceptron::predict(const matrix &a){
    int res=sign(a);
    if(res==1)
        return DataPointer->getLabelName(0);
    else
        return DataPointer->getLabelName(1);
}

