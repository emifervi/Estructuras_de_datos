#pragma once
#include "Node.h"

template <class T>
class Stack{
    public:
        Stack();
        ~Stack();
        T top();
        void push(T data);
        void pop();
        int size();
        bool empty();

    private:
        Node<T> *tope;
        int tam;
};

template <class T>
Stack<T>::Stack(){
    tope = NULL;
    tam = 0;
}

template <class T>
Stack<T>::~Stack(){
    Node<T> *curr = tope;
    while(tope != NULL){
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

template <class T>
T Stack<T>::top(){
    return tope->getData();
}

template <class T>
int Stack<T>::size(){
    return tam;
}

template <class T>
void Stack<T>::push(T data){
    tope = new Node<T>(data, tope);
    tam++;
}

template <class T>
bool Stack<T>::empty(){
    return tope == NULL;
}

template <class T>
void Stack<T>::pop(){
    Node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    tam--;
}