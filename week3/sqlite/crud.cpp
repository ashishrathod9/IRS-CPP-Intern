#include <sqlite3.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct User {
    int id;
    string name;
    string email;
    int age;
};

class Database {
private:
    sqlite3* db;

    void handleError(const string &operation, const char* errMsg = "prepare err") {
        cerr << operation << " failed: " << errMsg << endl;
    }

public:
    Database(const string &dbname) : db(nullptr) {
        int rc = sqlite3_open(dbname.c_str(), &db);

        if(rc != SQLITE_OK) {
            cerr << "Cannot open Database: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            db = nullptr;
        }
    }

    ~Database() {
        if(db) sqlite3_close(db);
    }

    bool createTable() {
        const char* sql =
            "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT NOT NULL,"
            "email TEXT NOT NULL,"
            "age INTEGER);";

        char* errMsg = nullptr;
        int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

        if(rc != SQLITE_OK) {
            handleError("create table", errMsg);
            sqlite3_free(errMsg);
            return false;
        }

        cout << "Table created successfully" << endl;
        return true;
    }

    bool createUser(const string &name, const string &email, int age) {
        stringstream ss;
        ss << "INSERT INTO users (name, email, age) VALUES('"
           << name << "', '" << email << "', " << age << ");";

        string sql = ss.str();
        char* errMsg = nullptr;

        int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

        if(rc != SQLITE_OK) {
            handleError("INSERT", errMsg);
            sqlite3_free(errMsg);
            return false;
        }

        cout << "User created with id: " << sqlite3_last_insert_rowid(db) << endl;
        return true;
    }

    bool createUserPre(const string &name, const string &email, int age) {
        const char* sql = "INSERT INTO users (name, email, age) VALUES (?,?,?);";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

        if(rc != SQLITE_OK) {
            handleError("prepare INSERT");
            return false;
        }

        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 3, age);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(rc != SQLITE_DONE) {
            handleError("execute INSERT");
            return false;
        }

        cout << "User created with id: " << sqlite3_last_insert_rowid(db) << endl;
        return true;
    }

    static int readCallback(void* data, int argc, char** argv, char** colNames) {
        cout << "id: " << (argv[0] ? argv[0] : "NULL")
             << ", name: " << (argv[1] ? argv[1] : "NULL")
             << ", email: " << (argv[2] ? argv[2] : "NULL")
             << ", age: " << (argv[3] ? argv[3] : "NULL")
             << endl;
        return 0;
    }

    bool readAllUsers() {
        const char* sql = "SELECT id, name, email, age FROM users;";
        char* errMsg = nullptr;

        int rc = sqlite3_exec(db, sql, readCallback, nullptr, &errMsg);

        if(rc != SQLITE_OK) {
            handleError("SELECT", errMsg);
            sqlite3_free(errMsg);
            return false;
        }

        return true;
    }

    vector<User> readAllUsersPre() {
        vector<User> users;
        const char* sql = "SELECT id, name, email, age FROM users;";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if(rc != SQLITE_OK) {
            handleError("prepare SELECT");
            return users;
        }

        while((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            User user;
            user.id = sqlite3_column_int(stmt, 0);
            user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            user.email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            user.age = sqlite3_column_int(stmt, 3);
            users.push_back(user);
        }

        sqlite3_finalize(stmt);
        return users;
    }

    bool updateUser(int id, const string &name, const string &email, int age) {
        stringstream ss;
        ss << "UPDATE users SET name = '" << name
           << "', email = '" << email
           << "', age = " << age
           << " WHERE id = " << id << ";";

        string sql = ss.str();
        char* errMsg = nullptr;

        int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

        if(rc != SQLITE_OK) {
            handleError("UPDATE", errMsg);
            sqlite3_free(errMsg);
            return false;
        }

        int changes = sqlite3_changes(db);
        if(changes > 0) {
            cout << "User updated successfully" << endl;
            return true;
        } else {
            cout << "No user found with id: " << id << endl;
            return false;
        }
    }

    bool updateUserPre(int id, const string &name, const string &email, int age) {
        const char* sql = "UPDATE users SET name = ?, email = ?, age = ? WHERE id = ?;";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

        if(rc != SQLITE_OK) {
            handleError("prepare UPDATE");
            return false;
        }

        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 3, age);
        sqlite3_bind_int(stmt, 4, id);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(rc != SQLITE_DONE) {
            handleError("execute update");
            return false;
        }

        int changes = sqlite3_changes(db);
        if(changes > 0) {
            cout << "User updated successfully" << endl;
            return true;
        } else {
            cout << "No user found with id: " << id << endl;
            return false;
        }
    }

    bool deleteUser(int id) {
        stringstream ss;
        ss << "DELETE FROM users WHERE id = " << id << ";";

        string sql = ss.str();
        char* errMsg = nullptr;

        int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

        if(rc != SQLITE_OK) {
            handleError("DELETE", errMsg);
            sqlite3_free(errMsg);
            return false;
        }

        int changes = sqlite3_changes(db);
        if(changes > 0) {
            cout << "User deleted successfully" << endl;
            return true;
        } else {
            cout << "No user found with id: " << id << endl;
            return false;
        }
    }

    bool deleteUserPre(int id) {
        const char* sql = "DELETE FROM users WHERE id = ?;";
        sqlite3_stmt* stmt;

        int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

        if(rc != SQLITE_OK) {
            handleError("prepare DELETE");
            return false;
        }

        sqlite3_bind_int(stmt, 1, id);

        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(rc != SQLITE_DONE) {
            handleError("execute delete");
            return false;
        }

        int changes = sqlite3_changes(db);
        if(changes > 0) {
            cout << "User deleted successfully" << endl;
            return true;
        } else {
            cout << "No user found with id: " << id << endl;
            return false;
        }
    }

    void displayUser(const User& user) {
        cout << "id: " << user.id
             << ", name: " << user.name
             << ", email: " << user.email
             << ", age: " << user.age << endl;
    }
};

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
