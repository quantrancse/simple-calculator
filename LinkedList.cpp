/**
 * Linked List
 *
 **/

#include "LinkedList.h"
#include <iostream>

using namespace std;

template <class DataType>
LinkedList<DataType>::LinkedList() {
    pHead = NULL;
    pLast = NULL;
    count = 0;
}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
    Node<DataType> *pRun = pHead;
    while (pRun != NULL) {
        pRun = pRun->pNext;
        delete pHead;
        pHead = pRun;
    }
}

template <class DataType>
int LinkedList<DataType>::length() {
    return count;
}

template <class DataType>
void LinkedList<DataType>::push(DataType value) {
    Node<DataType> *pNew = new Node<DataType>(value);
    if (count == 0) {
        pHead = pNew;
        pLast = pNew;
    } else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
    count++;
}

template <class DataType>
void LinkedList<DataType>::append(DataType value) {
    Node<DataType> *pNew = new Node<DataType>(value);
    if (count == 0) {
        pHead = pNew;
        pLast = pNew;
    } else {
        pLast->pNext = pNew;
        pLast = pNew;
    }
    count++;
}

template <class DataType>
void LinkedList<DataType>::insert(DataType prev, DataType value) {
    Node<DataType> *pRun = pHead;
    bool check = false;
    while (pRun != NULL) {
        if (pRun->value == prev) {
            if (pRun->pNext == NULL)
                append(value);
            else {
                Node<DataType> *pNew = new Node<DataType>(value);
                pNew->pNext = pRun->pNext;
                pRun->pNext = pNew;
            }
            check = true;
        }
        pRun = pRun->pNext;
    }
    if (check == false)
        cout << "Error: No previous value" << endl;
}

template <class DataType>
DataType LinkedList<DataType>::get() {
    return pHead->value;
}

template <class DataType>
DataType LinkedList<DataType>::getAt(int index) {
    Node<DataType> *pRun = pHead;
    if (index < count)
        for (int i = 0; i < index; i++)
            pRun = pRun->pNext;
    return pRun->value;
}

template <class DataType>
void LinkedList<DataType>::remove(int index) {
    if (index == 0) {
        Node<DataType> *pTemp = pHead;
        pHead = pHead->pNext;
        free(pTemp);
        if (count == 1)
            pLast == NULL;
        count--;
    } else if (index >= 0 && index <= count - 1) {
        Node<DataType> *pRun = pHead;
        for (int i = 0; i < index - 1; i++) {
            pRun = pRun->pNext;
        }
        Node<DataType> *pTemp = pRun->pNext;
        pRun->pNext = pRun->pNext->pNext;
        free(pTemp);
        if (index == count - 1)
            pLast = pRun;
        count--;
    } else
        cout << "Invalid Index" << endl;
}

template <class DataType>
bool LinkedList<DataType>::empty() {
    if (count == 0)
        return true;
    else
        return false;
}

template <class DataType>
void LinkedList<DataType>::clear() {
    pHead = NULL;
    pLast = NULL;
    count = 0;
}

template <class DataType>
void LinkedList<DataType>::print() {
    Node<DataType> *pRun = pHead;
    while (pRun != NULL) {
        cout << pRun->value << endl;
        pRun = pRun->pNext;
    }
}
