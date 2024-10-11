#include "Members.h"
#include "Global.h"

void Member::addMember()
{
	while (true)
	{
		ignoreLine();
		std::cout << "Enter the member's name: ";
		std::getline(std::cin, name);

		std::cout << "Enter the member's address: ";
		std::getline(std::cin, address);

		std::cout << "Enter the city: ";
		std::getline(std::cin, city);

		std::cout << "Enter the state: ";
		std::getline(std::cin, state);

		std::cout << "Enter the member's phone number: ";
		std::getline(std::cin, phone);

		stmt.str("");
		stmt << "INSERT INTO Members (name, address, city, state, phone) VALUES ('" << name << "','" << address << "','" << city << "','" << state << "','" << phone << "');";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if (!(res_set))
		{
			std::cout << "\nMember added successfully!\n\n";
		}
		else
		{
			std::cout << "Entry error, contact technical team\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to add another member\n";
			std::cout << "Enter 2 to return to the Member Menu\n";
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

void Member::updateMember()
{
	while (true)
	{
		std::cout << "Enter the ID of the member to update: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Members;";
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
			std::cout << "Enter the updated name: ";
			std::getline(std::cin, name);

			std::cout << "Enter the updated address: ";
			std::getline(std::cin, address);

			std::cout << "Enter the updated city: ";
			std::getline(std::cin, city);

			std::cout << "Enter the updated state: ";
			std::getline(std::cin, state);

			std::cout << "Enter the updated phone number: ";
			std::getline(std::cin, phone);

			stmt.str("");
			stmt << "UPDATE Members SET name = '" << name << "',address='" << address << "',city='" << city << "',state='" << state << "',phone='" << phone << "' WHERE ID = " << id << ';';
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			res_set = mysql_store_result(conn);

			if (!(res_set))
			{
				std::cout << "\nMember updated successfully!\n\n";
			}
			else
			{
				std::cout << "Update error, contact technical team\n\n";
			}
		}

		while (true)
		{
			std::cout << "Enter 1 to update another member\n";
			std::cout << "Enter 2 to return to the Member Menu\n";
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

void Member::removeMember()
{
	while (true)
	{
		std::cout << "Enter the ID of the member to remove: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Members;";
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
			stmt << "DELETE FROM Members WHERE ID = " << id << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			std::cout << "\nMember removed\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to delete another member\n";
			std::cout << "Enter 2 to return to the Member Menu\n";
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

void Member::searchMember()
{
	while (true)
	{
		std::cout << "\nEnter the ID of the member you would like to search for: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT * FROM Members WHERE ID = " << id << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if ((row = mysql_fetch_row(res_set)) != NULL)
		{
			std::cout << "\nThe name of the member is " << row[1] << '\n';
			std::cout << "Their address is " << row[2] << ", " << row[3] << ", " << row[4] << '\n';
			std::cout << "Their phone number is " << row[5] << "\n\n";
		}
		else
		{
			std::cout << "\nNo record found" << "\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to search for another member\n";
			std::cout << "Enter 2 to return to the Member Menu\n";
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

void Member::printTable()
{
	query = "SELECT * FROM Members;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "\nMember ID: " << row[0] << '\n';
		std::cout << "Name: " << row[1] << '\n';
		std::cout << "Address: " << row[2] << '\n';
		std::cout << "City: " << row[3] << '\n';
		std::cout << "State: " << row[4] << '\n';
		std::cout << "Phone number: " << row[5] << "\n\n";
	}

	std::cout << "Press Enter to go back to the Book Menu\n";
	ignoreLine();
	std::cin.get();
	system("cls");
}
