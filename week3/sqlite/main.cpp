#include <iostream>
#include "Database.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "EXAMPLE 1: WITHOUT PREPARED STATEMENTS" << endl;
    cout << "========================================\n" << endl;

    Database db1("users_unsafe.db");
    db1.createTable();

    cout << "\n--- CREATE ---" << endl;
    db1.createUser("Alice Smith", "alice@example.com", 28);
    db1.createUser("Bob Johnson", "bob@example.com", 35);

    cout << "\n--- READ ALL ---" << endl;
    db1.readAllUsers();

    cout << "\n--- UPDATE ---" << endl;
    db1.updateUser(1, "Alice Johnson", "alice.j@example.com", 29);

    cout << "\n--- READ AFTER UPDATE ---" << endl;
    db1.readAllUsers();

    cout << "\n--- DELETE ---" << endl;
    db1.deleteUser(2);

    cout << "\n--- FINAL STATE ---" << endl;
    db1.readAllUsers();

    cout << "\n\n========================================" << endl;
    cout << "EXAMPLE 2: WITH PREPARED STATEMENTS" << endl;
    cout << "========================================\n" << endl;

    Database db2("users_safe.db");
    db2.createTable();

    cout << "\n--- CREATE ---" << endl;
    db2.createUserPre("Carol Williams", "carol@example.com", 42);
    db2.createUserPre("David Brown", "david@example.com", 31);

    cout << "\n--- READ ALL ---" << endl;
    vector<User> users = db2.readAllUsersPre();
    for(const auto& user : users) {
        db2.displayUser(user);
    }

    cout << "\n--- UPDATE ---" << endl;
    db2.updateUserPre(1, "Carol Davis", "carol.d@example.com", 43);

    cout << "\n--- READ AFTER UPDATE ---" << endl;
    users = db2.readAllUsersPre();
    for(const auto& user : users) {
        db2.displayUser(user);
    }

    cout << "\n--- DELETE ---" << endl;
    db2.deleteUserPre(2);

    cout << "\n--- FINAL STATE ---" << endl;
    users = db2.readAllUsersPre();
    for(const auto& user : users) {
        db2.displayUser(user);
    }

    cout << "\n\n========================================" << endl;
    cout << "SQL INJECTION DEMONSTRATION" << endl;
    cout << "========================================\n" << endl;

    cout << "Attempting SQL injection with unsafe method:" << endl;
    string maliciousInput = "Test'); DROP TABLE users; --";
    cout << "Malicious input: " << maliciousInput << endl;
    cout << "(Not executing to avoid breaking the demo)" << endl;

    cout << "\nWith prepared statements, the malicious input is treated as data:" << endl;
    db2.createUserPre(maliciousInput, "safe@test.com", 25);
    cout << "The string is safely inserted as literal text!" << endl;

    return 0;
}
