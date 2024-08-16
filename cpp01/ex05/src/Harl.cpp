#include "./includes/Harl.hpp"

Harl::Harl(void)
{
	std::cout << INVERSE << "Harl is here to complaim!" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << INVERSE << "Finally, Harl is gone!" << std::endl;
	return ;
}

void Harl::complain(std::string level)
{
	std::string Complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*membFunctions[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (Complaints[i] == level)
		{
			(this->*membFunctions[i])();
			return ;
		}
	}
	std::cout << BOLD << BRIGHT_MAGENTA << "Invalid complaint level" << RESET << std::endl;
}

void Harl::debug(void)
{
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": Starting the extra bacon module." << RESET << std::endl;
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": Ensuring bacon quantity meets 7XL standards." << RESET << std::endl;
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": Verifying the freshness of lettuce." << RESET << std::endl;
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": No wilted leaves detected." << RESET << std::endl;
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": Loading the special ketchup recipe." << RESET << std::endl;
	std::cout << BOLD << INVERSE << CYAN << "DEBUG" << RESET << BOLD << CYAN 
              << ": Triple-checking the secret ingredient ratio." << RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Extra bacon added successfully." << RESET << std::endl;
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Proceeding to next burger customization step." << RESET << std::endl;
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Customer requested additional cheese layer." << RESET << std::endl;
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Extra cheese applied." << RESET << std::endl;
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Burger assembly complete." << RESET << std::endl;
	std::cout << BOLD << INVERSE << GREEN << "INFO" << RESET << BOLD << GREEN 
              << ": Preparing to wrap and serve." << RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": Bacon supply running low." << RESET << std::endl;
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": Replenishment needed to avoid customer dissatisfaction." << RESET << std::endl;
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": Pickle count discrepancy detected." << RESET << std::endl;
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": May result in fewer pickles than requested." << RESET << std::endl;
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": Customer has been waiting longer than usual." << RESET << std::endl;
	std::cout << BOLD << INVERSE << YELLOW << "WARNING" << RESET << BOLD << YELLOW 
              << ": Expedite order preparation." << RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": No bacon available!" << RESET << std::endl;
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": Unable to complete the 7XL-double-cheese-triple-pickle-special-ketchup burger." << RESET << std::endl;
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": Cheese melter malfunction!" << RESET << std::endl;
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": Unable to apply the correct cheese layer." << RESET << std::endl;
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": Pickle jar dropped!" << RESET << std::endl;
	std::cout << BOLD << INVERSE << RED << "ERROR" << RESET << BOLD << RED 
              << ": Insufficient pickles for the order." << RESET << std::endl;
}
