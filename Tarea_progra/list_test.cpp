#include <iostream>
using namespace std;
#include "Lista.h"

int main(){
	Lista<string> iLista;
	iLista.add("c");
	iLista.add("a");
	iLista.add("g");
	iLista.add("b");

	cout<<iLista.getCant()<<endl<<iLista.getDato(2)<<endl;

	cout<<iLista.search("a")<<endl;

	Lista<string> iLista2 = iLista;

	cout<<"iLista"<<endl;
	iLista.print();

	cout<<endl<<"iLista2"<<endl;
	iLista2.print();

	if(iLista == iLista2){
		cout<<endl<<"Son iguales"<<endl<<endl;
	}
	else{
		cout<<endl<<"NO son iguales"<<endl<<endl;
		
	}

	iLista2.sort(true);

	cout<<"iLista"<<endl;
	iLista.print();

	cout<<endl<<"iLista2"<<endl;
	iLista2.print();

	if(iLista == iLista2){
		cout<<endl<<"Son iguales"<<endl<<endl;
	}
	else{
		cout<<endl<<"NO son iguales"<<endl<<endl;
		
	}

	iLista2.sort(false);
	cout<<endl<<"iLista2"<<endl;
	iLista2.print();
	
	cout<<"Check"<<endl;

	Lista<string> iLista3(iLista2);

	cout<<endl<<"iLista3"<<endl;
	iLista3.print();
	
	return 0;
}