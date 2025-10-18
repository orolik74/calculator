#include <bits/stdc++.h>
using namespace std;

int Priority(char a){
    if (a == '+' || a == '-') {
        return 1;
    }
    if (a == '*' || a == '/') {
        return 2;
    }
    return 0;
}

long double Calculate(string s) {
    vector <long double> numbers;
    vector <char> operators;

    string cur = "";
    for (auto x: s) {
        if (x == '+' || x == '-' || x == '/' || x == '*' || x == '(' || x == ')') {
            if (!cur.empty()) {
                numbers.push_back(stod(cur));
                cur.clear();
            }
        }
        if (x == '+' || x == '-' || x == '/' || x == '*') {
            while (!operators.empty() && Priority(operators.back()) >= Priority(x)) {
                long double b = numbers.back();
                numbers.pop_back();
                long double a = numbers.back();
                numbers.pop_back();
                char op = operators.back();
                operators.pop_back();
                if (op == '+') {
                    numbers.push_back(a + b);
                } else if (op == '-') {
                    numbers.push_back(a - b);
                }
                else if (op == '/') {
                    numbers.push_back(a / b);
                }
                else {
                    numbers.push_back(a * b);
                }
            }
            operators.push_back(x);
        }
        else if (x == ')') {
            while (operators.back() != '(') {
                long double b = numbers.back();
                numbers.pop_back();
                long double a = numbers.back();
                numbers.pop_back();
                char op = operators.back();
                operators.pop_back();
                if (op == '+') {
                    numbers.push_back(a + b);
                } else if (op == '-') {
                    numbers.push_back(a - b);
                }
                else if (op == '/') {
                    numbers.push_back(a / b);
                }
                else {
                    numbers.push_back(a * b);
                }
            }
            operators.pop_back();
        }
        else if (x == '(') {
            operators.push_back(x);
        }
        else {
            cur += x;
        }
    }
    if (!cur.empty()) {
        numbers.push_back(stod(cur));
    }
    while (!operators.empty()) {
        long double b = numbers.back();
        numbers.pop_back();
        long double a = numbers.back();
        numbers.pop_back();
        char op = operators.back();
        operators.pop_back();
        if (op == '+') {
            numbers.push_back(a + b);
        } else if (op == '-') {
            numbers.push_back(a - b);
        }
        else if (op == '/') {
            numbers.push_back(a / b);
        }
        else {
            numbers.push_back(a * b);
        }
    }
    return numbers[0];
}