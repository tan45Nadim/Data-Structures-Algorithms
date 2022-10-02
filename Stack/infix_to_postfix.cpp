#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;

    return -1;
}

bool isOperand(char c) {
    if(c >= '0' && c <= '9') return true;
    else if(c >= 'a' && c <= 'z') return true;
    else if(c >= 'A' && c <= 'Z') return true;

    return false;
}

string InfixToPostfix(string infix) {
    stack <char> s;
    string postfix = "";

    for(int i=0; i<infix.length(); i++) {
        if(isOperand(infix[i])) {
            postfix += infix[i];
            postfix += " ";
        }
        else if(infix[i] == '(') {
            s.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(s.top() != '(' && (!s.empty())) {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            if(s.top() == '(')
                s.pop();
        }
        else if(isOperator(infix[i])) {
            if(s.empty()) {
                s.push(infix[i]);
            }
            else {
                if(precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if(precedence(infix[i]) == precedence(s.top()) && (infix[i] == '^')) {
                    s.push(infix[i]);
                }
                else {
                    while(!s.empty() && (precedence(infix[i]) <= (precedence(s.top())))) {
                        postfix += s.top();
                        postfix += " ";
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        postfix += " ";
        s.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    getline(cin, infix);

    string postfix = InfixToPostfix(infix);

    cout << "PostFix : " << postfix << endl;
}


/*
Output

Enter Infix Expression: 7+(2*4)-9*2+5+(9/3)-2
PostFix : 7 2 4 * + 9 2 * - 5 + 9 3 / + 2 -

*/
