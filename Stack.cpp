#include "Stack.h"
#include <cstring>
#include <iostream>

using namespace std;

template <class DataType>
Stack<DataType>::Stack() {
    capacity = 10;
    csize = 0;
    storage = new DataType[capacity];
}

template <class DataType>
Stack<DataType>::Stack(int capacity) {
    this->capacity = capacity;
    csize = 0;
    storage = new DataType[capacity];
}

template <class DataType>
Stack<DataType>::~Stack() {
    delete[] storage;
}

template <class DataType>
int Stack<DataType>::size() {
    return csize;
}

template <class DataType>
DataType Stack<DataType>::top() {
    return storage[csize - 1];
}

template <class DataType>
void Stack<DataType>::push(DataType value) {
    if (csize == capacity)
        cout << "Overflow" << endl;
    else {
        storage[csize] = value;
        csize++;
    }
}

template <class DataType>
void Stack<DataType>::pop() {
    csize = csize - 1;
}

template <class DataType>
void Stack<DataType>::showstack() {
    for (int i = csize - 1; i >= 0; i--)
        cout << storage[i] << " ";
}

template <class DataType>
bool Stack<DataType>::empty() {
    if (csize == 0)
        return true;
    else
        return false;
}
