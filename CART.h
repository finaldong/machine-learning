#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED
struct CART{
    size_t elementIndex;
    double value;
    int h;
    shared_ptr<CART> lchild,rchild;
    void build();
};

#endif // CART_H_INCLUDED
