#ifndef LOGSTIC_REGRESS_H_INCLUDED
#define LOGSTIC_REGRESS_H_INCLUDED
#include "data.h"
struct LogsticRegress{
    shared_ptr<data>;
    matrix w;
    double b;
    void MaxLikelihood();
};
#endif // LOGSTIC_REGRESS_H_INCLUDED
