#include <iostream>
#include "unsortedtype.cpp"
#include "student.h"
using namespace std;

void checkEmpty(UnsortedType<int> u) {
    if(u.isEmpty())
        cout<<"List is Empty"<<endl;
    else
        cout<<"List not Empty"<<endl;
}

void checkFull(UnsortedType<int> u) {
    if(u.isFull())
        cout<<"List is full"<<endl;
    else
        cout<<"List is not full"<<endl;
}

void countLength(UnsortedType<int> u) {
    int cnt = u.LengthIs();
    cout<<cnt<<endl;
}

void print(UnsortedType<int> u) {
    int temp;
    for(int i=0; i<u.LengthIs(); i++) {
        u.getNextItem(temp);
        cout<<temp<<" ";
    }
    cout<<endl;
    u.ResetList();
}

void print(UnsortedType<Student> u) {
    Student temp;
    for(int i=0; i<u.LengthIs(); i++) {
        u.getNextItem(temp);
        temp.PrintStudent();
    }
    cout<<endl;
    u.ResetList();
}
void checkValue(UnsortedType<int> u, int n) {
    bool found = false;
    u.RetriveItem(n, found);
    if(found)
        cout<<"Item is found"<<endl;
    else
        cout<<"Item is not found"<<endl;
}

void Retrieve(UnsortedType <Student> u, Student stu) {
    bool found = false;
    u.RetriveItem(stu, found);
    if(found) {
        cout<<"Item is found"<<endl;
        Student temp;
        for(int i=0; i<u.LengthIs(); i++) {
            u.getNextItem(temp);
            if(temp == stu) {
                temp.PrintStudent();
                break;
            }
        }
    }
    else
        cout<<"Item is not found"<<endl;
}

int main() {
    UnsortedType<int>u1;
    u1.Insert(5);
    u1.Insert(7);
    u1.Insert(6);
    u1.Insert(9);

    print(u1);
    countLength(u1);
//    cout<<u1.LengthIs()<<endl;

    u1.Insert(1);
    print(u1);

    checkValue(u1, 4);
    checkValue(u1, 5);
    checkValue(u1, 9);
    checkValue(u1, 10);

    checkFull(u1);
    u1.Delete(5);
    checkFull(u1);
    u1.Delete(1);
    print(u1);
    u1.Delete(6);
    print(u1);


    Student s1(15234, "Jon", 2.6);
    Student s2(13732, "Tyrion", 3.9);
    Student s3(13569, "Sandor", 1.2);
    Student s4(15467, "Ramsey 2", 3.1);
    Student s5(16285, "Arya", 3.1);

    UnsortedType<Student> stu;

    stu.Insert(s1);
    stu.Insert(s2);
    stu.Insert(s3);
    stu.Insert(s4);
    stu.Insert(s5);
//    print(stu);

    Student id = 15467;
    stu.Delete(id);

    id = 13569;
    Retrieve(stu, id);
    cout<<endl;
    print(stu);

    return 0;
}
