#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPair(char opening, char closing) {
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    return false;
}

bool isBalancedParentheses(string str) {
    stack <char> s;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(s.empty() || !isPair(s.top(),str[i]))
                return false;
        else
                s.pop();
        }
    }
    return s.empty();
}

int main() {
    cout << "Enter an expression: " ;
    string s; cin >> s;

    if(isBalancedParentheses(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}


/*
Output

Enter an expression: ({)}{}
Not Balanced

Enter an expression: ([]){}{[]}
Balanced

Enter an expression: (((((()))))
Not Balanced

*/
