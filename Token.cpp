#include <string>
#include "Token.h"

using namespace std;

Token::Token() {
    value = "";
    var_name = "";
}

Token::Token(string val, TokenType type) {
    value = val;
    var_name = "";
    this->type = type;
}

Token::Token(string val, string name, TokenType type) {
    value = val;
    var_name = name;
    this->type = type;
}

string Token::getValue() {
    return value;
}

string Token::getVarName() {
    return var_name;
}

TokenType Token::getType() {
    return type;
}
