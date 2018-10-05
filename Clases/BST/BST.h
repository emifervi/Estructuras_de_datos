#pragma once
#include "NodeT.h"

class BST{
public:
    BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    
private:
    NodeT *root;
};

BST::BST(){
    root = nullptr;
}

bool BST::search(int data){
    NodeT *curr = root;
    while(curr != nullptr){
        if(curr->getData() == data){
            return true;
        }
        curr = (curr->getData() > data) ? 
                curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::add(int data){
    NodeT *father = nullptr;
    NodeT *curr = root;

    while(curr != nullptr){
        if(curr->getData() == data){
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ? 
                curr->getLeft() : curr->getRight();
    }

    if(father == nullptr){
        root = new NodeT(data);
    }
    else{
        if(father->getData() > data){
            father->setLeft(new NodeT(data));
        }
        else{
            father->setRight(new NodeT(data));
        }
    }
}