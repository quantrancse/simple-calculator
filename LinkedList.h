#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.cpp"
#include "Node.h"

template <class DataType>
class LinkedList {
   private:
    Node<DataType>* pHead;
    Node<DataType>* pLast;
    int count;

   public:
    LinkedList();
    ~LinkedList();
    int length();
    void push(DataType);
    void append(DataType);
    void insert(DataType, DataType);
    DataType get();
    DataType getAt(int);
    void remove(int);
    bool empty();
    void clear();
    void print();
};
#endif
