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
	Contact(void);
	~Contact(void);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
	void printContact(void);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getPhoneNumber(void);
	std::string getDarkestSecret(void);
};

void		helpMessage(void);
void		validateName(std::string &name);
void		validatePhoneNumber(std::string &phoneNumber);

#endif