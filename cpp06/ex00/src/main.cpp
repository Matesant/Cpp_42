#include "./includes/Bureaucrat.hpp"

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
	std::cout << INVERSE << YELLOW << "---- Trying to decrease grade bellow 150 ---" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	try
	{
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------- Trying to increase grade ---------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat << std::endl;
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
	std::cout << INVERSE << YELLOW << "----- Trying to increase grade above 1 -----" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		fotocopia->incrementGrade();
		std::cout << *fotocopia << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------- Trying to decrease grade ---------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	
	try
	{
		fotocopia->decrementGrade();
		std::cout << *fotocopia << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--- Creating a Bureaucrat with grade 151 ---" << RESET << std::endl;
	std::cout << INVERSE << YELLOW << "--------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Chico bento", 151);
		std::cout << *bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	delete bureaucrat;
	delete fotocopia;
	std::cout << std::endl;

	return (0);
}
