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
	PhoneBook(void);
	~PhoneBook(void);
	void addContact(void);
	void searchContact(void);
};

#endif
