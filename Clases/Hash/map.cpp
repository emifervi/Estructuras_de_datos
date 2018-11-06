#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string, int> miMap;
	int n, edad;
	string nom;

	cout << "Cuantos datos" << endl;
	cin >> n;

	for(int i=0; i < n; i++){
		cin >> nom >> edad;
		pair<string, int> miPar(nom, edad);
		miMap.insert(miPar);
	}

	cout << "Dar el nombre a buscar: ";
	cin >> nom;
	map<string, int>::iterator it = miMap.find(nom);

	if(it != miMap.end()){
		cout << it->second << endl;
	}
	else{
	     cout << "NO ESTA" << endl;
    }	     
}

