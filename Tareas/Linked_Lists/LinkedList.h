#include "Node.h"

template <class T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();

        void addFirst(T data);
        void addLast(T data);
       
        void deleteFirst();
        
        bool isEmpty();


    private:
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
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

template <class T>
void LinkedList<T>::deleteFirst(){
    if(!isEmpty()){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (head == NULL);
}



