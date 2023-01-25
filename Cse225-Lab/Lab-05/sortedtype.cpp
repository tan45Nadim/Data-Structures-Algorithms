#include "sortedtype.h"

template<class T>
sortedType<T>::sortedType() {
    length = 0;
    currentPos = -1;
}

template<class T>
bool sortedType<T>::isEmpty() {
    return length == 0;
}

template<class T>
bool sortedType<T>::isFull() {
    return length == max_items;
}

template<class T>
void sortedType<T>::makeEmpty() {
    length = 0;
}

template<class T>
void sortedType<T>::Insert(T item) {
    int pos=0;
    for(int i=0; i<length; i++)
    {
        if(data[i] < item){
            pos++;
        }
    }
    for(int i=length-1; i >= pos; i--)
    {
        data[i+1] = data[i];
    }
    data[pos] = item;
    length++;
}

template<class T>
void sortedType<T>::Delete(T item) {
    int pos;
    for(int i=0; i<length; i++)
    {
        if(data[i] == item) {
            pos = i;
            break;
        }
    }
    for(int i=pos; i<length-1; i++)
    {
        data[i] = data[i+1];
    }
    length--;
}

template<class T>
int sortedType<T>::LengthIs() {
    return length;
}

template<class T>
void sortedType<T>::getNextItem(T& item) {
    currentPos++;
    item = data[currentPos];
}

template<class T>
void sortedType<T>::ResetList() {
    currentPos = -1;
}

template<class T>
void sortedType<T>::RetriveItem(T& item, bool& found) {
    int first = 0, last = length - 1;

    while(first <= last)
    {
        int mid = (first + last)/2;
        if(data[mid] == item) {
            found = true;
            break;
        }
        else if(data[mid] < item) {
            first = mid + 1;
        }
        else {
            last = mid -1;
        }
    }
}
