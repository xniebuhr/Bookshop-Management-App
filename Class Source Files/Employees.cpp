#include "Employees.h"
#include "Global.h"

void Employee::addEmployee()
{
	while (true)
	{
		ignoreLine();
		std::cout << "Enter the employee's name: ";
		std::getline(std::cin, name);

		std::cout << "Enter the employee's address: ";
		std::getline(std::cin, address);

		std::cout << "Enter the employee's city: ";
		std::getline(std::cin, city);

		std::cout << "Enter the employee's state: ";
		std::getline(std::cin, state);

		std::cout << "Enter the employee's phone number: ";
		std::getline(std::cin, phone);

		std::cout << "Enter the employee's salary: ";
		std::cin >> salary;

		char c;
		std::cout << "Is this employee a manager (y/n): ";
		std::cin >> c;
		if (c == 'y')
		{
			isManager = true;
		}
		else
		{
			isManager = false;
		}

		stmt.str("");
		stmt << "INSERT INTO Employees (name, address, city, state, phone, salary, isManager) VALUES ('" << name << "','" << address << "','" << city << "','" << state << "','" << phone << "'," << salary << "," << isManager << ");";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if (!(res_set))
		{
			std::cout << "\Employee added successfully!\n\n";
		}
		else
		{
			std::cout << "Entry error, contact technical team\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to add another employee\n";
			std::cout << "Enter 2 to return to the Employee Menu\n";
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

void Employee::updateEmployee()
{
	while (true)
	{
		std::cout << "Enter the ID of the employee to update: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Employees;";
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
			std::cout << "Enter the employee's updated name: ";
			std::getline(std::cin, name);

			std::cout << "Enter the employee's updated address: ";
			std::getline(std::cin, address);

			std::cout << "Enter the employee's updated city: ";
			std::getline(std::cin, city);

			std::cout << "Enter the employee's updated state: ";
			std::getline(std::cin, state);

			std::cout << "Enter the employee's updated phone number: ";
			std::getline(std::cin, phone);

			std::cout << "Enter the employee's updated salary: ";
			std::cin >> salary;

			char c;
			std::cout << "Is this employee a manager (y/n): ";
			std::cin >> c;
			if (c == 'y')
			{
				isManager = true;
			}
			else
			{
				isManager = false;
			}

			stmt.str("");
			stmt << "UPDATE Employees SET name='" << name << "',address='" << address << "',city='" << city << "',state='" << state << "',phone='" << phone << "',salary=" << salary << ",isManager=" << isManager << " WHERE ID = " << id << ';';
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			res_set = mysql_store_result(conn);

			if (!(res_set))
			{
				std::cout << "\Employee updated successfully!\n\n";
			}
			else
			{
				std::cout << "Update error, contact technical team\n\n";
			}
		}

		while (true)
		{
			std::cout << "Enter 1 to update another employee\n";
			std::cout << "Enter 2 to return to the Employee Menu\n";
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

void Employee::removeEmployee()
{
	while (true)
	{
		std::cout << "Enter the ID of the employee to remove: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT MAX(ID) FROM Employees;";
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
			stmt << "DELETE FROM Employees WHERE ID = " << id << ";";
			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);
			std::cout << "\nEmployee removed\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to remove another employee\n";
			std::cout << "Enter 2 to return to the Employee Menu\n";
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

void Employee::searchEmployee()
{
	while (true)
	{
		std::cout << "\nEnter the ID of the employee you would like to search for: ";
		std::cin >> id;

		stmt.str("");
		stmt << "SELECT * FROM Employees WHERE ID = " << id << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
		res_set = mysql_store_result(conn);

		if ((row = mysql_fetch_row(res_set)) != NULL)
		{
			std::cout << "\nThe employee's name is " << row[1] << '\n';
			std::cout << "Their address is " << row[2] << ", " << row[3] << ", "<< row[4] << '\n';
			std::cout << "Their phone number is " << row[5] << '\n';
			std::cout << "Their salary is $" << row[6] << '\n';
			if (std::stoi(row[7]) != 0)
			{
				std::cout << "They are a manager\n\n";
			}
			else
			{
				std::cout << "They are not a manager\n\n";
			}
		}
		else
		{
			std::cout << "\nNo record found" << "\n\n";
		}

		while (true)
		{
			std::cout << "Enter 1 to search for another employee\n";
			std::cout << "Enter 2 to return to the Employee Menu\n";
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

void Employee::printTable()
{
	query = "SELECT * FROM Employees;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "\nEmployee ID: " << row[0] << '\n';
		std::cout << "Name: " << row[1] << '\n';
		std::cout << "Address: " << row[2] << ", " << row[3] << ", " << row[4] << '\n';
		std::cout << "Phone number: " << row[5] << '\n';
		std::cout << "Salary: $" << row[6] << '\n';
		if (std::stoi(row[7]) != 0)
		{
			std::cout << "Is a manager: Yes\n\n";
		}
		else
		{
			std::cout << "Is a manager: No\n\n";
		}
	}

	std::cout << "Press Enter to go back to the Employee Menu\n";
	ignoreLine();
	std::cin.get();
	system("cls");
}
