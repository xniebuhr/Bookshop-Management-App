#include "Menus.h"
#include "Global.h"

int main()
{
	const std::string username{ "" /* Add login username */};
	const std::string password{ "" /* Add login password */};
	std::string i;

	std::cout << "Welcome to the Bookshop Management System\n\nPlease login\n";

	while (true)
	{
		std::cout << "Enter username: ";
		std::cin >> i;
		if (i != username)
		{
			std::cout << "Invalid username\n";
			continue;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Enter password: ";
		std::cin >> i;
		if (i != password)
		{
			std::cout << "Invalid password\n";
			continue;
		}
		else
		{
			break;
		}
	}

	initializeDatabase();

	if (conn)
	{
		while (true)
		{
			system("cls");
			mainMenu();
		}
	}
	else
	{
		system("cls");
		std::cout << "Error While connection to database. Contact Tech Expert.\n";
	}

	return 0;
}
