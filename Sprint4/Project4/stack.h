#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

using namespace std;


class Stack
{
private:
    LinkedList<string> data;
    int size;
public:
    Stack();

    template <typename T>
    LinkedList<T>& operator[](int i);
    void push(string val);
    string pop();
    bool isEmpty();
    bool contains(string val);
    string peek();

};

#endif // STACK_H
