#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "linkedlist.h"


class AdjacencyList
{
private:
    LinkedList<LinkedList<string>> data;
public:

    AdjacencyList();
    void insert(string find, string val);
    LinkedList<string> findWhereFirstIs(string val);
    LinkedList<string> stepIterator(string val);

};

#endif // ADJACENCYLIST_H
