#include <iostream>
using namespace std;
#include "BST.h"

int main(){

    BST miArbol;
    
    miArbol.add(12);
    miArbol.add(100);
    miArbol.add(45);
    miArbol.add(50);
    miArbol.add(8);
    miArbol.add(10);
    miArbol.add(-5);
    miArbol.add(65);
    miArbol.add(13);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    miArbol.printLeaves();

    cout << "El arbol tiene: " << miArbol.count() << " nodos." << endl;

    // cout << "Altura: " << miArbol.getHeight() << endl;

    if(miArbol.search(100)){
        cout << "Encontre el 100" << endl;
    }
    if(miArbol.search(200)){
        cout << "Encontre el 200" << endl;
    }
    else{
        cout << "No encontre el 200" << endl;
    }

    miArbol.remove(12);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    miArbol.printLeaves();

    return 0;
}