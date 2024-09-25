#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>

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
class Form
{
  public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	virtual ~Form();

	// Getters
	std::string getName(void) const;
	bool getSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	// Member functions
	void beSigned(Bureaucrat const &bureaucrat);
	void execute(Bureaucrat const &executor) const;

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

  private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif // FORM_HPP
