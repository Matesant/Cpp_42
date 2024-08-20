#include "./includes/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << BOLD_CYAN << "Default constructor called" << RESET << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << BOLD_YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << BOLD_RED << "Destructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rigthSide)
{
	std::cout << BOLD_BRIGHT_MAGENTA << "Assignation operator called" << RESET << std::endl;
	this->_fixedPointValue = rigthSide.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << BOLD_GREEN << "getRawBits member function called" << RESET << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << BOLD << BLINK << "setRawBits member function called" << RESET << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

Fixed::Fixed(const int value)
{
	std::cout << BOLD_CYAN << "Int constructor called" << RESET << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << BOLD_CYAN << "Float constructor called" << RESET << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

bool Fixed::operator>(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue > rigthSide.getRawBits());
}

bool Fixed::operator<(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue < rigthSide.getRawBits());
}

bool Fixed::operator>=(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue >= rigthSide.getRawBits());
}

bool Fixed::operator<=(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue <= rigthSide.getRawBits());
}

bool Fixed::operator==(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue == rigthSide.getRawBits());
}

bool Fixed::operator!=(Fixed const &rigthSide) const
{
	return (this->_fixedPointValue != rigthSide.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() + rigthSide.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() - rigthSide.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() * rigthSide.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() / rigthSide.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed preIncrement(*this);
	operator++();
	return (preIncrement);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed preDecrement(*this);
	operator--();
	return (preDecrement);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}