#include <iostream>
#include "sortedtype.cpp"
#include "timestamp.h"

using namespace std;

void CheckEmpty(sortedType<int> s) {
    if(s.isEmpty())
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        cout<<"Not Empty"<<endl;
    }
}

void CheckFull(sortedType<int> s) {
    if(s.isFull())
    {
        cout<<"List is full"<<endl;
    }
    else
    {
        cout<<"List not full"<<endl;
    }
}

void Print(sortedType<int> s) {
    int temp;
    for(int i= 0 ; i<s.LengthIs();i++)
    {
        s.getNextItem(temp);
        cout<<temp<<" ";
    }
    cout<<endl;
    s.ResetList();
}

void Print(sortedType<timeStamp> s) {
    timeStamp temp;
    for(int i= 0 ; i<s.LengthIs();i++)
    {
        s.getNextItem(temp);
        temp.printTime();
    }
    cout<<endl;
    s.ResetList();
}

void CheckValue(sortedType<int> s, int n) {
    bool found = false;
    s.RetriveItem(n,found);
    if(found)
    {
        cout<<"Item is found"<<endl;
    }
    else
    {
        cout<<"Item is not found"<<endl;
    }
}

int main() {
    sortedType<int> s1;

    cout<<s1.LengthIs()<<endl;
    s1.Insert(5);
    s1.Insert(7);
    s1.Insert(4);
    s1.Insert(2);
    s1.Insert(1);

    Print(s1);
    CheckValue(s1, 6);
    CheckValue(s1, 5);
    CheckFull(s1);
    s1.Delete(1);
    Print(s1);
    CheckFull(s1);


    timeStamp t1(15, 34, 23);
    timeStamp t2(13, 13, 02);
    timeStamp t3(43, 45, 12);
    timeStamp t4(25, 36, 17);
    timeStamp t5(52, 02, 20);

    sortedType<timeStamp> ts;

    ts.Insert(t1);
    ts.Insert(t2);
    ts.Insert(t3);
    ts.Insert(t4);
    ts.Insert(t5);

    cout<<endl;
//    Print(ts);
    ts.Delete(t4);
    Print(ts);
}
