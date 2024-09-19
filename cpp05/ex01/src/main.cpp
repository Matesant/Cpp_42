#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--- Creating a Bureaucrat with grade 150 ---" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	Bureaucrat *bureaucrat = new Bureaucrat("Chico bento", 150);
	std::cout << *bureaucrat << std::endl;
	std::cout << std::endl;

	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "-- Creating a Form with grade 150 to sign --" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	Form *form = NULL;

	try
	{
		form = new Form("Form 1", 150, 150);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "-------- Bureacrat sign the Form -----------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << *form << std::endl;
		bureaucrat->signForm(*form);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "---- Creating a Bureaucrat with grade 1 ----" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	Bureaucrat *fotocopia = new Bureaucrat("Fotocopia", 1);
	std::cout << *fotocopia << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "------- Creating a form with grade 3 -------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	Form *form2 = NULL;

	try
	{
		form2 = new Form("Form 2", 3, 150);
		std::cout << *form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "Bureacrat with low grade try to sign the Form" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << *form2 << std::endl;
		bureaucrat->signForm(*form2);
		std::cout << *form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "Bureacrat with high grade try to sign the Form" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << *form2 << std::endl;
		fotocopia->signForm(*form2);
		std::cout << *form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "-- Creating a Form with grade 200 to sign --" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		form = new Form("Form 3", 200, 150);
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	delete bureaucrat;
	delete fotocopia;
	delete form;
	delete form2;
	std::cout << std::endl;

	return (0);
}
