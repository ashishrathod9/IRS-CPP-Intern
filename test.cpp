#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3* db;
    if (sqlite3_open("test.db", &db) == SQLITE_OK) {
        std::cout << "SQLite OK\n";
        sqlite3_close(db);
    }
    return 0;
}
