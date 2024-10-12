#ifndef UTILS_HPP
# define UTILS_HPP

# include <cctype>
# include <iostream>
# include <string>
# include <cstddef>

typedef std::size_t uintptr_t;

#define ORANGE "\033[38;5;208m"
#define PINK "\033[38;5;213m"
#define PURPLE "\033[38;5;135m"
#define GREY "\033[38;5;246m"
#define BROWN "\033[38;5;130m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;95m"
#define BLUE "\033[1;34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define INVERSE "\033[7m"

void newLine(void);

#endif
