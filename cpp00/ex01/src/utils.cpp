#include "./includes/Contact.hpp"

void helpMessage()
{
	std::cout << GREEN << "ADD" << RESET << ": Add a new contact to your phonebook!\n"
			  << GREEN << "SEARCH" << RESET << ": Lists all the contacts already registered in your phonebook\n"
			  << GREEN << "EXIT" << RESET << ": Exit from the phonebook" << std::endl;
}
