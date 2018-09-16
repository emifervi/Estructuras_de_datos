#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int calculator(int y, int x, string operation){
  if (operation == "+"){
    return y + x;
  }
  else if (operation == "-"){
    return y - x;
  }
  else if (operation == "*"){
    return y * x;
  }
  else if (operation == "/"){
    return y / x;
  }
  else{
    return -1;
  }
}

void stackOperations(stack<int>& opStack, int y, int x, string d, int& result){
  x = opStack.top();
  opStack.pop();

  y = opStack.top();
  opStack.pop();

  result = calculator(y, x, d);
  opStack.push(result);
}
void emptyStack(stack<int>& opStack){
  while(!opStack.empty()){
    opStack.pop();
  }
}

void queueOperation(queue<int>& opQueue, int y, int x, string d, int& result){
  x = opQueue.front();
  opQueue.pop();

  y = opQueue.front();
  opQueue.pop();

  result = calculator(y, x, d);
  opQueue.push(result);
}
void emptyQueue(queue<int>& opQueue){
  while(!opQueue.empty()){
    opQueue.pop();
  }
}

void priorityOperation(priority_queue<int, vector<int>, greater<int>>& priorityOp, int y, int x, string d, int& result){
  x = priorityOp.top();
  priorityOp.pop();

  y = priorityOp.top();
  priorityOp.pop();

  result = calculator(y, x, d);
  priorityOp.push(result);
}
void emptyPriority(priority_queue<int, vector<int>, greater<int>>& priorityOp){
  while (!priorityOp.empty()){
    priorityOp.pop();
  }
}

int main() {
  string d, data;
  int x, y, stackRes, queueRes, priorityRes;
  stack<int> opStack;
  queue<int> opQueue;
  priority_queue<int, vector<int>, greater<int> > priorityOp;
  
  getline(cin, data);

  while(data != "#"){
    
    stringstream ss;
    ss << data;
    
    while (ss >> d){

      // Make operation based on the sign
      if(d == "+" || d == "-" || d == "*" || d == "/"){
        stackOperations(opStack, y, x, d, stackRes);
        queueOperation(opQueue, y, x, d, queueRes);
        priorityOperation(priorityOp, y, x, d, priorityRes);
      }

      // Push numeric elements
      else{
        opStack.push(stoi(d));
        opQueue.push(stoi(d));
        priorityOp.push(stoi(d));
      }
    }

    // Print results, get new operations and empty structures.
    cout << stackRes << " " << queueRes << " " << priorityRes << endl;
    getline(cin, data);
    emptyStack(opStack);
    emptyQueue(opQueue);
    emptyPriority(priorityOp);
  }

  return 0;
}