#include "Database.h"
#include <iostream>
#include <sstream>

using namespace std;

void Database::handleError(const string &operation, const char* errMsg) {
    cerr << operation << " failed: " << errMsg << endl;
}

Database::Database(const string &dbname) : db(nullptr) {
    int rc = sqlite3_open(dbname.c_str(), &db);

    if(rc != SQLITE_OK) {
        cerr << "Cannot open Database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        db = nullptr;
    }
}

Database::~Database() {
    if(db) sqlite3_close(db);
}

bool Database::createTable() {
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

bool Database::createUser(const string &name, const string &email, int age) {
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

bool Database::createUserPre(const string &name, const string &email, int age) {
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

int Database::readCallback(void* data, int argc, char** argv, char** colNames) {
    cout << "id: " << (argv[0] ? argv[0] : "NULL")
         << ", name: " << (argv[1] ? argv[1] : "NULL")
         << ", email: " << (argv[2] ? argv[2] : "NULL")
         << ", age: " << (argv[3] ? argv[3] : "NULL")
         << endl;
    return 0;
}

bool Database::readAllUsers() {
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

vector<User> Database::readAllUsersPre() {
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

bool Database::updateUser(int id, const string &name, const string &email, int age) {
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

bool Database::updateUserPre(int id, const string &name, const string &email, int age) {
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

bool Database::deleteUser(int id) {
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

bool Database::deleteUserPre(int id) {
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

void Database::displayUser(const User& user) {
    cout << "id: " << user.id
         << ", name: " << user.name
         << ", email: " << user.email
         << ", age: " << user.age << endl;
}
