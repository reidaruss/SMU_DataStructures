#ifndef OUTPUT_H
#define OUTPUT_H
#include "adjacencylist.h"

class Output
{
public:
    Output();

    void writeOut(char* argv[], AdjacencyList<string> adj, int* distance, int numDist, string *inputT);
};

#endif // OUTPUT_H
