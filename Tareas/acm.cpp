#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Problem{
    int score;
    string status;

    Problem(){
        score = 0;
        status = "";
    }

    Problem(int score, string status){
        this->score = score;
        this->status = status;
    }
};

struct Team{
    string name;
    map<string, Problem> problemsSolved;
    int result, regNum, solved;

    Team(){
        name = "";
        result = 0;
        regNum = 0;
        solved = 0;
    }    

    Team(string name){
        this->name = name;
        result = 0;
        solved = 0;
    }
};

void fill (int numSolns, map<string, Team> &regTeams);
void mapTransfer(map<string, Team> &regTeams, vector<Team> &list);
void display(vector<Team> &list);
void swap(int *xp, int *yp);
void bubbleSort(vector<Team> &list);

int main(){
    int numTeams, numProblems, numSolns;

    cin >> numTeams >> numProblems;

    map<string, Team> teamMap;

    for (int i = 0; i < numTeams; i++){
        string teamName;
        cin >> teamName;
        // Recibe el nombre del equipo, lo pasa como llave y como valor en el mapa
        teamMap[teamName] = Team(teamName);
        teamMap[teamName].regNum = i + 1;
    }

    cin >> numSolns;

    // SE llena el mapa
    fill(numSolns, teamMap);

    // Se pasa el mapa a una lista y se ordena.
    vector <Team> teamList;

    mapTransfer(teamMap, teamList);
    bubbleSort(teamList);

    // Se despliegan los resultados.
    display(teamList);

    return 0;
}

// La función toma como parametros el número de soluciones y un mapa con los nombres de los equipos
// y modifica los scores de los equipos con base en si resolvieron o no los problemas.
void fill(int solutions, map<string, Team> &regTeams){
    for(int i = 0; i < solutions; i++){
        // Recibe un nombre de equipo, problema resuelto, tiempo tardado y
        // si fue aceptado o no
        string teamName, problemName, probStatus;
        int timeTaken;

        cin >> teamName >> problemName >> timeTaken >> probStatus;
        Problem answeredProblem = Problem(timeTaken, probStatus);

        // Verifica si el problema existe en el mapa de problemas
        if(regTeams[teamName].problemsSolved.count(problemName)){
            // Si sí existe evalua el puntaje y cambia el status y puntaje
            if(answeredProblem.status[0] == 'A'){
                regTeams[teamName].problemsSolved[problemName].status = answeredProblem.status;
            }
            regTeams[teamName].problemsSolved[problemName].score += (regTeams[teamName].problemsSolved[problemName].status[0] == 'A') ? timeTaken : 20;
        }
        else{
            // Si no existe lo anexa y evalua el status y puntaje
            regTeams[teamName].problemsSolved[problemName] = answeredProblem;
            regTeams[teamName].problemsSolved[problemName].score = (regTeams[teamName].problemsSolved[problemName].status[0] == 'A') ? timeTaken : 20;
        } 
    }
}

// La función toma como parámetros el mapa de equipos registrados y un vector para 
// guardar todos y posteriormente ordenarlos.
void mapTransfer(map<string, Team> &regTeams, vector<Team> &list){
    
    // Itera sobre cada equipo en el mapa, calcula el resultado y lo pasa al vector
    for(auto const& i : regTeams){ 

        // Itera sobre el mapa de problemas de cada equipo y los suma al resultado dependiendo del estatus
        // Además cuenta los problemas resuletos.
        for(auto const& j : regTeams[i.first].problemsSolved){
            (j.second.status[0] == 'A') ? regTeams[i.first].result += j.second.score : 0; 
            (j.second.status[0] == 'A') ? regTeams[i.first].solved += 1 : 0;
        }

        list.push_back(i.second);
    }
}


// La función recibe los valores de dos equipos y los intercambia
// Referencia: https://www.geeksforgeeks.org/bubble-sort/
void swap(Team *xp, Team *yp){
    Team temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// La función recibe una lista de equipo y las ordena con el algoritmo de bubble sort
// Referencia: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(vector<Team> &list){
   for (int i = 0; i < list.size()-1; i++)      
 
       for (int j = 0; j < list.size()-i-1; j++) 
           // Edge case when both number of problems and points are the same.
           if (list[j].solved == list[j+1].solved && list[j].result == list[j + 1].result && list[j].regNum > list[j+1].regNum){
               swap(&list[j], &list[j+1]);
           }
            // Compara el número de problemas resueltos por los elementos en j y j + 1
           else if (list[j].solved < list[j+1].solved){
              swap(&list[j], &list[j+1]);
           }

           // Si tienen el mismo número de problemas compara el tiempo que tardaron en contestar.
           else if (list[j].solved == list[j+1].solved && list[j].result > list[j + 1].result){
               swap(&list[j], &list[j+1]);
           }      
}

// La función toma un vector como parámetro e imprime los elementos que lo componen.
void display(vector<Team> &list){
    
    for(int i = 0; i < list.size(); i++){

        cout << i + 1 << " - " << list[i].name << " " << list[i].solved << " ";

        if (list[i].result > 0){
            cout << list[i].result << endl;
        }
        else{
            cout << "-" << endl;
        }
    }
}

 