#pragma once
#include <vector>

class Priority{
private:
    bool priority;
    std::vector<int> priorityQueue;
    void swap(int &x, int &y);
    bool compare(int x, int y);
    void arrangeUpwards(std::vector<int> &heap);
    void arrangeDownwards(std::vector<int> &heap);

public:
    Priority();
    Priority(bool priority);
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
    int getData(int pos);
    void print();
};

Priority::Priority(){
    std::vector<int> priorityQueue;
    priority = true;
}

Priority::Priority(bool priority){
    std::vector<int> priorityQueue;
    this->priority = priority;
}

void Priority::swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

bool Priority::compare(int x, int y){
    return priority ? x>y : x<y;
}

void Priority::arrangeUpwards(std::vector<int> &heap){
    int AP = heap.size()-1;
    while(AP >= 1 && compare(heap[AP/2],heap[AP])){
        swap(heap[AP/2], heap[AP]);
        AP = AP / 2;
    }
}

void Priority::push(int data){
    priorityQueue.push_back(data);
    arrangeUpwards(priorityQueue);
}

void Priority::arrangeDownwards(std::vector<int> &heap){

}

void Priority::pop(){
    swap(priorityQueue.front(), priorityQueue.back());
    priorityQueue.erase(priorityQueue.end()-1);

    arrangeDownwards(priorityQueue);
}

int Priority::top(){
    return priorityQueue.front();
}

int Priority::size(){
    return priorityQueue.size();
}

bool Priority::empty(){
    return priorityQueue.empty();
}

/* int Priority::getData(int pos){
    return priorityQueue[pos];
}
void Priority::print(){
    for(int i=0; i < priorityQueue.size(); i++){
        cout << priorityQueue[i] << " ";
    }
    cout << endl;
} */

