#include "Purchases.h"
#include "Global.h"

void Purchase::newOrder()
{
	while (true)
	{
		ignoreLine();
		std::cout << "Enter the title of the book ordered: ";
		std::getline(std::cin, bookTitle);

		std::cout << "Enter the name of the supplier: ";
		std::getline(std::cin, supplier);

		std::cout << "Enter the quantity ordered: ";
		std::cin >> quantity;

		ignoreLine();
		std::cout << "Enter the estimated time of arrival: ";
		std::getline(std::cin, eta);

		stmt.str("");
		stmt << "INSERT INTO Purchases (bookTitle, supplier, quantity, eta, arrived) VALUES ('" << bookTitle << "','" << supplier << "'," << quantity << ",'" << eta << "',FALSE);";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if (!(res_set))
		{
			std::cout << "\nOrder added successfully!\n\n";
		}
		else
		{
			std::cout << "Entry error, contact technical team\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to add another order\n";
			std::cout << "Enter 2 to return to the Purchase Menu\n";
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

void Purchase::updateOrder()
{
	while (true)
	{
		std::cout << "Enter the ID of the purchase to update: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Purchases;";
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
			std::cout << "Enter the updated title of the book ordered: ";
			std::getline(std::cin, bookTitle);

			std::cout << "Enter the updated name of the supplier: ";
			std::getline(std::cin, supplier);

			std::cout << "Enter the updated quantity ordered: ";
			std::cin >> quantity;

			ignoreLine();
			std::cout << "Enter the updated eta: ";
			std::getline(std::cin, eta);

			char c;
			std::cout << "Has the order arrived yet (y/n)? ";
			std::cin >> c;
			if (c == 'y')
			{
				arrived = true;
			}
			else
			{
				arrived = false;
			}

			stmt.str("");
			stmt << "UPDATE Purchases SET bookTitle='" << bookTitle << "',supplier='" << supplier << "',quantity=" << quantity << ",eta='" << eta << "',arrived=" << arrived << " WHERE ID = " << id << ';';
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
			std::cout << "Enter 1 to update another purchase\n";
			std::cout << "Enter 2 to return to the Purchase Menu\n";
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

void Purchase::cancelOrder()
{
	while (true)
	{
		std::cout << "Enter the ID of the purchase to remove: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Purchases;";
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
			stmt << "DELETE FROM Purchases WHERE ID = " << id << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			std::cout << "\nPurchase removed\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to cancel another purchase\n";
			std::cout << "Enter 2 to return to the Purchase Menu\n";
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

void Purchase::searchOrder()
{
	while (true)
	{
		std::cout << "\nEnter the ID of the order you would like to search for: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT * FROM Purchases WHERE ID = " << id << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if ((row = mysql_fetch_row(res_set)) != NULL)
		{
			std::cout << "\nThe book title is " << row[1] << '\n';
			std::cout << "The supplier is " << row[2] << '\n';
			std::cout << row[3] << " books were ordered" << '\n';
			std::cout << "The estimated date of arrival is " << row[4] << '\n';
			if (std::stoi(row[5]) != 0)
			{
				std::cout << "The order has arrived\n\n";
			}
			else
			{
				std::cout << "The order has not arrived\n\n";
			}
		}
		else
		{
			std::cout << "\nNo record found" << "\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to search for another purchase\n";
			std::cout << "Enter 2 to return to the Purchase Menu\n";
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

void Purchase::printTable()
{
	query = "SELECT * FROM Purchases;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "\nPurchase ID: " << row[0] << '\n';
		std::cout << "Book title: " << row[1] << '\n';
		std::cout << "Supplier: " << row[2] << '\n';
		std::cout << "Quantity: " << row[3] << '\n';
		std::cout << "Estimated date of arrival: " << row[4] << '\n';
		if (std::stoi(row[5]) == 0)
		{
			std::cout << "Arrived: No\n\n";
		}
		else
		{
			std::cout << "Arrived: Yes\n\n";
		}
	}

	std::cout << "Press Enter to go back to the Purchase Menu\n";
	ignoreLine();
	std::cin.get();
	system("cls");
}
