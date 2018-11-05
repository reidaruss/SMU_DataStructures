#ifndef INPUT_H
#define INPUT_H
#include "adjacencylist.h"
#include "stack.h"

class Input
{
public:
    Input(char* argv[]);
    void requestedDistanceInput(char* argv[],AdjacencyList<string> &adj);
    void sepOfTwo(AdjacencyList<string> adj);
    void requestedDistance(AdjacencyList<string> &adj, int* numDist, string temp[], int &counter);
};

#endif // INPUT_H
