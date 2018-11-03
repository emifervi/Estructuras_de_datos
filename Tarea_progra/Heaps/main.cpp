#include <iostream>
using namespace std;
#include "Priority.h"

int main(){
    Priority myPriority;

    myPriority.push(14);
    myPriority.push(10);
    myPriority.push(8);
    myPriority.push(25);
    myPriority.push(73);
    myPriority.push(5);
    myPriority.push(43);
    myPriority.push(17);
    myPriority.push(43);
    myPriority.push(23);
    
    myPriority.print();

    while(!myPriority.empty()){
        cout << myPriority.top() << " ";
        myPriority.pop();
    }

    return 0;
}