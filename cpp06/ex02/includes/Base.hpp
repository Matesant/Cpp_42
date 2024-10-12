#ifndef BASE_HPP
# define BASE_HPP

#include "Utils.hpp"

// Class declaration
class Base
{
  public:
	virtual ~Base();
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

// Function prototypes
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif // BASE_HPP
