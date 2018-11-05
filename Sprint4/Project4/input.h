#ifndef INPUT_H
#define INPUT_H
#include "adjacencylist.h"
#include "stack.h"

class Input
{
public:
    Input(char* argv[]);    //initial file in
    void requestedDistanceInput(char* argv[],AdjacencyList<string> &adj);   //input second file
    void sepOfTwo(AdjacencyList<string> adj);   //find the number of total connections within 2 steps of a person
    void requestedDistance(AdjacencyList<string> &adj, int* numDist, string temp[], int &counter); //find degrees of seperation between individuals from input file 2
};

#endif // INPUT_H
