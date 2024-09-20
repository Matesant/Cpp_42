#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

// Class declaration
class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();

	// member functions
	void execute(Bureaucrat const &executor) const;

  private:
	std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
