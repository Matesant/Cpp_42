#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Class declaration
class PresidentialPardonForm: public AForm
{
  public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();

	//member functions
	void execute(Bureaucrat const &executor) const;

  private:
  	std::string _target;

	
};

#endif // PRESIDENTIALPARDONFORM_HPP
