#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "linkedlist.h"

template<class T>
class AdjacencyList
{
private:
    LinkedList<LinkedList<T>> data;
    int size;
public:

    AdjacencyList();
    void insert(T find, T val);
    LinkedList<T> findWhereFirstIs(string val);
    T stepIterator(string val);
    string getAt(int i, int j);
    int getSize();
    void resetIters();
    int getInnerSize(int i);
    string getIter(string val);
};


template <typename T>
AdjacencyList<T>::AdjacencyList()
{
    size = 0;
}

template <typename T>
void AdjacencyList<T>::insert(T find, T val)
{
    bool added1 = false;
    bool added2 = false;
    for(int i = 0; i < size; i ++)
    {
        if(data[i][0] == find)
        {
            data[i].addBack(val);
            added1 = true;
            break;
        }
    }

    if(added1 == false)
    {
        LinkedList<T> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
        size++;
    }

    for(int i = 0; i < size; i ++)
    {
        if(data[i][0] == val)
        {
            data[i].addBack(find);
            added2 = true;
            break;
        }

    }
    if(added2 == false)
    {
        LinkedList<T> temp;
        temp.addBack(val);
        temp.addBack(find);
        data.addBack(temp);
        size++;
    }

}
template <typename T>
string AdjacencyList<T>::getAt(int i, int j)
{
    return data[i][j];
}


template <typename T>
LinkedList<T> AdjacencyList<T>::findWhereFirstIs(string val)    //return type was LinkedList<T> (return data[i])
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i];
    }
}

template <typename T>
int AdjacencyList<T>::getSize()
{
    return size;
}


template <typename T>
void AdjacencyList<T>::resetIters()
{
    for(int i = 0; i < size; i ++)
    {
        data[i].resetIterator();
    }
}

template <typename T>
string AdjacencyList<T>::getIter(string val)
{
    for(int i = 0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i].getCurr();
    }


}


template <typename T>
T AdjacencyList<T>::stepIterator(string val)      //return type was LInkedList<string> (return L.getNext();)
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
        {
            return data[i].getNext();//sets curr = curr->next and returns curr->payload.
        }
    }





}

template <typename T>
int AdjacencyList<T>::getInnerSize(int i)
{
    return data[i].getLen();
}


#endif // ADJACENCYLIST_H
