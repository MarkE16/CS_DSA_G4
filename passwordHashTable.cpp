#include <iostream>
#include <string>
#include <vector>
#include "passwordHashTable.h"
using namespace std;

    int HashTable::Hashfunction(string key){
        //add code to convert string into an int I belive//
        return key % size;
    }
    
    void HashTable::insert(const string& key, const string& value){
        //all functions need this line of code to get the key value from string//
        int index = Hashfunction(key);
        
        //might need more code to check for if key is alrdy taken??//
        table[index] = Users(key, value)
        
    }
    
    //if low on time might not need to search but if we have a delete function
    //then we probably need a search function i presume??//
    string HashTable::search(const string& key){
        int index = Hashfunction(key);
        
        //code to find where the information is at
        
    }
    
    //might not need a remove function for passwords as we'd only want this
    //if deleting a users account or changing password??(only saying this
    //for time wise but if we have time do remove function)//
    void HashTable::remove(const string& key){
        int index = Hashfunction(key);
        
        //add code to remove; find the key and do something with mod??
        
    }
    
    void HashTable::display(const string& key){
        //if we add a way to see if key is in use might need to update this code//
        for(int i=0; i<size; i++){
            cout << "Username: " << Users[i].key << endl
            << "Password: " << users[i].value << endl;
        }
    }
