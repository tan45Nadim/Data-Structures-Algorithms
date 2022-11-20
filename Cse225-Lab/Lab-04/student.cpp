#include "student.h"

Student::Student() {
    id = 0;
    name = "";
    cgpa = 0;
}
Student::Student(int i) {
    id = i;
}

Student::Student(int i, string n, float c) {
    id = i;
    name = n;
    cgpa = c;
}

void Student::PrintStudent() {
    cout<<id<<" "<<name<<" "<<cgpa<<endl;
}

bool operator==(Student s1, Student s2) {
    return s1.id == s2.id;
}
