#include "Calculate.h"
#include <math.h>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Check if Operator
bool Calculate::checkOperator(char ch) {
    if (ch == '#' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == '=' || ch == '^')
        return true;
    else
        return false;
}

// Priority in postfix
int Calculate::getPriority(TokenType token) {
    switch (token) {
        case DATA:
        case VAR:
            return 0;
        case PLUS:
        case MINUS:
            return 1;
        case MULT:
        case DIV:
            return 2;
        case POW:
            return 3;
        case UNI_PLUS:
        case UNI_MINUS:
            return 4;
        case LEFT:
        case RIGHT:
            return -1;
        default:
            return -2;
    }
}

// Split string to token with value and type
void Calculate::getToken(string str) {
    char pre = '#';  // Check if Uni at first pos
    string token = "";
    int check = 0;

    // Split
    while (str[0] != '\0') {
        if (check == 0)
            token = "";
        if (str[0] == '(') {
            token = str[0];
            Token s(token, LEFT);
            token_list.append(s);
        } else if (check != 2 && ((str[0] >= '0' && str[0] <= '9') || str[0] == '.')) {
            token.push_back(str[0]);
            check = 1;
        } else if ((checkOperator(str[0]) == 0 && str[0] != ')') || ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))) {
            token.push_back(str[0]);
            check = 2;
        } else if (check == 1) {
            Token s(token, DATA);
            token_list.append(s);
            check = 0;
            continue;
        } else if (check == 2) {
            Token s(token, VAR);
            token_list.append(s);
            check = 0;
            continue;
        } else if (str[0] == '+' && checkOperator(pre)) {
            token = str[0];
            Token s(token, UNI_PLUS);
            token_list.append(s);
        } else if (str[0] == '-' && checkOperator(pre)) {
            token = str[0];
            Token s(token, UNI_MINUS);
            token_list.append(s);
        } else if (str[0] == '+') {
            token = str[0];
            Token s(token, PLUS);
            token_list.append(s);
        } else if (str[0] == '-') {
            token = str[0];
            Token s(token, MINUS);
            token_list.append(s);
        } else if (str[0] == '*') {
            token = str[0];
            Token s(token, MULT);
            token_list.append(s);
        } else if (str[0] == '/') {
            token = str[0];
            Token s(token, DIV);
            token_list.append(s);
        } else if (str[0] == '^') {
            token = str[0];
            Token s(token, POW);
            token_list.append(s);
        } else if (str[0] == ')') {
            token = str[0];
            Token s(token, RIGHT);
            token_list.append(s);
        }
        pre = str[0];
        str = str.substr(1, string::npos);
    }

    // Push last token
    if (str[0] == '\0' && token == ")") {
        Token s(token, RIGHT);
        token_list.append(s);
    } else if (str[0] == '\0' && (token[0] >= '0' && token[0] <= '9')) {
        Token s(token, DATA);
        token_list.append(s);
    } else {
        Token s(token, VAR);
        token_list.append(s);
    }
}

// Infix token list to Postfix token list
void Calculate::InfixToPostfix() {
    Stack<Token> s(1000);

    for (int i = 0; i < token_list.length(); i++) {
        if (getPriority(token_list.getAt(i).getType()) == 0)
            postfix_list.append(token_list.getAt(i));
        else if (token_list.getAt(i).getType() == LEFT)
            s.push(token_list.getAt(i));
        else if (token_list.getAt(i).getType() == RIGHT) {
            while (!s.empty() && s.top().getType() != LEFT) {
                postfix_list.append(s.top());
                s.pop();
            }
            if (s.top().getType() == LEFT) {
                s.pop();
            }
        } else {
            if ((getPriority(token_list.getAt(i).getType()) == 4 || getPriority(token_list.getAt(i).getType()) == 3) && getPriority(s.top().getType()) == 3)  // Negative exponent
                s.push(token_list.getAt(i));
            else {
                while (!s.empty() && getPriority(token_list.getAt(i).getType()) <= getPriority(s.top().getType())) {
                    postfix_list.append(s.top());
                    s.pop();
                }
                s.push(token_list.getAt(i));
            }
        }
    }

    while (!s.empty()) {
        postfix_list.append(s.top());
        s.pop();
    }
}

