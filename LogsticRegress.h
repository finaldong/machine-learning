#ifndef LOGSTIC_REGRESS_H_INCLUDED
#define LOGSTIC_REGRESS_H_INCLUDED
#include<memory>
#include "Data.h"
struct LogsticRegress{
    shared_ptr<Data> DataPointer;
    matrix w;
    double b;
    LogsticRegress(shared_ptr<Data> p):DataPointer(p),w(p->X[0].row,1),b(0){}
    void MaxLikelihood();
};
#endif // LOGSTIC_REGRESS_H_INCLUDED
