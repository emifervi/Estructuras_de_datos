#pragma once
#include "NodeT.h"
#include <queue>
#include <stack>

class BST{
public:
    BST();
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    void print(int x);
    int count();
    void printLeaves();
    int height(); // tarea programada
    void ancestors(int data);
    int whatLevelamI(int data);
    
private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int predecesor(NodeT *r);
    int sucesor(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void levelOrder(NodeT *r);
    void leafNodes(NodeT *r);
    void free(NodeT *r);
    // void leafNodes(NodeT *r);  // recurisva
    int getHeight(NodeT *r); // tarea programada
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

void BST::ancestors(int data){
    NodeT *curr = root;
    stack<NodeT *>nodeStack;
    nodeStack.push(curr);

    while(!nodeStack.empty()){
        if(curr->getData() == data){
            cout << nodeStack.top()->getData() << " ";
            nodeStack.pop();
        }
        else{
            curr = (curr->getData() > data) ?
                    curr->getLeft() : curr->getRight();
            if(curr->getData() != data){
                nodeStack.push(curr);
            }
        }
    }
    cout << endl;
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

void BST::levelOrder(NodeT *r){
    if(r != nullptr){
        queue<NodeT *> nodeQueue;
        nodeQueue.push(r);

        while(!nodeQueue.empty()){
            NodeT *temp = nodeQueue.front();
            nodeQueue.pop();
            cout << temp->getData() << " ";

            if(temp->getLeft()){
                nodeQueue.push(temp->getLeft());
            }
            if(temp->getRight()){
                nodeQueue.push(temp->getRight());
            }
        }
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

/* 
Leaf nodes recursiva
void BST::leafNodes(NodeT *r){

    if(r == nullptr){
        return;
    }

    if(r->getLeft() == nullptr && r->getRight() == nullptr){
        cout << r->getData() << endl;
    }

    if(r->getLeft()){
        leafNodes(r->getLeft());
    }

    if(r->getRight()){
        leafNodes(r->getRight());
    }
} */

void BST::printLeaves(){
    if(!root){
        return;
    }

    else{
        queue<NodeT *> leafQueue;
        leafQueue.push(root);

        while(!leafQueue.empty()){
            NodeT *temp = leafQueue.front();
            leafQueue.pop();

            if(temp->getLeft()){
                leafQueue.push(temp->getLeft());
            }
            if(temp->getRight()){
                leafQueue.push(temp->getRight());
            }
            if(!temp->getLeft() && !temp->getRight()){
                cout << temp->getData() << " ";
            }
        }

        cout << endl;
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
        
        /* case 4:
            leafNodes(root);
            break; */
        
        case 5:
            levelOrder(root);
            break;
    }
    cout << endl;
}
 


int BST::getHeight(NodeT *r){
    if(r == nullptr){
        return 0;
    }

    else{
        int leftHeight = getHeight(r->getLeft());
        int rightHeight = getHeight(r->getRight());

        int maxHeight = (leftHeight > rightHeight) ? 
                         leftHeight + 1 : rightHeight + 1;
        return maxHeight;
    }
}

int BST::whatLevelamI(int data){
    NodeT *curr = root;
    int level = 0;

    while(curr != nullptr){
        if(curr->getData() == data){
            return level;
        }
        else{
            level++;
            curr = (curr->getData() > data) ? 
                    curr->getLeft():curr->getRight();
        }
    }
    return -1;
}
 
int BST::height(){
    return getHeight(root);
}

int BST::count(){
    if(root == nullptr){
        return 0;
    }

    else{
        queue<NodeT *> nodeQueue;
        int nodeCount = 1;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            NodeT *temp = nodeQueue.front();
            nodeQueue.pop();

            if(temp->getLeft()){
                nodeQueue.push(temp->getLeft());
                nodeCount++;
            }
            if(temp->getRight()){
                nodeQueue.push(temp->getRight());
                nodeCount++;
            }
        }

        return nodeCount;
    }
}

