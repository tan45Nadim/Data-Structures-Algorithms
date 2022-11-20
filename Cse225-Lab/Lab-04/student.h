#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
using namespace std;
class Student {
    friend bool operator==(Student, Student);
private:
    int id;;
    string name;
    float cgpa;
public:
    Student();
    Student(int);
    Student(int, string, float);
    void PrintStudent();
};
#endif // STUDENT_H_INCLUDED
