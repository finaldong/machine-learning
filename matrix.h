#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<vector>
#include<stdexcept>

using namespace std;
struct matrix
{
    int col,row;//行数和列数
    vector<double>m;//矩阵是按照行拼接成连续内存上的一段数据
    double modulus()const{
        double res=0;
        for(auto& c:m)
            res+=c*c;
        return res;
    }
    //构造函数
    matrix()=default;
    matrix(double x):col(1),row(1){//允许从一个数值变量到矩阵的隐式类型转换
        m.push_back(x);
    }
    matrix(int a,int b,initializer_list<double>l):col(a),row(b){
        for(auto c:l)
            m.push_back(c);
    }
    matrix(int a,int b,double v=0.0):col(a),row(b){
        for(int i=0;i<a*b;i++)
                m.push_back(v);
    }
    double at(int a,int b)const{
        if(a>col||b>row)
            throw runtime_error("超出索引范围");
        return m[a*row+b];
    }
    matrix transpose()//直接创建一个新的矩阵返回一个拷贝
    {
        matrix res;
        res.col=row;
        res.row=col;
        for(int i=0;i<col;i++)
            for(int j=0;j<row;j++)
                res.m.push_back(m[j*col+i]);
        return res;
    }
    //复合运算符
    matrix& operator+=(const matrix&);
    matrix& operator-=(const matrix&);
    matrix& operator*=(const double&);
};
ostream& operator<<(ostream&,const matrix&);
matrix operator+(const matrix&,const matrix&);
double operator+(const double&,const matrix&);
double operator+(const matrix&,const double&);

matrix operator-(const matrix&,const matrix&);
double operator+(const double&,const matrix&);
double operator+(const matrix&,const double&);

matrix operator*(const matrix&,const matrix&);
matrix operator*(const matrix&,const double&);
matrix operator*(const double&,const matrix&);

#endif // MATRIX_H_INCLUDED
