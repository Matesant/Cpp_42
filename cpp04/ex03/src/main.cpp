#include "./includes/Character.hpp"
#include "./includes/Cure.hpp"
#include "./includes/Ice.hpp"
#include "./includes/MateriaSource.hpp"

int	main(void)
{
	IMateriaSource	*src;
	ICharacter		*me;
	AMateria		*tmp;
	ICharacter		*bob;

	std::cout << CYAN << INVERSE << "--------------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Creating MateriaSource, Character, Ice, Cure" << RESET << std::endl;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	me = new Character("me");
	bob = new Character("bob");
	std::cout << CYAN << INVERSE << "--------------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Equipping Ice and Cure" << RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	std::cout << CYAN << INVERSE << "--------------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Using Ice and Cure" << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << CYAN << INVERSE << "--------------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << "Unequipping Ice" << RESET << std::endl;
	me->unequip(1);
	std::cout << CYAN << INVERSE << "--------------------------------------------------" << RESET << std::endl;

	delete			bob;
	delete			me;
	delete			src;
	delete 			tmp;

	return (0);
}
