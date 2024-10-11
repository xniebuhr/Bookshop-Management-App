#pragma once
#include <mysql.h>
#include <sstream>
#include <string>
#include <iostream>
#include <limits>

// Global variables used in all class member functions
extern MYSQL* conn;
extern MYSQL_RES* res_set;
extern MYSQL_ROW row;
extern std::stringstream stmt;
extern const char* q;
extern std::string query;

void initializeDatabase();

void ignoreLine();
