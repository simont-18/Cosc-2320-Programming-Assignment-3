#ifndef __Cosc_2320_Programming_Assignment_3__BinaryTree__
#define __Cosc_2320_Programming_Assignment_3__BinaryTree__

#include <stdio.h>
#include <iostream>
using namespace std;

struct NodeB {
    NodeB *Left = nullptr;
    NodeB *Right = nullptr;
    char Data;
};

class BinaryTree {
public:
    BinaryTree(string a);
    void print();
private:
    NodeB* buildTree(string a);
    void inorder(NodeB *current);
    NodeB *ParentNode;
    string remainder;
};

#endif
