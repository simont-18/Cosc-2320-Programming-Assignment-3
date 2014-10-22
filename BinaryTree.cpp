#include "BinaryTree.h"

BinaryTree::BinaryTree(string a) {
    ParentNode = buildTree(a);
}

NodeB* BinaryTree::buildTree(string x) {
    NodeB *Result = nullptr;
    remainder = x.substr(1,string::npos);
    
    if(x[0] == '#')
        return nullptr;
    else {
        Result = new NodeB();
        Result->Data = x[0];
        Result->Left = buildTree(remainder);
        Result->Right = buildTree(remainder);
    }
    
    return Result;
}

void BinaryTree::print() {
    inorder(ParentNode);
}

void BinaryTree::inorder(NodeB *current) {
    if(current !=  nullptr) {
        inorder(current->Left);
        cout << current->Data << ' ';
        inorder(current->Right);
    }
}
