#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HashTable{
    private:
        struct Userinfo{ //idk what to name can rename the struct//
            string key;
            string value;
            
            //code to check if key is taken??? or if short on time dont need
            
            //constructor to populate key and value in one line
            Userinfo(string k, string v) : key(k), value(v) {}
        };
        
        int size;
        int Hashfunction(string key);
        //
        vector<Userinfo> Users;
    
    public:
        //all const as it shouldn't change the values, but if run into issues
        //can get rid of const, just make sure values aren't changed.//
        
        //We techinquely also do not need & to reference but I think it is better
        //practice storage wise if the program were to get big
        //(for our purposes they arent)//
        
        //constructor for the hashtable
        HashTable(int tableSize);
        void insert(const string& key, const string& value);
        string search(const string& key);
        void remove(const string& key);
        void display();
}
