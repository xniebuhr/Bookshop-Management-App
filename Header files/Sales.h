#pragma once
#include <iostream>

class Sale
{

private:
	int id;
	std::string book;
	std::string buyer;
	int price;

public:
	void newSale();
	void updateSale();
	void cancelSale();
	void searchSale();
	void printTable();

};
