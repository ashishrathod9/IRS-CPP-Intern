#include <sqlite3.h>

int main() {
    sqlite3* db;

    sqlite3_open("test.db", &db);

    // use db later

    sqlite3_close(db);
}
