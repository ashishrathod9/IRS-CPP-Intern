#include <iostream>
#include <sqlite3.h>

using namespace std;

static int createDb(const char* s);
static int createTable(const char* s);

int main() {
    const char* dir = "STUDENTS.db";

    createDb(dir);
    createTable(dir);

    return 0;
}

static int createDb(const char* s) {
    sqlite3* DB;
    int rc = sqlite3_open(s, &DB);

    if (rc) {
        cerr << "Error opening DB: " << sqlite3_errmsg(DB) << endl;
    } else {
        cout << "Database created/opened successfully!" << endl;
    }

    sqlite3_close(DB);
    return rc;
}

static int createTable(const char* s) {
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS GRADES("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "NAME TEXT NOT NULL,"
                 "LNAME TEXT NOT NULL,"
                 "AGE INT NOT NULL,"
                 "ADDRESS CHAR(50),"
                 "GRADE CHAR(1));";

    int rc = sqlite3_open(s, &DB);
    if (rc) {
        cerr << "Error opening DB: " << sqlite3_errmsg(DB) << endl;
        return rc;
    }

    char* messageError = nullptr;
    rc = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &messageError);

    if (rc != SQLITE_OK) {
        cerr << "Error creating table: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Table created successfully!" << endl;
    }

    sqlite3_close(DB);
    return rc;
}
