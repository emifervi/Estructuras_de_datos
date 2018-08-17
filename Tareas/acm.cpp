#include <iostream>
#include <map>
using namespace std;

struct Equipo{
    string nombre;
    map<string, int> problemsSolved;

    Equipo() {
        nombre = "";
    }    

    Equipo(string nombre){
        this->nombre = nombre;
    }
};

int main(){
    int iNumEquipos, iNumProblemas, iNumSoluciones;

    cin >> iNumEquipos >> iNumProblemas;

    map<string, Equipo> mapaEquipos;

    for (int i = 0; i < iNumEquipos; i++){
        string sNombre;
        cin >> sNombre;
        // Recibe el nombre del equipo, lo pasa como llave y como valor en el mapa
        mapaEquipos[sNombre] = Equipo(sNombre);
    }

    cin >> iNumSoluciones;
    
    for(int i = 0; i < iNumSoluciones; i++){
        // Recibe un nombre de equipo, problema resuelto, tiempo tardado y
        // si fue aceptado o no
        string sNombre, sProblema, sEstatus;
        int iTiempo;

        cin >> sNombre >> sProblema >> iTiempo >> sEstatus;

        Equipo equipo = mapaEquipos[sNombre];
        if(equipo.problemsSolved.count(sProblema)){
            equipo.problemsSolved[sProblema] += (sEstatus[0] == 'A') ? iTiempo : 20;
        }
        else{
            equipo.problemsSolved[sProblema] = (sEstatus[0] == 'A') ? iTiempo : 20;
        }
    }
    for(auto const& i : mapaEquipos){ //cada equipo
        cout << i.first << " " << i.second.nombre << endl;
    }
}


