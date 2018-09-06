/*
 * Emilio Fernando Alonso Villa
 * A00959385
 */

#pragma once
#include "Node.h"

template <class T>
class LinkedList{
    public:
        LinkedList();
        LinkedList(const LinkedList<T> &Linked);
        ~LinkedList();

        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int iPosicion);
       
        void deleteFirst();
        void deleteLast();
        void del(int iPosicion);
        int deleteAll();

        int getSize();
        
        bool isEmpty();

        T get(int pos);
        T set(T data, int pos);
        bool change(int pos1, int pos2);
        void print();

        void reverse();

        bool operator == (const LinkedList<T> &Linked);
        void operator += (T data);
        void operator += (const LinkedList<T> &Linked);
        void operator = (const LinkedList<T> &Linked);
    
    private:
        void deleteHelper();
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &Linked){
    if (Linked.size > 0){
        head = new Node<T>(Linked.head->getData(), NULL);
        size = 1;
        
        Node<T> *curr1 = head, *curr2 = Linked.head;

        while(curr2->getNext() != NULL){
            curr2 = curr2->getNext();
            curr1->setNext(new Node<T>(curr2->getData(), NULL));
            curr1 = curr1 -> getNext();
            size++;
        }
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteHelper();
}

template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void  LinkedList<T>::addLast(T data){
    if (this -> isEmpty()){
        addFirst(data);
    }
    else{
        // Crea apuntador auxiliar a nodo para recorrer lista
        Node<T> *curr = head;
        while (curr->getNext() != NULL){
            curr = curr->getNext();
        }
        
        // Cuando llega a null, asigna a curr como el siguiente nodo con el data
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template<class T>
bool LinkedList<T>::add(T data, int iPosicion){
    if(iPosicion > size){
        return false;
    }
    if(iPosicion == 0){
        addFirst(data);
    }
    else if (iPosicion == size){
        addLast(data);
    }
    else {
        Node<T> *curr = head;
        for (int i = 1; i < iPosicion; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::deleteFirst(){
    if(!this -> isEmpty()){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast(){
    if(size <= 1){
        deleteFirst();
    }
    else{
        Node<T> *curr = head;
        while(curr -> getNext()-> getNext() != NULL){
            curr = curr -> getNext();
        }
        delete curr -> getNext();
        curr -> setNext(NULL);
        size--;
    }
}

template <class T>
void LinkedList<T>::del(int iPosicion){
    if (iPosicion == 0){
        deleteFirst();
    }
    else if (iPosicion == size - 1){
        deleteLast();
    }
    else{
        Node<T> *curr = head;
        for (int i = 1; i < iPosicion; i++){
            curr = curr->getNext();
        }
        Node<T> *temp = curr->getNext();
        curr->setNext(temp->getNext());
        delete temp;
        size--;
    }
}

template <class T>
int LinkedList<T>::deleteAll(){
    int iCant = size;
    deleteHelper();
    size = 0;
    return iCant;
}

template <class T>
void LinkedList<T>::deleteHelper(){
    Node<T> *curr = head;
    while( !this ->isEmpty()){
        head = head->getNext();
        delete curr;
        curr = head;
        size--;
    }
}

template<class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (head == NULL);
}

template <class T>
T LinkedList<T>::get(int pos){
    Node<T> *curr = head;

    for(int i = 0; i < pos; i++){
        curr = curr->getNext();
    }

    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
    Node<T> *curr = head;
    
    for (int i = 0; i < pos; i++){
        curr = curr->getNext();
    }

    T dataAux = curr->getData();
    curr->setData(data);

    return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
    if(pos1 > size || pos2 > size || pos1 < 0 || pos2 < 0){
        return false;
    }

    if (pos1 == pos2){
        return true;
    }

    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);

    Node<T> *curr1 = head;
    for(int i=0; i < posMen; i++){
        curr1 = curr1->getNext();
    }

    Node<T> *curr2 = curr1;
    for(int i= posMen; i<posMay; i++){
        curr2 = curr2->getNext();
    }

    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);

    return true;
}

template <class T>
void LinkedList<T>::print(){
    Node<T> *curr = head;
    while(curr != NULL){
        cout << curr->getData() <<  " ";
        curr = curr->getNext();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::reverse(){

    Node<T> *current = head;
    Node<T> *prev = NULL, *next = NULL;

    while(current != NULL){
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    head = prev;
}

template <class T>
bool LinkedList<T>::operator == (const LinkedList<T> &Linked){
    if(size != Linked.size){
        return false;
    }

    else{
        bool flag = false;
        Node<T> *curr1 = head, *curr2 = Linked.head;
        
        while(curr1 != NULL){
            flag = curr1->getData() == curr2->getData();
            
            if(!flag){
                return false;
            }
            
            else{
                curr1 = curr1->getNext();
                curr2 = curr2->getNext();
            }
        }
        return flag; 
    }
}

template <class T>
void LinkedList<T>::operator += (T data){
    this->addLast(data);
}

template <class T>
void LinkedList<T>::operator += (const LinkedList<T> &Linked){

    if(Linked.size > 0){
        
        Node<T> *curr1 = head, *curr2 = Linked.head;

        if(size == 0){
            addFirst(curr2->getData());
            curr2 = curr2->getNext();
            curr1 = head;
        }

        while(curr1->getNext() != NULL){
            curr1 = curr1->getNext();
        }

        while(curr2 != NULL){
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
            size++;
        }
    }
}

template <class T>
void LinkedList<T>::operator = (const LinkedList<T> &Linked){
    if(this->size > 0){
        this->deleteAll();
    }

    head = new Node<T>(Linked.head->getData(), NULL);
    size = 1;
        
    Node<T> *curr1 = head, *curr2 = Linked.head;

    while(curr2->getNext() != NULL){
        curr2 = curr2->getNext();
        curr1->setNext(new Node<T>(curr2->getData(), NULL));
        curr1 = curr1 -> getNext();
        size++;
    }
}