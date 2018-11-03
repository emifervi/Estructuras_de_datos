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
    while(AP >= 1 && compare(heap[AP],heap[AP/2])){
        swap(heap[AP/2], heap[AP]);
        AP = AP / 2;
    }
}

void Priority::push(int data){
    priorityQueue.push_back(data);
    arrangeUpwards(priorityQueue);
}

void Priority::arrangeDownwards(std::vector<int> &heap){
    int left;
    int right;
    int highestPriority;

    for(int i = (heap.size()-1/2); i >= 0 ; i--){
        left = 2*i + 1;
        right = 2*i + 2;
         
        // Highest priority between left son and father
        if(left < heap.size() - 1 && compare(heap[left], heap[i])){
            highestPriority = left;
        }
        else{
            highestPriority = i;
        }

        // Highest priority bewteeen rightson and highestPriority
        if(right < heap.size() - 1 && compare(heap[right], heap[highestPriority])){
            highestPriority = right;
        }

        if(highestPriority != i){
            swap(heap[i], heap[highestPriority]);
        }
    }
}

void Priority::pop(){
    swap(priorityQueue.front(), priorityQueue.back());
    priorityQueue.erase(priorityQueue.end()-1);
    

    if(!priorityQueue.empty()){
        arrangeDownwards(priorityQueue);
    }
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

void Priority::print(){
    for(int i=0; i < priorityQueue.size(); i++){
        cout << priorityQueue[i] << " ";
    }
    cout << endl;
}

