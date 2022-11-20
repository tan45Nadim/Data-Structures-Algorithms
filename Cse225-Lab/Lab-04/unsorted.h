#ifndef UNSORTED_H_INCLUDED
#define UNSORTED_H_INCLUDED

const int max_items = 5;
template<class T>
class UnsortedType {
private:
    T data[max_items];
    int length;
    int currentPos;
public:
    UnsortedType();

    bool isEmpty();
    bool isFull();

    void makeEmpty();

    void Insert(T item);
    void Delete(T item);

    int LengthIs();

    void getNextItem(T&);
    void ResetList();
    void RetriveItem(T&, bool&);

};
#endif // UNSORTED_H_INCLUDED
