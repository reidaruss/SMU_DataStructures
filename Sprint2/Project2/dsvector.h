#ifndef DSVECTOR_H
#define DSVECTOR_H

template <typename T>
class DSVector
{
private:
    int size;
    int capacity;
    T* data;
public:
    DSVector();
    DSVector(const dsvector<T>&);//Copy Constructor
    DSVector& operator=(const DSVector& rhs);//Overloaded Assignment Operator
    ~Vector();//destructor



    void pushBack(T& val);
    void remove();
    void resize();
}



#endif // DSVECTOR_H
