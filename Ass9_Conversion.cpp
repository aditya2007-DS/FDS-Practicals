/* Assignment 9.
Conversion and Evaluation of Expressions Using Stacks
*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' &&
                  (precedence(s.top()) > precedence(ch) ||
                  (precedence(s.top()) == precedence(ch)
                  && ch != '^'))) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            s.push(applyOperator(a, b, ch));
        }
    }

    return s.top();
}

int evaluatePrefix(string exp) {
    stack<int> s;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            s.push(applyOperator(a, b, ch));
        }
    }

    return s.top();
}

int main() {
    string infix;

    cout << "Enter infix expression (single-digit operands): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << prefix << endl;

    cout << "Postfix Evaluation: "
         << evaluatePostfix(postfix) << endl;

    cout << "Prefix Evaluation: "
         << evaluatePrefix(prefix) << endl;

    return 0;
}

/*
Sample Output:

Enter infix expression (single-digit operands): (3+4)*2
Postfix Expression: 34+2*
Prefix Expression: *+342
Postfix Evaluation: 14
Prefix Evaluation: 14
*/
