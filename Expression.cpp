#include "Expression.h"

Expression::Expression(string s) {
    setInfix(s);
}

bool Expression::isValidExpression(string s) {
    if((isOperator(s[0]) || isOperator(s[s.length()-1])) && !isBalance(s))
        return false;
    for(int i = 0; i < s.length(); i++) {
        if(isOperand(s[i]) && i+1 < s.length()) {
            if(!isOperator(s[i+1]) && s[i+1] != '(' && s[i+1] != ')') {
                cout << "here 1\n";
                return false;
            }
        } else if(isOperator(s[i]) && i+1 < s.length()) {
            if(!(s[i+1] == '(') && !isOperand(s[i+1])) {
                return false;
            }
        }
    }

    return true;
}

bool Expression::isBalance(string s) {
    int open = 0, close = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
            open++;
        if(s[i] == ')')
            close++;
    }
    
    if(open == close)
        return true;
    else
        return false;
}

bool Expression::isOperand(char c) {
    if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        return true;
    else
        return false;
}

bool Expression::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

void Expression::setInfix(string s) {
    if(isValidExpression(s)) {
        this->infix = s;
    }
    else {
        cerr << "Invalid infix expression, please enter another infix expression.\n";
    }
}

bool Expression::precedence(char leftOperator, char rightOperator)
{
    if (leftOperator == '*' || leftOperator == '/') {
        return true;
    } else if (rightOperator == '*' || rightOperator == '/') {
        return false;
    }
    
    return true;
}

void Expression::convertToPostfix() {
    Stack<char> s;
    s.push('('); // Push a left parenthesis ‘(‘ onto the stack.
    
    for(int i = 0; i < infix.length(); i++) {
        char current = infix[i];
        
        if(isOperand(current)) {
            postfix += current;
        } else if('(' == current) {
            s.push(current);
        } else if(isOperator(current)) {
            char rightOperator = current;
            while(!s.isEmpty() && isOperator(s.top()) && precedence(s.top(), rightOperator)) {
                postfix += s.top();
                s.pop();
            }
            s.push(rightOperator);
        } else if(')' == current) {
            while(!s.isEmpty() && '(' != s.top()) {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    
    while(!s.isEmpty() && '(' != s.top()) {
        postfix += s.top();
        s.pop();
    }
    s.pop();
}

void Expression::print() {
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
}