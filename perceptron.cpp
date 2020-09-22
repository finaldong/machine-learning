#include<random>
#include<ctime>
#include"perceptron.h"
perceptron::perceptron(const data& d):X(d.X),Y(d.Y),w((*X)[0].row,1){
    int l=Y->size();
    int number[2]={1,-1};
    int k=0;
    default_random_engine e(time(0));
    uniform_real_distribution<double> u(0,1);
    for(auto&c:w.m)
        c=u(e);
    for(int i=0;i<l;i++)
    {
        if(k>1)
            break;
        string s=*(Y->begin()+i);
        if(label_map.count(s)==0)
            {
                label[k]=s;
                label_map[s]=number[k++];
            }
    }
};
int perceptron::sign(const matrix&a){
    return (a*w+b)>0?1:-1;
}
void perceptron::train(){
        int l=X->size(),cnt=0,times_wrong=1;
        while(cnt<max_iterations&&times_wrong>0)
        {
            times_wrong=0;
            for(int i=0;i<l;i++){
            //计算更新式
            cnt++;
            int y=label_map[*(Y->begin()+i)];
            int res=sign(*(X->begin()+i))*y;
            if(res<=0)
              {
                  times_wrong++;
                  w+=(*(X->begin()+i)).transpose()*(learn_rate*y);
                  b+=learn_rate*y;
              }
            //更新
            }
        }
    };
string perceptron::predict(const matrix &a){
    int res=sign(a);
    if(res==1)
        return label[0];
    else
        return label[1];
}
double perceptron::accuracy(){
    double ans=0;
    double total=X->size();
    for(int i=0;i<total;i++)
    {
        if(predict(*(X->begin()+i))==*(Y->begin()+i))
            ans+=1;
    }
    return ans/total;
}
