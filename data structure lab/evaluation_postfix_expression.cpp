#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 9;

double scanNum(char ch) {
    int value;
    value = ch - '0';
    return (double) value;
}

bool isOperator(char ch) {
    if (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^') {
        return 1;
    }
    return 0;
}

bool isOperand(char ch) {
    if (ch >= '0' and ch <= '9') return 1;
    return 0;
}

double operation(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return a / b;
    else if (op == '^') return pow(a, b);
    else return -INF;
}

double postFixEval(string postFix) {
    stack<double> stk;
    for (auto ch : postFix) {
        if (isOperand(ch)) {
            stk.push(scanNum(ch));
        }
        else if (isOperator(ch)) {
            double b = stk.top();
            stk.pop();
            double a = stk.top();
            stk.pop();
            stk.push(operation(a, b, ch));
        }
    }
    return stk.top();
}

int main() {
    string postFix;
    cout << "Enter Postfix Expression: ";
    cin >> postFix;
    double res = postFixEval(postFix);
    cout << "Evaluation result: " << res << endl;
}
