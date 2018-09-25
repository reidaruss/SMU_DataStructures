#ifndef OUTPUT_H
#define OUTPUT_H
#include "dsvector.h"
#include "index.h"


class Output
{
public:
    Output();

    void writeOut(char* argv[]);
    void sortWords(const DSVector<Index>& v);
};

#endif // OUTPUT_H
