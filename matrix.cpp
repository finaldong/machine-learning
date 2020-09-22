#include<iostream>
#include<vector>
#include<stdexcept>
#include"matrix.h"
using namespace std;
ostream& operator<<(ostream&os,const matrix&a){
    for(int i=0;i<a.col;i++)
    {
        for(int j=0;j<a.row;j++)
            os<<a.at(i,j)<<' ';
        os<<endl;
    }
    return os;
}
matrix& matrix::operator+=(const matrix&a){
        if(col!=a.col||row!=a.row)
            throw runtime_error("矩阵加法维度不匹配");
        for(int i=0;i<col*row;i++)
            m[i]+=a.m[i];
        return *this;
}
matrix& matrix::operator-=(const matrix&a){
        if(col!=a.col||row!=a.row)
            throw runtime_error("矩阵减法维度不匹配");
        for(int i=0;i<col*row;i++)
            m[i]-=a.m[i];
        return *this;
}
matrix& matrix::operator*=(const double&a){
        for(int i=0;i<col*row;i++)
            m[i]*=a;
        return *this;
}
matrix operator+(const matrix&a,const matrix&b){
    matrix res=a;
    res+=b;
    return res;
}
double operator+(const double&a,const matrix&b){
    if(b.col!=1||b.row!=1)
        throw runtime_error("矩阵无法和一个数运算");
    return a+b.m[0];
}
double operator+(const matrix&a,const double&b){
    return b+a;
}

matrix operator-(const matrix&a,const matrix&b){
    matrix res=a;
    res-=b;
    return res;
}
double operator-(const double&a,const matrix&b){
    if(b.col!=1||b.row!=1)
        throw runtime_error("矩阵无法和一个数运算");
    return a-b.m[0];
}
double operator-(const matrix&a,const double&b){
    return b-a;
}

matrix operator*(const matrix&a,const matrix&b){
    if(a.row!=b.col)
        throw runtime_error("矩阵乘法维度不匹配");
    matrix res;
    res.col=a.col;
    res.row=b.row;
    for(int i=0;i<a.col;i++)
        for(int j=0;j<b.row;j++)
        {
            double ans=0;
            for(int k=0;k<a.row;k++)
            {
                ans+=a.at(i,k)*b.at(k,j);
            }
           res.m.push_back(ans);
        }
    return res;
}

matrix operator*(const matrix&a,const double&b){
    matrix res=a;
    res*=b;
    return res;
}
matrix operator*(const double&a,const matrix&b)
{
    return b*a;
}

