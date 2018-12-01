#include <iostream>
#include "Calculate.cpp"
#include "Calculate.h"

using namespace std;

int main() {
    string str;
    Calculate s;
    
    cout << "Enter equation: ";
    getline(cin, str);
    s.eval(str);

    // system("pause");
    return 0;
}
