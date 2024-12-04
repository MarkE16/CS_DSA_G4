#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HashTable{
    private:
        struct Userinfo{ //idk what to name can rename the struct
            string key;
            string value;
            //constructor to populate key and value in one line
            Userinfo(string k, string v) : key(k), value(v) {}
        };
        
    
    
    public:
        void insert();
        string search();
        void remove();
        void display();
}
