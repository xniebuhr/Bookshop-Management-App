#include "Menus.h"
#include "Global.h"

void mainMenu()
{
	std::cout << "**********************************************\n";
	std::cout << "          BOOKSHOP MANAGEMENT SYSTEM\n";
	std::cout << "**********************************************\n\n";
	std::cout << "   1. BOOKS\n";
	std::cout << "   2. PURCHASES\n";
	std::cout << "   3. EMPLOYEES\n";
	std::cout << "   4. MEMBERS\n";
	std::cout << "   5. SALES\n";
	std::cout << "   6. EXIT\n\n";
	std::cout << "Enter your choice: ";
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (!std::cin)
		{
			std::cout << "Please enter a valid input\n";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		if (choice < 1 || choice > 6)
		{
			std::cout << "Please enter a valid input\n";
			std::cin.clear();
			ignoreLine();
			continue;
		}

		break;
	}

	switch (choice)
	{
	case 1:
		system("cls");
		bookMenu();
		break;
	case 2:
		system("cls");
		purchaseMenu();
		break;
	case 3:
		system("cls");
		employeeMenu();
		break;
	case 4:
		system("cls");
		memberMenu();
		break;
	case 5:
		system("cls");
		salesMenu();
		break;
	case 6:
		exit(0);
	}
}

void bookMenu()
{
	while (true)
	{
		std::cout << "**********************************************\n";
		std::cout << "                  BOOK MENU\n";
		std::cout << "**********************************************\n\n";
		std::cout << "   1. ADD\n";
		std::cout << "   2. UPDATE\n";
		std::cout << "   3. DELETE\n";
		std::cout << "   4. SEARCH\n";
		std::cout << "   5. SEE ALL BOOKS\n";
		std::cout << "   6. RETURN TO MAIN MENU\n\n";
		std::cout << "Enter your choice: ";
		int choice;
		while (true)
		{
			std::cin >> choice;
			if (!std::cin)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			if (choice < 1 || choice > 6)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			break;
		}

		Book b;

		switch (choice)
		{
		case 1:
			b.addBook();
			break;
		case 2:
			b.updateBook();
			break;
		case 3:
			b.deleteBook();
			break;
		case 4:
			b.searchBook();
			break;
		case 5:
			b.printTable();
			break;
		case 6:
			system("cls");
			return;
		}
	}
}

void purchaseMenu()
{
	while (true)
	{
		std::cout << "**********************************************\n";
		std::cout << "                PURCHASES MENU\n";
		std::cout << "**********************************************\n\n";
		std::cout << "   1. NEW\n";
		std::cout << "   2. UPDATE\n";
		std::cout << "   3. CANCEL\n";
		std::cout << "   4. SEARCH\n";
		std::cout << "   5. SEE ALL PURCHASES\n";
		std::cout << "   6. RETURN TO MAIN MENU\n\n";
		std::cout << "Enter your choice: ";
		int choice;
		while (true)
		{
			std::cin >> choice;
			if (!std::cin)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			if (choice < 1 || choice > 6)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			break;
		}

		Purchase p;

		switch (choice)
		{
		case 1:
			p.newOrder();
			break;
		case 2:
			p.updateOrder();
			break;
		case 3:
			p.cancelOrder();
			break;
		case 4:
			p.searchOrder();
			break;
		case 5:
			p.printTable();
			break;
		case 6:
			system("cls");
			return;
		}
	}
}

void employeeMenu()
{
	while (true)
	{
		std::cout << "**********************************************\n";
		std::cout << "                 EMPLOYEE MENU\n";
		std::cout << "**********************************************\n\n";
		std::cout << "   1. ADD\n";
		std::cout << "   2. UPDATE\n";
		std::cout << "   3. REMOVE\n";
		std::cout << "   4. SEARCH\n";
		std::cout << "   5. SEE ALL EMPLOYEES\n";
		std::cout << "   6. RETURN TO MAIN MENU\n\n";
		std::cout << "Enter your choice: ";
		int choice;
		while (true)
		{
			std::cin >> choice;
			if (!std::cin)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			if (choice < 1 || choice > 7)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			break;
		}

		Employee e;

		switch (choice)
		{
		case 1:
			e.addEmployee();
			break;
		case 2:
			e.updateEmployee();
			break;
		case 3:
			e.removeEmployee();
			break;
		case 4:
			e.searchEmployee();
			break;
		case 5:
			e.printTable();
			break;
		case 6:
			system("cls");
			return;
		}
	}
}

void memberMenu()
{
	while (true)
	{
		std::cout << "**********************************************\n";
		std::cout << "                  MEMBER MENU\n";
		std::cout << "**********************************************\n\n";
		std::cout << "   1. ADD\n";
		std::cout << "   2. UPDATE\n";
		std::cout << "   3. REMOVE\n";
		std::cout << "   4. SEARCH\n";
		std::cout << "   5. SEE ALL MEMBERS\n";
		std::cout << "   6. RETURN TO MAIN MENU\n\n";
		std::cout << "Enter your choice: ";
		int choice;
		while (true)
		{
			std::cin >> choice;
			if (!std::cin)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			if (choice < 1 || choice > 6)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			break;
		}

		Member m;

		switch (choice)
		{
		case 1:
			m.addMember();
			break;
		case 2:
			m.updateMember();
			break;
		case 3:
			m.removeMember();
			break;
		case 4:
			m.searchMember();
			break;
		case 5:
			m.printTable();
			break;
		case 6:
			system("cls");
			return;
		}
	}
}

void salesMenu()
{
	while (true)
	{
		std::cout << "**********************************************\n";
		std::cout << "                  SALES MENU\n";
		std::cout << "**********************************************\n\n";
		std::cout << "   1. NEW\n";
		std::cout << "   2. UPDATE\n";
		std::cout << "   3. CANCEL\n";
		std::cout << "   4. SEARCH\n";
		std::cout << "   5. SEE ALL SALES\n";
		std::cout << "   6. RETURN TO MAIN MENU\n\n";
		std::cout << "Enter your choice: ";
		int choice;
		while (true)
		{
			std::cin >> choice;
			if (!std::cin)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			if (choice < 1 || choice > 6)
			{
				std::cout << "Please enter a valid input\n";
				std::cin.clear();
				ignoreLine();
				continue;
			}

			break;
		}

		Sale s;

		switch (choice)
		{
		case 1:
			s.newSale();
			break;
		case 2:
			s.updateSale();
			break;
		case 3:
			s.cancelSale();
			break;
		case 4:
			s.searchSale();
			break;
		case 5:
			s.printTable();
			break;
		case 6:
			system("cls");
			return;
		}
	}
}
