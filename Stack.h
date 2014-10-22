#ifndef __Cosc_2320_Programming_Assignment_3__Stack__
#define __Cosc_2320_Programming_Assignment_3__Stack__

#include <stdio.h>
#include <iostream>
using namespace std;

//helper Node struct for Stack class
template <class T>
struct Node {
    Node *next = nullptr;
    T data = NULL;
};

//Stack class implementation using Linked-List
template <class Type>
class Stack {
public:
    Stack();
    void push(Type element);
    void pop();
    Type top();
    bool isEmpty();
private:
    Node<Type> *first;
};

template <class Type>
Stack<Type>::Stack() {
    first = nullptr;
}

template <class Type>
void Stack<Type>::push(Type newElement) {
    Node<Type> *newNode = new Node<Type>;
    newNode->data = newElement;
    newNode->next = first;
    first = newNode;
}

template <class Type>
void Stack<Type>::pop() {
    Type popResult = NULL;
    if(!isEmpty()) {
        Node<Type> *temp;
        temp = first;
        popResult = temp->data;
        first = first->next;
        delete temp;
    }
    else
        cerr << "Error: Can not delete from an empty stack.\n";
}

template <class Type>
Type Stack<Type>::top() {
    if(!isEmpty())
        return first->data;
    else
        cerr << "Warning: The stack is empty.\n";
    return NULL;
}

template <class Type>
bool Stack<Type>::isEmpty() {
    return first == nullptr;
}
#endif