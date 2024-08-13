#include "./includes/PhoneBook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
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

bool nameIsOnlyLettersAndSpaces(std::string &name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && !isspace(name[i]))
			return false;
	}
	return true;
}

void Contact::setFirstName(std::string firstName)
{
	while (firstName.empty())
	{
		std::cout << BRIGHT_RED << "Error: The first name field cannot be empty." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact first name: " << RESET;
		std::getline(std::cin, firstName);
	}
	while (!nameIsOnlyLettersAndSpaces(firstName))
	{
		std::cout << BRIGHT_RED << "Error: The first name field can only contain letters." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact first name: " << RESET;
		std::getline(std::cin, firstName);
	}
	this->_firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	while (lastName.empty())
	{
		std::cout << BRIGHT_RED << "Error: The last name field cannot be empty." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact last name: " << RESET;
		std::getline(std::cin, lastName);
	}
	while (!nameIsOnlyLettersAndSpaces(lastName))
	{
		std::cout << BRIGHT_RED << "Error: The last name field can only contain letters." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact last name: " << RESET;
		std::getline(std::cin, lastName);
	}
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	while (nickname.empty())
	{
		std::cout << BRIGHT_RED << "Error: The nickname field cannot be empty." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact nickname: " << RESET;
		std::getline(std::cin, nickname);
	}
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	while (phoneNumber.empty())
	{
		std::cout << BRIGHT_RED << "Error: The phone number field cannot be empty." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact phone number: " << RESET;
		std::getline(std::cin, phoneNumber);
	}
	while (phoneNumber.length() < 10 || phoneNumber.length() > 15 || !isOnlyDigits(phoneNumber))
	{
		std::cout << BRIGHT_RED << "Error: The phone number must contain 10 to 15 digits." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact phone number: " << RESET;
		std::getline(std::cin, phoneNumber);
	}
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	while (darkestSecret.empty())
	{
		std::cout << BRIGHT_RED << "Error: The darkest secret field cannot be empty." << RESET << std::endl;
		std::cout << BRIGHT_GREEN << "Please insert the contact darkest secret: " << RESET;
		std::getline(std::cin, darkestSecret);
	}
	this->_darkestSecret = darkestSecret;
}

void Contact::printContact(void)
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}