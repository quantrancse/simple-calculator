#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "Stack.cpp"
#include "Stack.h"
#include "Token.cpp"
#include "Token.h"

class Calculate {
   private:
    LinkedList<Token> token_list;
    LinkedList<Token> postfix_list;
    LinkedList<Token> var_list;

   public:
    bool checkOperator(char);
    int getPriority(TokenType);
    void getToken(string);
    void InfixToPostfix();
    float cal(string);
    string getFormula(string);
    void calVar(string);
    void eval(string);
};

#endif
