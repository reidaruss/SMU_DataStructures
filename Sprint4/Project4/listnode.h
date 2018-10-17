#ifndef LISTNODE_H
#define LISTNODE_H

template<class T>
class ListNode
{
    template<class U> friend class LinkedList;
private:
    ListNode<T>* next;
    ListNode<T>* prev;
    T payload;
public:
    ListNode();
};

#endif // LISTNODE_H
