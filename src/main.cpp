#include <string>
#include <iostream>
#include <iomanip>
#include "calculator.h"
using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << setprecision(20) << Calculate(s) << '\n';
}