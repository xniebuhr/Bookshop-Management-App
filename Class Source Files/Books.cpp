#include "Books.h"
#include "Global.h"

void Book::addBook()
{
	while (true)
	{
		ignoreLine();
		std::cout << "Enter the book title: ";
		std::getline(std::cin, name);

		std::cout << "Enter the author's name: ";
		std::getline(std::cin, author);

		std::cout << "Enter the price of the boook: ";
		std::cin >> price;

		std::cout << "Enter the quantity received: ";
		std::cin >> quantity;

		stmt.str("");
		stmt << "INSERT INTO Books(name, author, price, quantity) VALUES ('" << name << "','" << author << "'," << price << "," << quantity << ");";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if (!(res_set))
		{
			std::cout << "\nBook added successfully!\n\n";
		}
		else
		{
			std::cout << "Entry error, contact technical team\n\n";
		}
		
		while (true)
		{
			std::cout << "Enter 1 to add another book\n";
			std::cout << "Enter 2 to return to the Book Menu\n";
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

void Book::updateBook()
{
	while (true)
	{
		std::cout << "Enter the ID of the book you would like to update: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Books;";
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
			std::cout << "Enter the updated title: ";
			std::getline(std::cin, name);

			std::cout << "Enter the updated author: ";
			std::getline(std::cin, author);

			std::cout << "Enter the updated price: ";
			std::cin >> price;

			std::cout << "Enter the updated quantity: ";
			std::cin >> quantity;

			stmt.str("");
			stmt << "UPDATE Books SET name = '" << name << "', author = '" << author << "', price = " << price << ", quantity = " << quantity << " WHERE ID = " << id << ';';
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			res_set = mysql_store_result(conn);

			if (!(res_set))
			{
				std::cout << "\nBook updated successfully!\n\n";
			}
			else
			{
				std::cout << "Update error, contact technical team\n\n";
			}
		}

		while (true)
		{
			std::cout << "Enter 1 to update another book\n";
			std::cout << "Enter 2 to return to the Book Menu\n";
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

void Book::deleteBook()
{
	while (true)
	{
		std::cout << "Enter the ID of the book to remove: ";
		std::cin >> id;
		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Books;";
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
			stmt << "DELETE FROM Books WHERE ID = " << id << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			std::cout << "\nBook removed\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to delete another book\n";
			std::cout << "Enter 2 to return to the Book Menu\n";
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

void Book::searchBook()
{
	while (true)
	{
		std::cout << "\nEnter the ID of the book you would like to search for: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT * FROM Books WHERE ID = " << id << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if ((row = mysql_fetch_row(res_set)) != NULL)
		{
			std::cout << "\nThe name of the book is " << row[1] << '\n';
			std::cout << "The author is " << row[2] << '\n';
			std::cout << "The price of the book is $" << row[3] << '\n';
			std::cout << "There are " << row[4] << " books in stock\n\n";
		}
		else
		{
			std::cout << "\nNo record found" << "\n\n";
		}
		
		while (true)
		{
			std::cout << "Enter 1 to search for another book\n";
			std::cout << "Enter 2 to return to the Book Menu\n";
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

void Book::printTable()
{
	query = "SELECT * FROM Books;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "\nBook ID: " << row[0] << '\n';
		std::cout << "Title: " << row[1] << '\n';
		std::cout << "Author: " << row[2] << '\n';
		std::cout << "Price: $" << row[3] << '\n';
		std::cout << "Quantity: " << row[4] << "\n\n";
	}
	
	std::cout << "Press Enter to go back to the Book Menu\n";
	ignoreLine();
	std::cin.get();
	system("cls");
}
