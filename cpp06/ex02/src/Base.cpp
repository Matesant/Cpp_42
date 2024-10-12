#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	srand(std::time(0));
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout << MAGENTA << "A instance created" << RESET << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << BLUE << "B instance created" << RESET << std::endl;
		return (new B);
	}
	else
	{
		std::cout << GREEN << "C instance created" << RESET << std::endl;
		return (new C);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << MAGENTA << "It's an A type" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BLUE << "It's an B type" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "It's an C type" << RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << MAGENTA << "It's an A type" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << BLUE << "It's an B type" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "It's an C type" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Unknown type" << RESET << std::endl;
	}
}