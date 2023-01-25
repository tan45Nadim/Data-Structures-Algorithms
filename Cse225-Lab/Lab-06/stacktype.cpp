#include "stacktype.h"
#include<iostream>
using namespace std;

template<class T>
stackType<T>::stackType() {
    top = -1;
}

template<class T>
bool stackType<T>::isEmpty() {
    return (top == -1);
}

template<class T>
bool stackType<T>::isFull() {
    return (top == max_items - 1);
}

template<class T>
void stackType<T>::push(T item) {
    try {
        if(isFull()) {
            throw FullStack();
        }
        top++;
        data[top] = item;
    }catch(FullStack f) {
        cout<<"Stack is already Full"<<endl;
    }
}

template<class T>
void stackType<T>::pop() {
    try {
        if(isEmpty()) {
            throw EmptyStack();
        }
        top--;
    }catch(EmptyStack e) {
        cout<<"Stack is already Empty"<<endl;
    }
}

template<class T>
T stackType<T>::Top()
{
    try {
        if(isEmpty()) {
            throw EmptyStack();
        }
        return data[top];
    }catch(EmptyStack e) {
        cout<<"Stack is already Empty"<<endl;
    }
}
