#ifndef OUTPUT_H
#define OUTPUT_H
#include "dsvector.h"
#include "index.h"


class Output
{
public:
    Output();

    void writeOut(char* argv[], DSVector<Index> v);
    DSVector<Index> sortWords(DSVector<Index> &v);
};

#endif // OUTPUT_H
