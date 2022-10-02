#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

bool IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool IsNumericDigit(char c) {
    return (c >= '0' && c <= '9');
}

int PerformanceOperation(char operation, int operand01, int operand02) {
    if (operation == '+') return operand01 + operand02;
    else if (operation == '-') return operand01 - operand02;
    else if (operation == '*') return operand01 * operand02;
    else if (operation == '/') return operand01 / operand02;
    else if (operation == '^') return (pow(operand01,operand02));

    return -1;
}

int EvaluatePostfix(string expression) {
    stack <int> s;

    for(int i=0; i<expression.length(); i++) {

        if(expression[i] == ' ' || expression[i] == ',')
            continue;

        else if(IsNumericDigit(expression[i])) {
            int operand = 0;
            while(i<expression.length() && IsNumericDigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }

        else if(IsOperator(expression[i])) {
            int operand02 = s.top();
            s.pop();
            int operand01 = s.top();
            s.pop();
            int result = PerformanceOperation(expression[i], operand01, operand02);

            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter Postfix expression: ";
    getline(cin, expression);

    int result = EvaluatePostfix(expression);
    cout << "answer: " << result << endl;
}

/*
Output

Enter Postfix expression: 7 2 4 * + 9 2 * - 5 + 9 3 / + 2 -
answer: 3

*/
