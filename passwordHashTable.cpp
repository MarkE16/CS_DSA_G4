#include <iostream>
#include <string>
#include <vector>
#include "passwordHashTable.h"
using namespace std;

    //precondition: parameter contains username of type string
    //postcondition: an int returned
    int HashTable::Hashfunction(string key){
        //add code to convert string into an int I belive//
        return key % size;
    }

    //precondition: username and password are passed as arguments
    //postcondition: username and password are stored at the hashed index in the vector?
    void HashTable::insert(const string& key, const string& value){
        //all functions need this line of code to get the key value from string//
        int index = Hashfunction(key);
        
        //might need more code to check for if key is alrdy taken??//
        table[index] = Users(key, value)
        
    }

    //precondition: username is passed as an argument
    //postcondition: returns a string (the password?)
    //if low on time might not need to search but if we have a delete function
    //then we probably need a search function i presume??//
    string HashTable::search(const string& key){
        int index = Hashfunction(key);
        
        //code to find where the information is at
        
    }

    //precondition: username is passed as an argument
    //postcondition: key-value pair should be "deleted"
    //might not need a remove function for passwords as we'd only want this
    //if deleting a users account or changing password??(only saying this
    //for time wise but if we have time do remove function)//
    void HashTable::remove(const string& key){
        int index = Hashfunction(key);
        
        //add code to remove; find the key and do something with mod??
        
    }

    //precondition: username is passed as an argument?
    //postcondition: all vector values are printed out (for testing purposes?)
    void HashTable::display(const string& key){
        //if we add a way to see if key is in use might need to update this code//
        for(int i=0; i<size; i++){
            cout << "Username: " << Users[i].key << endl
            << "Password: " << Users[i].value << endl;
        }
    }
