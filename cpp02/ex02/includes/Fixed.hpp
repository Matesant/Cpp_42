#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>
# include <string>
# include <cmath>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string YELLOW = "\033[33m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BOLD_RED = "\033[1;31m";
const std::string BOLD_GREEN = "\033[1;32m";
const std::string BOLD_CYAN = "\033[1;36m";
const std::string BOLD_YELLOW = "\033[1;33m";
const std::string BOLD_BRIGHT_MAGENTA = "\033[1;95m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string RESET = "\033[0m";
const std::string INVERSE = "\033[7m";

// Class declaration
class Fixed
{
  public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	// Min and Max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	// Comparison operators
	bool operator>(Fixed const &rigthSide) const;
	bool operator<(Fixed const &rigthSide) const;
	bool operator>=(Fixed const &rigthSide) const;
	bool operator<=(Fixed const &rigthSide) const;
	bool operator==(Fixed const &rigthSide) const;
	bool operator!=(Fixed const &rigthSide) const;

	// Arithmetic operators
	Fixed &operator=(Fixed const &rigthSide);
	Fixed operator+(Fixed const &rigthSide) const;
	Fixed operator-(Fixed const &rigthSide) const;
	Fixed operator*(Fixed const &rigthSide) const;
	Fixed operator/(Fixed const &rigthSide) const;

	// Increment and decrement operators
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

  private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
