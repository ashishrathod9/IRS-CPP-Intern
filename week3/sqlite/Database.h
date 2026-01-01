#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
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

    void handleError(const string &operation, const char* errMsg = "prepare err");

public:
    Database(const string &dbname);

    ~Database();

    bool createTable();
    bool createUser(const string &name, const string &email, int age);

    bool createUserPre(const string &name, const string &email, int age);

    static int readCallback(void* data, int argc, char** argv, char** colNames);

    bool readAllUsers();

    vector<User> readAllUsersPre();

    bool updateUser(int id, const string &name, const string &email, int age);

    bool updateUserPre(int id, const string &name, const string &email, int age);

    bool deleteUser(int id);

    bool deleteUserPre(int id);

    void displayUser(const User& user);
};

#endif // DATABASE_H
