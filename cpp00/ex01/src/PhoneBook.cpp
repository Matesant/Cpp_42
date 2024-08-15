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
	if (this->_size == 8)
	{
		std::cout << BRIGHT_MAGENTA << "PhoneBook is full. The oldest Contact will be deleted." << std::endl;
		for (int i = 0; i < 7; i++)
		{
			this->_contacts[i] = this->_contacts[i + 1];
		}
		this->_index--;
		this->_size--;
	}
	this->_index++;
	this->_size++;
	std::cout << BRIGHT_GREEN << "Please insert the contact first name: " << RESET;
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, name);
	this->_contacts[this->_index].setFirstName(name);
	std::cout << BRIGHT_GREEN << "Please insert the contact last name: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setLastName(name);
	std::cout << BRIGHT_GREEN <<  "Please insert the contact nickname: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setNickname(name);
	std::cout << BRIGHT_GREEN << "Please insert the contact darkest secret: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setDarkestSecret(name);
	std::cout << BRIGHT_GREEN << "Please insert the contact phone number: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_index].setPhoneNumber(name);
}

std::string formatString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 8) + ".";
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
		std::cout << BRIGHT_RED << "No contacts available" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < this->_size)
	{
		std::cout << std::setw(10) << std::right << i+ 1 
			 << "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getFirstName())
			 << "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getLastName())
			 << "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getNickname()) 
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