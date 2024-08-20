#include "./includes/Fixed.hpp"

void	subjectTest(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

int	main(void)
{
	Fixed a(5);
	Fixed b(10);
	Fixed const c(10);
	Fixed const d(10);
	std::cout << INVERSE << BOLD_CYAN << "Value of a: " << RESET << a << std::endl;
	std::cout << INVERSE << BOLD_CYAN << "Value of b: " << RESET << b << std::endl;
	std::cout << INVERSE << "Testing comparison operators" << RESET << std::endl;
	std::cout << BOLD_GREEN << "a is less than b: " << RESET << (a < b) << std::endl;
	std::cout << BOLD_GREEN << "a is greater than b: " << RESET << (a > b) << std::endl;
	std::cout << BOLD_GREEN << "a is less than or equal to b: " << RESET << (a <= b) << std::endl;
	std::cout << BOLD_GREEN << "a is greater than or equal to b: " << RESET << (a >= b) << std::endl;
	std::cout << BOLD_GREEN << "a is equal to b: " << RESET << (a == b) << std::endl;
	std::cout << BOLD_GREEN << "a is not equal to b: " << RESET << (a != b) << std::endl;
	std::cout << INVERSE << "Testing arithmetic operators" << RESET << std::endl;
	std::cout << BOLD_GREEN << "a + b: " << RESET << (a + b) << std::endl;
	std::cout << BOLD_GREEN << "a - b: " << RESET << (a - b) << std::endl;
	std::cout << BOLD_GREEN << "a * b: " << RESET << (a * b) << std::endl;
	std::cout << BOLD_GREEN << "a / b: " << RESET << (a / b) << std::endl;
	a.setRawBits(5);
	std::cout << INVERSE << "Testing increment and decrement operators" << RESET << std::endl;
	std::cout << ++a << std::endl;
	std::cout << INVERSE << "Reseting a to 5 before next increment" << RESET << std::endl;
	a.setRawBits(5);
	std::cout << a++ << std::endl;
	std::cout << "Testing decrement operator" << std::endl;
	std::cout << INVERSE << "Reseting a to 5 before decrement" << RESET << std::endl;
	a.setRawBits(5);
	std::cout << --a << std::endl;
	std::cout << INVERSE << "Reseting a to 5 before decrement" << RESET << std::endl;
	a.setRawBits(5);
	std::cout << a-- << std::endl;
	std::cout << INVERSE << "Testing min and max functions" << RESET << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << INVERSE << "Testing min and max functions with const Fixed" << RESET << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	subjectTest();
	return (0);
}
