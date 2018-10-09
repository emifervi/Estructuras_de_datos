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



    /* Purebas tarea programada */
    
    // prueba printLeaves
    miArbol.printLeaves();
    
    // prueba acestros
    cout << "Ancestros de 65: ";
    miArbol.ancestors(65);

    // prueba count
    cout << "El arbol tiene: " << miArbol.count() << " nodos." << endl;
    
    // prueba height
    cout << "Altura del arbol: " << miArbol.height() << endl;

    // prueba print(5)
    cout << "Level Order: ";
    miArbol.print(5);

    // prueba whatLevelamI
    cout << "Nivel de 65: ";
    cout << miArbol.whatLevelamI(200) << endl;

    /* Fin pruebas */

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

    return 0;
}