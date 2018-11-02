#include <iostream>
using namespace std;
#include "Priority.h"

int main(){
    Priority myPriority(false);

    myPriority.push(14);
    myPriority.print();
    myPriority.push(10);
    myPriority.print();
    myPriority.push(8);
    myPriority.print();
    myPriority.push(25);
    myPriority.print();
    myPriority.push(73);
    myPriority.print();
    myPriority.push(5);
    myPriority.push(43);
    myPriority.print();
    myPriority.push(17);
    myPriority.print();
    myPriority.push(43);
    myPriority.print();
    myPriority.push(23);
    myPriority.print();

    return 0;
}