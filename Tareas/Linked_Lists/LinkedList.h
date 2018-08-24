#include "Node.h"

template <class T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();

        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int iPosicion);
       
        void deleteFirst();
        void deleteLast();
        void del(T data, int iPosicion);
        int deleteAll();

        int getSize();
        
        bool isEmpty();


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
        while(curr - >getNext()-> getNext() != NULL){
            curr = curr -> getNext();
        }
        delete curr -> getNext();
        curr -> setNext(NULL);
        size--;
    }
}

template <class T>
void LinkedList<T>::del(T data, int iPosicion){
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
    return iCant;
}

template <class T>
void LinkedList<T>::deleteHelper(){
    Node<T> *curr = head;
    while( !this ->isEmpty()){
        head = haed->getNext();
        delete curr;
        curr = head;
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



