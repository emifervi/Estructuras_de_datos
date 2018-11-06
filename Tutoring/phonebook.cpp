#include <iostream>
#include <map>
using namespace std;

void find(int phone, map<int, string> &phonebook){
    cin >> phone;
    cout << (phonebook.count(phone) ? phonebook[phone] : "not found") << endl;
}

void del(int phone, map<int, string> &phonebook){
    cin >> phone;
    phonebook.count(phone) ? phonebook.erase(phone) : 0;
}

void add(int phone, string name, map<int, string> &phonebook){
    cin >> phone >> name;
    phonebook[phone] = name;
}

int main(){
    int n, phone;
    cin >> n;

    string command, name;
    map<int, string> phonebook;

    for(n; n > 0; n--){
        cin >> command;

        if (command == "add")
            add(phone, name, phonebook);
        
        if (command == "find")
            find(phone, phonebook);
        
        if(command == "del")
            del(phone, phonebook);
    }

    return 0;
}