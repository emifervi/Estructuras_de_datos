#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Register{
    string name;
    int age;

    bool operator < (const Register &otro) const{
        if(age == otro.age){
            return name < otro.name;
        }
        age < otro.age;
    }
};

void fillGraph(map<string, vector<Register>>  &m, int n){
    string father;
    Register son; 

    for(int i = 0; i < n; i++){
        cout << "Inserta nombre del padre" << endl;
        cin >> father;
        cout << "Inserta nombre y edad del hijo" << endl; 
        cin >> son.name >> son.age;
        m[father].push_back(son);
    }
}

void printGraph(const map<string, vector<Register>> m){
    for(auto father: m){
        cout << father.first << ": ";
        for(auto son: father.second){
            cout << "(" << son.name << " " << son.age << "), " ;
        }
        cout << endl;
    }
}

void BFS(const map<string, <vector<Register>> m){
    priority_queue <Register> fila;
    Register berny;
    berny.age = 100;
    berny.name = "Berny";

    fila.push_back(berny);

    while(!fila.empty()){
        
    }
}

int main(){
    int n;
    
    cout << "Incerte número de de inputs" << endl;
    cin >> n;

    map<string, vector<Register>> m;
    fillGraph(m, n);
    printGraph(m);
}

/**
 4
 Ray Jaime 40
 Jaime Pepe 17
 Ray Marcos 75
 Berny Ray 20
 */