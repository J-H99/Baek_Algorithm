#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cmpPrecedence(char operand1, char operand2) {
    if (operand1 == '*' || operand1 == '/') {
        operand1 = '2';
    }
    else if (operand1 == '+' || operand1 == '-') {
        operand1 = '1';
    }
    else if (operand1 == '(') {
        operand1 = '0';
    }

    if (operand2 == '*' || operand2 == '/') {
        operand2 = '2';
    }
    else if (operand2 == '+' || operand2 == '-') {
        operand2 = '1';
    }
    else if (operand2 == '(') {
        operand2 = '0';
    }


    if (operand1 > operand2) {
        return 1;
    }
    else if (operand1 < operand2) {
        return -1;
    }
    else {
        return 0;
    }
}
int main() {
    string exp, convExp = "";
    stack<char> stack_char;

    cin >> exp;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            stack_char.push(exp[i]);
        }

        else if (exp[i] == ')') {   
            while (stack_char.top() != '(') {
                convExp += stack_char.top();
                stack_char.pop();
            }
            stack_char.pop();
        }

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            while (!stack_char.empty() && cmpPrecedence(stack_char.top(), exp[i]) >= 0) {
                convExp += stack_char.top();
                stack_char.pop();
            }
            stack_char.push(exp[i]);
        }

        else if (exp[i] >= 'A' && exp[i] <= 'Z') {
            convExp += exp[i];
        }
    }

    while (!stack_char.empty()) {
        convExp += stack_char.top();
        stack_char.pop();
    }

    cout << convExp;
    return 0;
}