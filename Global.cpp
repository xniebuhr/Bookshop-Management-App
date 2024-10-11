#include "Global.h"

MYSQL* conn;
MYSQL_RES* res_set;
MYSQL_ROW row;
std::stringstream stmt;
const char* q;
std::string query;

void initializeDatabase()
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "127.0.0.1", "root", ""/* Add MySQL password here */, ""/* Add Database name here */, 3306, NULL, 0);
}

void ignoreLine()
{
	std::cin.ignore(10000, '\n');
}
