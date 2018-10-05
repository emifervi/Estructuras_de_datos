#pragma once
#include "NodeT.h"

class BST{
public:
    BST();
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    void print(int x);
    
private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int predecesor(NodeT *r);
    int sucesor(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void free(NodeT *r);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    free(root);
}

int BST::howManyChildren(NodeT *r){
    int c = 0;
    if(r->getLeft() != nullptr){
        c++;
    }
    if(r->getRight() != nullptr){
        c++;
    }

    return c;
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

int BST::predecesor(NodeT *r){
    NodeT *aux = r->getLeft();
    
    while(aux->getRight() != nullptr){
        aux = aux->getRight();
    }
    return aux->getData();
}

int BST::sucesor(NodeT *r){
    NodeT *aux = r->getRight();

    while(aux->getLeft() != nullptr){
        aux = aux->getLeft();
    }
    return aux->getData();
}

void BST::preOrder(NodeT *r){
    if(r != nullptr){
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r){
    if(r != nullptr){
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r){
    if(r != nullptr){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::free(NodeT *r){
    if (r != nullptr){
        free(r->getLeft());
        free(r->getRight());
        delete r;
    }
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

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;

    while(curr != nullptr && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data) ? 
                curr->getLeft() : curr->getRight();
    }

    if(curr == nullptr){
        return;
    }

    int c = howManyChildren(curr);
    
    switch(c){
        case 0: 
            if(father == nullptr){
                root = nullptr;
            }
            else{
                if(father->getData() > data){
                    father->setLeft(nullptr);
                }
                else{
                    father->setRight(nullptr);
                }
            }
            delete curr;
            break;

        case 1:
            if(father == nullptr){
                if(curr->getLeft() != nullptr){
                    root = curr->getLeft();
                }
                else{
                    root = curr->getRight();
                }
            }
            else{
                if(father->getData() > data){
                    if(curr->getLeft() != nullptr){
                        father->setLeft(curr->getLeft());
                    }
                    else{
                        father->setLeft(curr->getRight());
                    }
                }
                else{
                    if(curr->getLeft() != nullptr){
                        father->setRight(curr->getLeft());
                    }
                    else{
                        father->setRight(curr->getRight());
                    }

                }
            }
            delete curr;
            break;
        
        case 2:
            int x = sucesor(curr);
            remove(x);
            curr->setData(x);
            break;
    }
}

void BST::print(int c){
    switch(c){
        case 1:
            preOrder(root);
            break;
        
        case 2:
            inOrder(root);
            break;
        
        case 3:
            postOrder(root);
            break;
    }
    cout << endl;
}