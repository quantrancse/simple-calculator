#include <iostream>
#include "Calculate.h"
#include "Calculate.cpp"

using namespace std;

int main() {
    string str;
    cout << "Enter equation: ";
    getline(cin, str);

    Calculate s;
    s.eval(str);

    return 0;
}