// Calculate equation
float Calculate::cal(string input_string) {
    getToken(input_string);
    InfixToPostfix();

    Stack<float> s(1000);
    float val1 = 0.0;
    float val2 = 0.0;
    for (int i = 0; i < postfix_list.length(); i++) {
        bool check = false;  // check if there is valid variable
        switch (postfix_list.getAt(i).getType()) {
            case DATA:
                s.push(stof(postfix_list.getAt(i).getValue()));
                break;
            case VAR:
                for (int j = var_list.length() - 1; j >= 0; j--) {
                    if (postfix_list.getAt(i).getValue().compare(var_list.getAt(j).getVarName()) == 0) {
                        s.push(stof(var_list.getAt(j).getValue()));
                        check = true;
                        break;
                    }
                }
                if (check == false)  // variable = 0 if not found
                    s.push(0);
                break;
            case PLUS:
                val1 = s.top();
                s.pop();
                val2 = s.top();
                s.pop();
                s.push(val2 + val1);
                break;
            case MINUS:
                val1 = s.top();
                s.pop();
                val2 = s.top();
                s.pop();
                s.push(val2 - val1);
                break;
            case MULT:
                val1 = s.top();
                s.pop();
                val2 = s.top();
                s.pop();
                s.push(val2 * val1);
                break;
            case DIV:
                val1 = s.top();
                if (val1 == 0) {
                    cout << "Cannot divide zero" << endl;
                    // system("pause");
                    exit(0);
                }
                s.pop();
                val2 = s.top();
                s.pop();
                s.push(val2 / val1);
                break;
            case POW:
                val1 = s.top();
                s.pop();
                val2 = s.top();
                s.pop();
                s.push(pow(val2, val1));
                break;
            case UNI_MINUS:
                val1 = s.top();
                s.pop();
                s.push(-val1);
                break;
            default:
                break;
        }
    }

    // Reset List
    token_list.clear();
    postfix_list.clear();
    return s.top();
}

// Split variable formula for calculate
string Calculate::getFormula(string input_str) {
    string str = "";
    for (int i = 0; i < input_str.length(); i++) {
        if (input_str[i] == ';' || input_str[i] == '\0')
            break;
        else if (input_str[i] != '=')
            str.push_back(input_str[i]);
    }
    if (str.compare("") == 0) {
        cout << "Invalid Input" << endl;
        // system("pause");
        exit(0);
    }
    return str;
}

// Call if calculate variabble
void Calculate::calVar(string str) {
    string token_name = "";

    // Get variables and get their value
    while (str[0] != '\0') {
        if ((str[0] >= '0' && str[0] <= '9') || (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '.' || str[0] == '_' || str[0] == '-') {
            token_name.push_back(str[0]);
            str = str.substr(1, string::npos);
        } else if (str[0] == '=') {
            string formula = getFormula(str);
            Token s(to_string(cal(formula)), token_name, VAR);  // Get valriable value
            var_list.append(s);
            token_name = "";
            size_t pos = str.find_first_of(';');  // Split for next variable
            if (pos == string::npos)
                break;
            str = str.substr(pos + 1, string::npos);
        }
    }

    cout << "Result:" << endl;
    for (int i = 0; i < var_list.length(); i++)
        cout << var_list.getAt(i).getVarName() << " = " << fixed << setprecision(2) << stof(var_list.getAt(i).getValue()) << endl;
}

void Calculate::eval(string input_str) {
    string str;

    // Check for valid input
    int count = 0;
    for (int i = 0; i < input_str.length(); i++) {
        if (input_str[i] == ')')
            count--;
        if (count < 0) {
            cout << "Invalid Parentheses Input" << endl;
            // system("pause");
            exit(0);
        }
        if (input_str[i] == '(')
            count++;
        if ((input_str[i] == '(' && str[str.length() - 1] == ')') || (input_str[i] == ')' && str[str.length() - 1] == '(')) {
            cout << "Invalid Parentheses Input" << endl;
            // system("pause");
            exit(0);
        }
        if (input_str[i] == ')' && checkOperator(str[str.length() - 1])) {
            cout << "Invalid Operator Input" << endl;
            // system("pause");
            exit(0);
        }
        if ((input_str[i] == '*' || input_str[i] == '/' || input_str[i] == '^') && checkOperator(str[str.length() - 1])) {
            cout << "Invalid Operator Input" << endl;
            exit(0);
        }
        if (input_str[i] == '+' && checkOperator(str[str.length() - 1]))
            continue;
        if (input_str[i] == '-' && str[str.length() - 1] == '-') {
            str.pop_back();
            str.push_back('+');
            continue;
        }
        if (input_str[i] == '-' && (str[str.length() - 1] == '=' || str[str.length() - 1] == '('))
            str.push_back('0');
        if (input_str[i] != ' ')
            str.push_back(input_str[i]);
    }
    if (count != 0) {
        cout << "Invalid Parentheses Input" << endl;
        // system("pause");
        exit(0);
    }
    while (str[0] == '+')
        str.erase(0, 1);
    if (str[0] == '-')
        str.insert(0, "0");

    bool check = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == '=')
            check = 1;
    if (check)
        calVar(str);
    else
        cout << "Result: " << fixed << setprecision(2) << cal(str) << endl;
}
