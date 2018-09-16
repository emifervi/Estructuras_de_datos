#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct punto{
    int x, y;

    bool operator < (const punto &otro) const{
        if(x == otro.x){
            return y < otro.y;
        }
        return x > otro.x;
    }
};

int main(){
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    priority_queue<punto> pq3;
    int n, dato;

    cin >> n;
    /* for (int i = 0; i < n; i++){
        cin >> dato;
        q.push(dato);
        s.push(dato);
        pq1.push(dato);
        pq2.push(dato);
    }

    cout << "La fila es: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl << "El stack es: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl << "La fila con prioridad es: ";
    while(!pq1.empty()){
        cout << pq1.top() << " ";
        pq1.pop();
    }

    cout << endl << "La fila con prioridad (pq2) es: ";
    while(!pq2.empty()){
        cout << pq2.top() << " ";
        pq2.pop();
    } */

    punto aux;
    for(int i = 0; i < n; i++){
        cin >> aux.x >> aux.y;
        pq3.push(aux);
    }

    cout << "La fila priorizada 3 es: " << endl;
    while(!pq3.empty()){
        cout << pq3.top().x << " , " << pq3.top().y << endl;
        pq3.pop(); 
    }
    cout << endl;
}