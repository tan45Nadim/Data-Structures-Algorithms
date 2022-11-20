#include "unsortedtype.h"

template<class T>
UnsortedType<T>::UnsortedType() {
    length = 0;
    currentPos = -1;
}

template<class T>
bool UnsortedType<T>::isEmpty() {
    return length == 0;
}

template<class T>
bool UnsortedType<T>::isFull() {
    return length == max_items;
}

template<class T>
void UnsortedType<T>::makeEmpty() {
    length = 0;
}

template<class T>
void UnsortedType<T>::Insert(T item) {
    data[length] = item;
    length++;
}

template<class T>
void UnsortedType<T>::Delete(T item) {
    int pos;
    for(int i=0; i<length; i++) {
        if(data[i] == item) {
            pos = i;
            break;
        }
    }
    for(int i=pos; i<length-1; i++) {
        data[i] = data[i+1];
    }
    length--;
}

template<class T>
int UnsortedType<T>::LengthIs() {
    return length;
}

template<class T>
void UnsortedType<T>::getNextItem(T& item) {
    currentPos++;
    item = data[currentPos];
}

template<class T>
void UnsortedType<T>::ResetList() {
    currentPos = -1;
}

template<class T>
void UnsortedType<T>::RetriveItem(T& item, bool& found) {
    for(int i=0; i<length; i++) {
        if(data[i] == item) {
            found = true;
            break;
        }
    }
}
