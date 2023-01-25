#include <iostream>
#include "stacktype.cpp"
using namespace std;

void checkEmpty(stackType<int> s) {
    if(s.isEmpty())
        cout<<"Stack is Empty"<<endl;
    else
        cout<<"Stack is not Empty"<<endl;
}

void checkFull(stackType<int> s) {
    if(s.isFull())
        cout<<"Stack is Full"<<endl;
    else
        cout<<"Stack is not Full"<<endl;
}
void Print(stackType<int> s) {
    stackType <int> aux;

    while(!s.isEmpty()) {
        aux.push(s.Top());
//        cout<<s.Top()<<" ";     // for reverse print
        s.pop();
    }
//    cout<<endl;
    while(!aux.isEmpty()) {
        s.push(aux.Top());
        cout<<aux.Top()<<" ";
        aux.pop();
    } cout<<endl;
}

void isBalanced(string str, char start, char end) {
    stackType <char> s;

    for(int i=0; i<str.size(); i++) {
        if(str[i] == start) {
            s.push(str[i]);
        }
        if(str[i] == end) {
            if(!s.isEmpty()) {
                if(s.Top() == start) {
                    s.pop();
                }
                else {
                    cout<<"Not Parenthesis Balanced"<<endl;
                    return;
                }
            }
            else {
                cout<<"Parenthesis Balanched"<<endl;
                return;
            }
        }
    }
    if(s.isEmpty()) {
        cout<<"Parenthesis Balanched"<<endl;
    }
    else {
        cout<<"Not Parenthesis Balanched"<<endl;
    }
}

int main() {
    stackType<int> s1;
    checkEmpty(s1);

    s1.push(5);
    s1.push(7);
    s1.push(4);
    s1.push(2);

    checkEmpty(s1);
    checkFull(s1);
    Print(s1);

    s1.push(3);
    checkFull(s1);

    s1.pop();
    s1.pop();
    Print(s1);
    cout << s1.Top() << endl;

    string str1 = "()";
    string str2 = "(())()(()())()";
    string str3 = "(())()((()";
    string str4 = "(())))((()";

    isBalanced(str1, '(', ')');
    isBalanced(str2, '(', ')');
    isBalanced(str3, '(', ')');
    isBalanced(str4, '(', ')');

    return 0;
}
