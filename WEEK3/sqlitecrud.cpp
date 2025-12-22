#include<iostream>
#include<sqlite3.h>

using namespace std;

int main()
{
	sqlite3* db=nullptr;
	sqlite3_stmt* stmt=nullptr;
	sqlite3_open("school.db",&db);
	const char* sql="CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT, "
        "age INTEGER);";

	if (sqlite3_prepare_v2(db,sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare failed (SELECT): "
                  << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return 1;
    }
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	const char * sql2="INSERT INTO students (name, age) VALUES (?, ?);";
	if (sqlite3_prepare_v2(db, sql2, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare failed (SELECT): "
                  << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return 1;
         }
	sqlite3_bind_text(stmt,1,"Ashish",-1,SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt,2,20);
	sqlite3_step(stmt);
        sqlite3_finalize(stmt);

	const char * sql3="SELECT id,name,age  FROM students;";
        if (sqlite3_prepare_v2(db, sql3, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare failed (SELECT): "
                  << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return 1;
         }

	while (sqlite3_step(stmt)!=SQLITE_DONE)
	{
		int id = sqlite3_column_int(stmt, 0);
        const char* name =
            reinterpret_cast<const char*>(
                sqlite3_column_text(stmt, 1));
        int age = sqlite3_column_int(stmt, 2);

        std::cout << id << " | " << name << " | " << age;
	}

	sqlite3_finalize(stmt);

	return 0;

}
