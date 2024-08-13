#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = -1;
	this->_size = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::addContact(void)
{
	std::string name;
	this->_index++;
	this->_size++;
	std::cout << BRIGHT_GREEN << "Enter the first name: " << RESET;
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, name);
	validateName(name);
	this->_contacts[this->_index].setFirstName(name);
	std::cout << BRIGHT_GREEN << "Enter the last name: " << RESET;
	std::getline(std::cin, name);
	validateName(name);
	this->_contacts[this->_index].setLastName(name);
	std::cout << BRIGHT_GREEN << "Enter the nickname: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setNickname(name);
	std::cout << BRIGHT_GREEN << "Enter darkest secret: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setDarkestSecret(name);
	std::cout << BRIGHT_GREEN << "Enter the phone number: " << RESET;
	std::getline(std::cin, name);
	validatePhoneNumber(name);
	this->_contacts[this->_index].setPhoneNumber(name);
}

std::string formatString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

bool indexIsValid(const std::string& index, int size) {
	if (index.length() > 1 || !isdigit(index[0]) || index[0] - '0' > size \
		|| index[0] - '0' < 1) {
		return false;
	}
	return true;
}

void PhoneBook::searchContact(void)
{
	int 		i;
	std::string index;

	i = 0;
	if (this->_size == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return ;
	}
	std::cout << "index | first name | last name  | nickname" << std::endl;
	while (i < this->_size)
	{
		std::cout << std::setw(5) << std::right << i+ 1 
			 << " | " << std::setw(10) << std::right << formatString(this->_contacts[i].getFirstName())
			 << " | " << std::setw(10) << std::right << formatString(this->_contacts[i].getLastName())
			 << " | " << std::setw(10) << std::right << formatString(this->_contacts[i].getNickname()) 
			 << std::endl;
		i++;
	}
	std::cout << CYAN << "Enter the index of the contact you want to see: " << RESET << std::endl;
	std::cin >> index;
	while (indexIsValid(index, this->_size) == false)
	{
		std::cout << BRIGHT_RED << "Invalid index" << std::endl;
		std::cout << CYAN << "Enter the index of the contact you want to see: " << RESET << std::endl;
		std::cin >> index;
	}
	this->_contacts[index[0] - '0' - 1].printContact();
}