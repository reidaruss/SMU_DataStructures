#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
using namespace std;
template <typename T>
class DSVector
{
private:
    int size;
    int capacity;
    T* data;
public:
    DSVector();
    DSVector(const DSVector<T>&);//Copy Constructor
    DSVector& operator=(const DSVector<T>& rhs);//Overloaded Assignment Operator
    //~DSVector();//destructor



   void pushBack(const T&);
   T getElement(int i);
    //void remove();
    //void resize();
};





template <typename T>
DSVector<T>::DSVector()
{
    size = 0;
    cout << size << endl;
    capacity = 10;
    cout << capacity << endl;
    data = new T[capacity];
}


//template <typename T>
//DSVector<T>::operator=(const DSVector<T>& rhs)
//{

//}

template <typename T>
DSVector<T>::DSVector(const DSVector<T>&)
{
    this->size = size;
    this->capacity = capacity;
    for(int i = 0 ; i < this->size ; size++)
    {
        this->data[i] = data[i];
    }
}
template <typename T>
T DSVector<T>::getElement(int i) //Return val at i
{
    return data[i];
}

template <typename T>
void DSVector<T>::pushBack(const T& val) //Add element to data then incriment size.
{

    if(size == capacity)
        cout << "Need to resize" << endl;
    else
    {
        data[size] = val;
        size ++;
    }
}


#endif // DSVECTOR_H
