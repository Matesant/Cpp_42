#include <iostream>
#include <string>
#include "includes/PhoneBook.hpp"
#include <unistd.h>

int main(void)
{
	PhoneBook PhoneBook;
	std::string command;

	do
	{
		std::cout << BRIGHT_YELLOW << "Type a command or type -help: " << RESET;
		std::cin >> command;
		
		if (command == "ADD" || command == "add")
			PhoneBook.addContact();
		else if (command == "SEARCH" || command == "search")
			PhoneBook.searchContact();
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << RED << ("Thank you for using our Super PhoneBook! :D") << std::endl;
			break;
		}
		else if (command == "help")
			helpMessage();
		else
			std::cout << BRIGHT_RED << "Invalid command, type -help for additional information" << RESET << std::endl;
	} while (1);

	return (0);
}
