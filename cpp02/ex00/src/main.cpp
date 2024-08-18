#include "./includes/Fixed.hpp"

int	main(void)
{
	std::cout << BOLD << INVERSE << "INSTANTIATING OBJECTS AND CALLING THEIR DEFAULT CONSTRUCTORS" << RESET << std::endl;
	Fixed	a;
	Fixed	c;

	std::cout << BOLD << INVERSE << "INSTANTIATING OBJECTS AND CALLING THEIR COPY CONSTRUCTORS" << RESET << std::endl;
	Fixed b(a);
	c = b;

	std::cout << BOLD << INVERSE << "GETTING RAW BITS" << RESET << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << BOLD << INVERSE << "SETTING RAW BITS" << RESET << std::endl;
	b.setRawBits(42);
	a.setRawBits(21);
	c.setRawBits(84);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << BOLD << INVERSE << "DESTRUCTORS" << RESET << std::endl;
	return (0);
}
