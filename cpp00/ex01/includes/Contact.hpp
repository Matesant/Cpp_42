#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <cctype>
# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"

class Contact
{
  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

  public:
	// constructor
	Contact(void);
	// destructor
	~Contact(void);
	// setters
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
	// getters
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
	// methods
	void printContact(void);
};

void		helpMessage(void);

#endif