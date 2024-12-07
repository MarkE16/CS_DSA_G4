#include "hashing.h"
#include <iostream>
#include <limits> // Add this include to fix the error

using namespace std;

void adminDashboard(HashTable &studentTable) {
  while (true) {
    cout << "\n--- Admin Dashboard ---\n";
    cout << "1. Create Student Account\n";
    cout << "2. Display Hash Table\n";
    cout << "3. Logout\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
      string username, password;
      cout << "Enter new student's username: ";
      cin >> username;
      cout << "Enter password: ";
      cin >> password;
      studentTable.insert(username, password);
    } else if (choice == 2) {
      studentTable.display();
    } else if (choice == 3) {
      cout << "Logging out...\n";
      break;
    } else {
      cerr << "Invalid choice! Please try again.\n";
    }
  }
}

void studentLogin(HashTable &studentTable) {
  string username, password;
  cout << "\n--- Student Login ---\n";
  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  string storedPassword = studentTable.get(username);
  if (storedPassword.empty()) {
    cerr << "Error: Username not found.\n";
  } else if (storedPassword == password) {
    cout << "Login successful! Welcome, " << username << ".\n";
  } else {
    cerr << "Error: Incorrect password.\n";
  }
}

int main() {
  HashTable studentTable;
  while (true) {
    cout << "\n--- Course Registration System ---\n";
    cout << "1. Administration Login\n";
    cout << "2. Student Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    // Input validation to prevent infinite loop on invalid input
    if (!cin) {
      cin.clear(); // Clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n'); // Ignore the invalid input
      cerr << "Invalid input! Please enter a valid choice (1, 2, or 3).\n";
      continue;
    }

    if (choice == 1) {
      // Simulate admin login (username/password hardcoded for simplicity)
      string adminUsername, adminPassword;
      cout << "\n--- Admin Login ---\n";
      cout << "Enter admin username: ";
      cin >> adminUsername;
      cout << "Enter admin password: ";
      cin >> adminPassword;

      if (adminUsername == "admin" && adminPassword == "admin123") {
        adminDashboard(studentTable);
      } else {
        cerr << "Error: Invalid admin credentials.\n";
      }
    } else if (choice == 2) {
      studentLogin(studentTable);
    } else if (choice == 3) {
      cout << "Exiting the system. Goodbye!\n";
      break;
    } else {
      cerr << "Invalid choice! Please try again.\n";
    }
  }
  return 0;
}
