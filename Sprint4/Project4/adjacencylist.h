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
    //T& operator[](int i);
    void insert(T find, T val);
    LinkedList<T> findWhereFirstIs(string val);
    LinkedList<T> stepIterator(string val);
    string getAt(int i, int j);

};

#endif // ADJACENCYLIST_H
template <typename T>
AdjacencyList<T>::AdjacencyList()
{
    size = 0;
}
//template <typename T>
//T& AdjacencyList<T>::operator[](int i)
//{
//    if( i >= size)
//        cerr << "op[] Unable to access. Out of scope" << endl;
//    else
//        return data[i];
////    if(i >= size)
////        cerr << "op[] Unable to access. Out of scope" << endl;
////    else if(i == 0)
////    {

////        curr = head;
////        return curr->payload;
////    }

//}
template <typename T>
void AdjacencyList<T>::insert(T find, T val)
{

    for(int i = 0; i < data.getLen(); i ++)
    {
        if(data[i][0] == find)
            data[i].addBack(val);
        else
        {
            LinkedList<T> temp;
            temp.addBack(find);
            temp.addBack(val);
            data.addBack(temp);
        }
    }
    if(data.getLen() == 0)
    {
        LinkedList<T> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
    }

}
template <typename T>
string AdjacencyList<T>::getAt(int i, int j)
{
    return data[i][j];
}


template <typename T>
LinkedList<T> AdjacencyList<T>::findWhereFirstIs(string val)
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i];
    }
}



//LinkedList<string> AdjacencyList::stepIterator(string val)
//{
//    LinkedList<string> L = findWhereFirstIs(val);
//    return L.getNext();
//}
