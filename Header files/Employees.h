#pragma once
#include <string>

class Employee
{

private:
	int id;
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string phone;
	long int salary;
	bool isManager;

public:
	void addEmployee();
	void updateEmployee();
	void removeEmployee();
	void searchEmployee();
	void printTable();

};
