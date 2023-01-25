#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int max_items = 5;
class EmptyStack {

};
class FullStack {

};

template<class T>
class stackType {
private:
    int data[max_items];
    int top;
public:
    stackType();
    bool isEmpty();
    bool isFull();
    void push(T);
    void pop();
    T Top();
};

#endif // STACKTYPE_H_INCLUDED
