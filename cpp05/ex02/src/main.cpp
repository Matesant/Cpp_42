#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "- Creating a bureaucrat Jaime that cannot approve nothing -" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;
    std::cout << std::endl;

    Bureaucrat jaime("Jaime", 150);
    std::cout << jaime << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "- Creating a bureaucrat Cersei that can approve everything-" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;
    std::cout << std::endl;

    Bureaucrat cersei("Cersei", 1);
    std::cout << cersei << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------- Creating a ShrubberyCreationForm form ---------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    ShrubberyCreationForm shrubbery("Winterfell");
    std::cout << shrubbery << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------- Creating a RobotomyRequestForm form -----------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    RobotomyRequestForm robotomy("Jon Snow");
    std::cout << robotomy << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------- Creating a PresidentialPardonForm form --------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    PresidentialPardonForm pardon("Ned Stark");
    std::cout << pardon << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------------- Jaime tries to sign forms ---------------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    try
    {
        jaime.signForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        jaime.signForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        jaime.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "------- Cersei tries to execute forms before signing ------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    try
    {
        cersei.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        cersei.executeForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        cersei.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------------- Cersei tries to sign forms --------------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    cersei.signForm(shrubbery);
    cersei.signForm(robotomy);
    cersei.signForm(pardon);

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" << std::endl;
    std::cout << "----------------- Jaime tries to execute forms ------------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET << std::endl;

    try
    {
        jaime.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        jaime.executeForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        jaime.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" <<std::endl;
    std::cout << "----------------- Cersei tries to execute forms -----------" << std::endl;
    std::cout << "-----------------------------------------------------------" << RESET <<std::endl;

    cersei.executeForm(shrubbery);
    cersei.executeForm(robotomy);
    cersei.executeForm(pardon);

    std::cout << std::endl;
    std::cout << YELLOW << INVERSE << "-----------------------------------------------------------" << RESET <<std::endl;

    return (0);
}
