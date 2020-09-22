#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<vector>
#include<stdexcept>

using namespace std;
struct matrix
{
    int col,row;//����������
    vector<double>m;//�����ǰ�����ƴ�ӳ������ڴ��ϵ�һ������
    double modulus()const{
        double res=0;
        for(auto& c:m)
            res+=c*c;
        return res;
    }
    //���캯��
    matrix()=default;
    matrix(double x):col(1),row(1){//�����һ����ֵ�������������ʽ����ת��
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
            throw runtime_error("����������Χ");
        return m[a*row+b];
    }
    matrix transpose()//ֱ�Ӵ���һ���µľ��󷵻�һ������
    {
        matrix res;
        res.col=row;
        res.row=col;
        for(int i=0;i<col;i++)
            for(int j=0;j<row;j++)
                res.m.push_back(m[j*col+i]);
        return res;
    }
    //���������
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
