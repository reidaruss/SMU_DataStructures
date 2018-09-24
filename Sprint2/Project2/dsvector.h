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
    DSVector(const DSVector<T>& v);//Copy Constructor
    DSVector& operator=(const DSVector<T>& rhs);//Overloaded Assignment Operator
    T& operator[](int i);
    //~DSVector();//destructor



   void pushBack(const T val);
   T getElement(int k);
    //void remove();
   void resize();
   int getSize();
};





template <typename T>
DSVector<T>::DSVector()
{
    size = 0;
    capacity = 10;
    data = new T[capacity];
}


template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& rhs) // Overloaded assignment operator.
{
    if(data)
        delete[] data;
    size = rhs.size;
    capacity = rhs.capacity;

    data = new T[rhs.size];
    for(int i = 0; i < rhs.size; i++)
        data[i] = rhs.data[i];

    return *this;
}

template <typename T>
T& DSVector<T>::operator[](int i)
{
    if(i >= size)
        cerr << "Unable to access. Out of scope" << endl;
    else
        return data[i];
}

template <typename T>
DSVector<T>::DSVector(const DSVector<T>& v) //Copy Constructor
{

    size = v.size;
    capacity = v.capacity;
    data = new T[capacity];
    for(int i = 0 ; i < size ; i++)
    {
        data[i] = v.data[i];
    }


}
template <typename T>
T DSVector<T>::getElement(int k) //Return index of k
{
    for(int i = 0; i < size; i ++)
        if(data[i] == k)
            return i;
    else
            return -1;
}

template <typename T>
int DSVector<T>::getSize()
{
    return size;
}

template <typename T>
void DSVector<T>::pushBack(const T val) //Add element to data then incriment size.
{
    if(size < capacity)
    {

        data[size] = val;
        size++;
    }
    else
    {
        resize();
        data[size] = val;
        size++;
    }



}

template <typename T>
void DSVector<T>::resize()
{


    capacity *= 2;
    T* temp = new T[capacity];
    for(int i =0; i <size; i ++)
        temp[i] = data[i];
    delete[] data;
    data = temp;



}

//template <typename T>
//DSVector<T>::~DSVector()
//{
//    if(this->data != nullptr)

//}



#endif // DSVECTOR_H
