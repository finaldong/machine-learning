#include"CART.h"
pair<size_t,two>
void CART::build(){
    //二维搜索
    vector<matrix> &X=DataPointer->X;
    vector<double> &Y=DataPointer->Y;
    size_t FeatureNums=X[0].m.size();
    size_t bestFeature=0;
    double bestVar=10000;
    for(size_t i=0;i<FeatureNums;i++){
        //计算该特征的最大最小值
        double xMax=X[_beg].m[i];
        double xMin=X[_beg].m[i];
        for(size_t j=_beg;j<_end;j++)
        {
            if(X[j].m[i]>xMax)
                xMax=X[j].m[i];
            if(X[j].m[i]<xMin)
                xMin=X[j].m[i];
        }
        double bestV;
        double bestG=10000;
        for(int j=1;j<n;j++)
        {
            double G,G1=0,G2=0,M1=0,M2=0,C1=0,C2=0;
            double v=xMin+j*(xMax-xMin)/n;//将j映射到某个数据点
            for(size_t k=_beg;k<_end;k++)
            {
                if(X[k].m[i]>v)
                {
                    G1+=X[k].m[i]*X[k].m[i];
                    M1+=X[k].m[i];
                    C1++;
                }
                else{
                    G2+=X[k].m[i]*X[k].m[i];
                    M2+=X[k].m[i];
                    C2++;
                }
            }
            M1/=C1;
            M2/=C2;
            G1-=M1*M1;
            G2-=M2*M2;
            G=G1+G2;
            if(G<bestG)
            {
                bestG=G;
                bestV=v;
            }
        }
        if(bestG<bestVar)
        {
            bestVar=bestG;
            bestFeature=i;
            value=bestV;
        }
    }
    size_t i=_beg,j=_end-1,k=_beg;
    while(i<j)
    {
        while(X[i].m[bestFeature]<value)
        {
            i++;
        }
        swap(X[i],X[k]);
        while(X[j].m[bestFeature]>value)
        {
            j--;
        }
        swap(X[j],X[k]);
    }
    lchild(*this,_beg,i);
    rchild(*this,i,_end);
    lchild.build();
    rchild.build();
}
