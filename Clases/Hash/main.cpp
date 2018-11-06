#include <iostream>
#include <set>

using namespace std;

int main(){

    set<int> miSet;
    int n, dato;

    cout << "Cuantos datos ?" << endl;
    cin >> n;

    for(int i=0; i < n; i++){
        cout << "Inseta tus datos:" << endl;
        cin >> dato;
        miSet.insert(dato);
    }

    cout << "Dato a buscar: ";
    cin >> dato;

    set<int>::iterator it = miSet.find(dato);

    if (it != miSet.end()){
        cout << "Sí está" << endl;
    }
    else{
        cout << "NO ESTÁ" << endl;
    }

    return 0;
}