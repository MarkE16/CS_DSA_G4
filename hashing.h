#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class HashTable {
private:
  static const int TABLE_SIZE = 10; // Size of the hash table
  vector<list<pair<string, string>>> table;

  // Hash function
  int hashFunction(const string &key) const {
    int hash = 0;
    for (char ch : key) {
      hash += ch;
    }
    return hash % TABLE_SIZE;
  }

public:
  HashTable() : table(TABLE_SIZE) {}

  // Insert a new user
  void insert(const string &username, const string &password) {
    int index = hashFunction(username);
    // Check if username already exists
    for (auto &entry : table[index]) {
      if (entry.first == username) {
        cerr << "Error: Username '" << username << "' already exists.\n";
        return;
      }
    }
    table[index].emplace_back(username, password);
  }

  // Retrieve password for a username
  string get(const string &username) const {
    int index = hashFunction(username);
    for (const auto &entry : table[index]) {
      if (entry.first == username) {
        return entry.second;
      }
    }
    return ""; // Username not found
  }

  // Display the hash table
  void display() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
      cout << "Index " << i << ": ";
      for (const auto &entry : table[i]) {
        cout << "[" << entry.first << ", " << entry.second << "] -> ";
      }
      cout << "nullptr\n";
    }
  }
};

#endif
