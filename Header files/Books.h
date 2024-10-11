#pragma once
#include <string>
#include <iostream>

class Book
{

private:
	int id;
	std::string name;
	std::string author;
	int price;
	int quantity;

public:
	void addBook();
	void updateBook();
	void deleteBook();
	void searchBook();
	void printTable();

};
