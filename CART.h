#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED
#include "Data.h"
struct basicCART{
    size_t elementIndex;//ѡ��Ļ���Ԫ�����ĸ�
    double value;
    int n;//��ɢ�����ֵľ���
    pair<size_t,double> twodimSearch();
}
struct CART:basicCART{
    shared_ptr<RegressData> DataPointer;
    size_t _beg,_end;
    int h;//�������
    shared_ptr<CART> lchild,rchild;
    CART(const RegressData&rd):DataPointer(new RegressData(rd)){}//����ʹ�������������ż��ɵ��㷨,ʵ�п�������
    CART(const CART&father,size_t a,size_t b):DataPointer(father.DataPointer),_beg(a)._end(b){}
    void build();
    double predict();
};

#endif // CART_H_INCLUDED
