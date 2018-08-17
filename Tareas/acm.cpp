#include <iostream>
#include <map>
using namespace std;

struct Team{
    string name;
    map<string, int> problemsSolved;
    int result;

    Team(){
        name = "";
        result = 0;
    }    

    Team(string name){
        this->name = name;
        this->result = 0;
    }
};

int main(){
    int numTeams, numProblems, numSolns;

    cin >> numTeams >> numProblems;

    map<string, Team> teamMap;

    for (int i = 0; i < numTeams; i++){
        string teamName;
        cin >> teamName;
        // Recibe el nombre del equipo, lo pasa como llave y como valor en el mapa
        teamMap[teamName] = Team(teamName);
    }

    cin >> numSolns;

    for(int i = 0; i < numSolns; i++){
        // Recibe un nombre de equipo, problema resuelto, tiempo tardado y
        // si fue aceptado o no
        string teamName, problemName, probStatus;
        int iTiempo;

        cin >> teamName >> problemName >> iTiempo >> probStatus;
        
        if(teamMap[teamName].problemsSolved.count(problemName)){
            teamMap[teamName].problemsSolved[problemName] += (probStatus[0] == 'A') ? iTiempo : 20;
        }
        else{
            teamMap[teamName].problemsSolved[problemName] = (probStatus[0] == 'A') ? iTiempo : 20;
        }
    }


    // Itera sobre cada equipo en el mapa imprime el nombre y tamaño
    for(auto const& i : teamMap){ 

      cout << i.first << " " << teamMap[i.first].problemsSolved.size() << " ";
      
      // Itera sobre el mapa de problemas de cada equipo y los suma al resultado
      // por último imprime el resultado si es mayor a 0 si no imprime un guión
      for(auto const& j : teamMap[i.first].problemsSolved){
            teamMap[i.first].result += j.second;
      }
      
      (teamMap[i.first].result > 0) ? cout << teamMap[i.first].result << endl : cout << " -" << endl;
    }

    return 0;
}


