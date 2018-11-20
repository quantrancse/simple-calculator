#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum TokenType {
    LEFT = 0,
	RIGHT,       // 1
	PLUS,        // 2
    UNI_PLUS,    // 3
    MINUS,       // 4
	UNI_MINUS,   // 5
	MULT,        // 6
    DIV,         // 7
    POW,         // 8
    DATA,        // 9
    VAR          // 10
};

class Token {
   private:
    string value;
    string var_name;
    TokenType type;

   public:
    Token();
    Token(string, TokenType);
    Token(string, string, TokenType);
    string getValue();
    string getVarName();
    TokenType getType();
};
#endif
