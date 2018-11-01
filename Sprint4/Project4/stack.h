#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

using namespace std;


class Stack
{
private:
    LinkedList<string> data;
    int size; //SAVING PATH: distance will always be size-1, implement a function to check if the new path is smaller, if it is change the length data member to new length else leave it (finding degrees of sep)
public:
    Stack();


    string& operator[](int i);
    void push(string val);
    string pop();
    bool isEmpty();
    bool contains(string val);
    string peek();


};

#endif // STACK_H
