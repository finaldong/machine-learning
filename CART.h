#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED
#include "Data.h"
struct basicCART{
    size_t elementIndex;//选择的划分元素是哪个
    double value;
    int n;//离散化划分的精度
    pair<size_t,double> twodimSearch();
}
struct CART:basicCART{
    shared_ptr<RegressData> DataPointer;
    size_t _beg,_end;
    int h;//树的深度
    shared_ptr<CART> lchild,rchild;
    CART(const RegressData&rd):DataPointer(new RegressData(rd)){}//对于使用数据序列重排技巧的算法,实行拷贝传入
    CART(const CART&father,size_t a,size_t b):DataPointer(father.DataPointer),_beg(a)._end(b){}
    void build();
    double predict();
};

#endif // CART_H_INCLUDED
