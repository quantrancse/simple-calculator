#ifndef NODE_H
#define NODE_H

template <class DataType>
class LinkedList;

template <class DataType>
class Node {
   public:
    friend class LinkedList<DataType>;
    DataType value;
    Node* pNext;

    Node();
    Node(DataType);
    //~Node();
};
#endif
