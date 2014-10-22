#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
using namespace std;

typedef int* intptr;

void testInfixToPostfix();
void testStack();
void testBinaryTree();

int main(int argc, const char * argv[]) {
//    testStack();
//    testInfixToPostfix();
    testBinaryTree();
    return 0;
}

void testInfixToPostfix() {
    //test expression: a*b-c*d-(e-(f/h+1)*j-k)*g
    string input;
    cout << "Please enter an expression: ";
    getline(cin, input);
    
    Expression *Converter = new Expression(input);
    Converter->convertToPostfix();
    Converter->print();
}

void testStack() {
    Stack<int> *stack1 = new Stack<int>();
    Stack<double> *stack2 = new Stack<double>();
    Stack<char> *stack3 = new Stack<char>();
    Stack<intptr> *stack4 = new Stack<intptr>();
    
    cout << "-----Testing an \"int\" stack-----\n";
    cout << "Pushing 6, 8, 4, 9 onto the stack.\n";
    stack1->push(6);
    stack1->push(8);
    stack1->push(4);
    stack1->push(9);
    
    cout << stack1->top() << endl;      stack1->pop();
    cout << stack1->top() << endl;      stack1->pop();
    cout << stack1->top() << endl;      stack1->pop();
    cout << stack1->top() << endl;      stack1->pop();
    
    cout << "\n-----Testing a \"double\" stack-----\n";
    cout << "Pushing 5.274, 6.2, 1.10, 15.256 onto the stack.\n";
    stack2->push(5.274);
    stack2->push(6.2);
    stack2->push(1.10);
    stack2->push(15.256);
    
    cout << stack2->top() << endl;      stack2->pop();
    cout << stack2->top() << endl;      stack2->pop();
    cout << stack2->top() << endl;      stack2->pop();
    cout << stack2->top() << endl;      stack2->pop();
    
    cout << "\n-----Testing a \"char\" stack-----\n";
    cout << "Pushing b, f, a, s onto the stack.\n";
    stack3->push('b');
    stack3->push('f');
    stack3->push('a');
    stack3->push('s');
    
    cout << stack3->top() << endl;      stack3->pop();
    cout << stack3->top() << endl;      stack3->pop();
    cout << stack3->top() << endl;      stack3->pop();
    cout << stack3->top() << endl;      stack3->pop();
    
    int num1 = 8;
    int num2 = 6;
    int num3 = 3;
    int num4 = 7;
    
    cout << "-----Testing an \"int pointer\" stack-----\n";
    cout << "Pushing 8, 6, 3, 7 onto the stack.\n";
    stack4->push(&num1);
    stack4->push(&num2);
    stack4->push(&num3);
    stack4->push(&num4);
    
    cout << stack4->top() << endl;      stack4->pop();
    cout << stack4->top() << endl;      stack4->pop();
    cout << stack4->top() << endl;      stack4->pop();
    cout << stack4->top() << endl;      stack4->pop();
}

void testBinaryTree() {
    string input[4] = {"ABD#EF####CG##HI###", "ACD##E#H##BF##GI###", "AB#D#F##C#EGI###H##", "A#BC#D#EF#G####"};
    string output[4] = {"D F E B A G C I H", "D C E H A F B I G", "B D F A C I G E H", "A C D F G E B"};
    int i = 0;
    BinaryTree *b = new BinaryTree(input[i]);
    b->print();
    cout << endl << output[i];
    cout << endl;
}