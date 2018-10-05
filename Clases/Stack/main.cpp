#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack<int> miPila;
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);

    cout << "El tamaño de mi pila es: " << miPila.size() << endl;

    while(!miPila.empty()){
        cout << miPila.top() << endl;
        miPila.pop();
    }

    return 0;
}

