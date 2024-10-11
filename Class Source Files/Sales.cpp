#include "Sales.h"
#include "Global.h"

void Sale::newSale()
{
	while (true)
	{
		ignoreLine();
		std::cout << "Enter the title of the book sold: ";
		std::getline(std::cin, book);

		std::cout << "Enter the name of the buyer: ";
		std::getline(std::cin, buyer);

		std::cout << "Enter the price of the book: ";
		std::cin >> price;

		stmt.str("");
		stmt << "INSERT INTO Sales (book, buyer, price) VALUES ('" << book << "','" << buyer << "'," << price << ");";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if (!(res_set))
		{
			std::cout << "\Sale added successfully!\n\n";
		}
		else
		{
			std::cout << "Entry error, contact technical team\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to add another sale\n";
			std::cout << "Enter 2 to return to the Sale Menu\n";
			std::string choice;
			std::cin >> choice;

			if (choice == "1")
			{
				break;
			}
			else if (choice == "2")
			{
				system("cls");
				return;
			}
			else
			{
				std::cout << "Invalid input\n";
			}
		}
	}
}

void Sale::updateSale()
{
	while (true)
	{
		std::cout << "Enter the ID of the sale to update: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Sales;";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);
		row = mysql_fetch_row(res_set);

		int max_id = row[0] ? std::stoi(row[0]) : 0;
		mysql_free_result(res_set);

		if (id > max_id || id <= 0)
		{
			std::cout << "\nID is not valid\n\n";
		}
		else
		{
			ignoreLine();
			std::cout << "Enter the updated title of the book sold: ";
			std::getline(std::cin, book);

			std::cout << "Enter the updated name of the buyer: ";
			std::getline(std::cin, buyer);

			std::cout << "Enter the updated price of the book: ";
			std::cin >> price;

			stmt.str("");
			stmt << "UPDATE Sales SET book='" << book << "',buyer='" << buyer << "',price=" << price << " WHERE ID = " << id << ';';
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			res_set = mysql_store_result(conn);

			if (!(res_set))
			{
				std::cout << "\nPurchase updated successfully!\n\n";
			}
			else
			{
				std::cout << "Update error, contact technical team\n\n";
			}
		}

		while (true)
		{
			std::cout << "Enter 1 to update another sale\n";
			std::cout << "Enter 2 to return to the Sale Menu\n";
			std::string choice;
			std::cin >> choice;

			if (choice == "1")
			{
				break;
			}
			else if (choice == "2")
			{
				system("cls");
				return;
			}
			else
			{
				std::cout << "Invalid input\n";
			}
		}
	}
}

void Sale::cancelSale()
{
	while (true)
	{
		std::cout << "Enter the ID of the sale to remove: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Sales;";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);
		row = mysql_fetch_row(res_set);

		int max_id = row[0] ? std::stoi(row[0]) : 0;
		mysql_free_result(res_set);

		if (id > max_id || id <= 0)
		{
			std::cout << "\nID is not valid\n\n";
		}
		else
		{
			stmt.str("");
			stmt << "DELETE FROM Sales WHERE ID = " << id << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			std::cout << "\Sale removed\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to cancel another sale\n";
			std::cout << "Enter 2 to return to the Sale Menu\n";
			std::string choice;
			std::cin >> choice;
			if (choice == "1")
			{
				break;
			}
			else if (choice == "2")
			{
				system("cls");
				return;
			}
			else
			{
				std::cout << "Invalid input\n";
			}
		}
	}
}

void Sale::searchSale()
{
	while (true)
	{
		std::cout << "\nEnter the ID of the sale you would like to search for: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT * FROM Sales WHERE ID = " << id << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if ((row = mysql_fetch_row(res_set)) != NULL)
		{
			std::cout << "\nThe book bought is " << row[1] << '\n';
			std::cout << "The buyer is " << row[2] << '\n';
			std::cout << "The price is $" << row[3] << "\n\n";
		}
		else
		{
			std::cout << "\nNo record found" << "\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to search for another sale\n";
			std::cout << "Enter 2 to return to the Sale Menu\n";
			std::string choice;
			std::cin >> choice;
			if (choice == "1")
			{
				break;
			}
			else if (choice == "2")
			{
				system("cls");
				return;
			}
			else
			{
				std::cout << "Invalid input\n";
			}
		}
	}
}

void Sale::printTable()
{
	query = "SELECT * FROM Sales;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "\nSale ID: " << row[0] << '\n';
		std::cout << "Book bought: " << row[1] << '\n';
		std::cout << "Buyer: " << row[2] << '\n';
		std::cout << "Price: $" << row[3] << "\n\n";
	}

	std::cout << "Press Enter to go back to the Purchase Menu\n";
	ignoreLine();
	std::cin.get();
	system("cls");
}
