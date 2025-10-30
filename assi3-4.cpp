#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top(); s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., a+b*(c^d-e)^(f+g*h)-i): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
