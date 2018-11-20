#ifndef STACK_H
#define STACK_H

template <class DataType>
class Stack {
    private:       
        int csize;
        int capacity;
        DataType *storage;
    public:
        Stack();
        Stack(int);
        ~Stack();

        int size();
        DataType top();
        void push(DataType);
        void pop();
        void showstack();
        bool empty();
};
#endif
