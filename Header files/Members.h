#pragma once
#include <string>

class Member
{

private:
	int id;
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string phone;

public:
	void addMember();
	void updateMember();
	void removeMember();
	void searchMember();
	void printTable();
};
