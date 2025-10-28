#include "sqlite3.h"
#include <iostream>

sqlite3* db;

bool OpenDatabase(const char* dbFileName, const char* tableName)
{
	int rc = sqlite3_open(dbFileName, &db);
	if (rc)
	{
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
		return false;
	}
	
	std::string sqlCreateTable =
		"CREATE TABLE IF NOT EXISTS" + std::string(tableName) + R"( (
			ID INTEGER PRIMARY KEY AUTOINCREMENT,
			Name TEXT NOT NULL,
			Age INTEGER NOT NULL,
			Grade REAL NOT NULL
	);)";

	char* errMsg = nullptr;
	rc = sqlite3_exec(db, sqlCreateTable.c_str(), nullptr, nullptr, &errMsg);
	if (rc != SQLITE_OK)
	{
		std::cerr << "SQL error " << tableName << " : " << errMsg << std::endl;
		sqlite3_free(errMsg);
		sqlite3_close(db);
		return false;
	}
	std::cout << "Database opened and table " << dbFileName << " ensured." << tableName << "ensured" << std::endl;
	return true;

}

