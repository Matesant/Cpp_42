#include "./includes/PhoneBook.hpp"

void helpMessage()
{
	std::cout << GREEN << "ADD" << RESET << ": Add a new contact to your phonebook!\n"
			  << GREEN << "SEARCH" << RESET << ": Lists all the contacts already registered in your phonebook\n"
			  << GREEN << "EXIT" << RESET << ": Exit from the phonebook" << std::endl;
}

bool nameIsOnlyLetters(std::string &name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]))
			return false;
	}
	return true;
}

bool isOnlyDigits(std::string &phoneNumber)
{
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
			return false;
	}
	return true;
}

void validateName(std::string &name)
{
	while (name.empty() || nameIsOnlyLetters(name) == false)
	{
		std::cout << BRIGHT_MAGENTA << name << BRIGHT_RED << " is not valid name" << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert a name: " << RESET;
		std::getline(std::cin, name);
	}
}

void validatePhoneNumber(std::string &phoneNumber)
{
	while (phoneNumber.empty() || phoneNumber.length() < 10 || phoneNumber.length() > 15 || !isOnlyDigits(phoneNumber))
	{
		std::cout << BRIGHT_RED << "please enter a valid phone number with 10 to 15 numbers" << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Phone number: " << RESET;
		std::getline(std::cin, phoneNumber);
	}
}