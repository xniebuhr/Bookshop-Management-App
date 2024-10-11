#pragma once
#include <iostream>

class Purchase
{

private:
	int id;
	std::string bookTitle;
	std::string supplier;
	int quantity;
	std::string eta;
	bool arrived;

public:
	void newOrder();
	void updateOrder();
	void cancelOrder();
	void searchOrder();
	void printTable();

};
