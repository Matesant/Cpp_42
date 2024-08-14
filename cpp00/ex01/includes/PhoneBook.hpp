#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	int _size;

  public:
	// constructor
	PhoneBook(void);
	// destructor
	~PhoneBook(void);
	// methods
	void addContact(void);
	void searchContact(void);
};

#endif
