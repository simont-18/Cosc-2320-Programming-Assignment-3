#ifndef __Cosc_2320_Programming_Assignment_3__Expression__
#define __Cosc_2320_Programming_Assignment_3__Expression__

#include <stdio.h>
#include <iostream>
#include "Stack.h"
using namespace std;

class Expression {
public:
    Expression(string s);
    bool isValidExpression(string s);
    bool isBalance(string s);
    bool isOperand(char c);
    bool isOperator(char c);
    void setInfix(string s);
    bool precedence(char leftOperator, char rightOperator);
    void convertToPostfix();
    void print();
private:
    string infix, postfix;
};

#endif
