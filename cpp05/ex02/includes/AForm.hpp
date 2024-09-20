#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include <cstdlib>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;95m"
# define BLUE "\033[1;34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define INVERSE "\033[7m"

class	Bureaucrat;

// Class declaration
class AForm
{
  private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

  public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);
	~AForm();

	// Getters
	std::string getName(void) const;
	bool getSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	// Member functions
	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &value);

#endif // AFORM_HPP
