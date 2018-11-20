#include "Node.h"

using namespace std;

template <class DataType>
Node<DataType>::Node() {
    pNext = NULL;
}

template <class DataType>
Node<DataType>::Node(DataType value) {
    this->value = value;
    pNext = NULL;
}

template <class DataType>
Node<DataType>::~Node() {
    delete pNext;
}
