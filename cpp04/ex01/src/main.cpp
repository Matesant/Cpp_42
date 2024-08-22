#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include "./includes/WrongCat.hpp"

int	main(void)
{
	Animal	*animals[6];

	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------------- ANIMAL LOOP ------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------- TESTING IDEAS,SOUNDS & TYPES -------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << MAGENTA << animals[i]->getType() << RESET << BOLD << " has an idea: " << GREEN << "BARK BARK BARK!" << RESET << std::endl;
			std::cout << BOLD << "Translated to: " << MAGENTA << ((Dog *)animals[i])->getIdea(i) << RESET << std::endl;
		}
		else
		{
			std::cout << MAGENTA << animals[i]->getType() << RESET << BOLD << " has an idea: " << GREEN << "MEOOOW MEOW!" << RESET << std::endl;
			std::cout << BOLD << "Translated to: " << MAGENTA << ((Cat *)animals[i])->getIdea(i) << RESET << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------ DEEP COPY FROM ARRAY --------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	{
		Dog copy_dog((Dog &)*animals[0]);
		Cat copy_cat((Cat &)*animals[1]);
		std::cout << INVERSE << YELLOW << "------------------ ORIGINAL ANIMALS ------------------------" << RESET << std::endl;
		std::cout << MAGENTA << animals[0]->getType() << RESET << BOLD << " has an idea: " << GREEN << "BARK BARK BARK!" << RESET << std::endl;
		std::cout << BOLD << "Translated to: " << MAGENTA << ((Dog *)animals[0])->getIdea(12) << RESET << std::endl;
		std::cout << MAGENTA << animals[1]->getType() << RESET << BOLD << " has an idea: " << GREEN << "MEOOOW MEOW!" << RESET << std::endl;
		std::cout << BOLD << "Translated to: " << MAGENTA << ((Cat *)animals[1])->getIdea(34) << RESET << std::endl;
		std::cout << INVERSE << YELLOW << "------------------ COPIED ANIMALS --------------------------" << RESET << std::endl;
		std::cout << MAGENTA << animals[0]->getType() << RESET << BOLD << " has an idea: " << GREEN << "BARK BARK BARK!" << RESET << std::endl;
		std::cout << BOLD << "Translated to: " << MAGENTA << ((Dog *)animals[0])->getIdea(12) << RESET << std::endl;
		std::cout << MAGENTA << animals[1]->getType() << RESET << BOLD << " has an idea: " << GREEN << "MEOOOW MEOW!" << RESET << std::endl;
		std::cout << BOLD << "Translated to: " << MAGENTA << ((Cat *)animals[1])->getIdea(34) << RESET << std::endl;
		std::cout << INVERSE << YELLOW << "-------------- DESCTRUCTORS CALLED -------------------------" << RESET << std::endl;
	}
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------------- DELETING ANIMALS -------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------------- TESTING DEEP COPY ------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;
	{
		Cat		cat1;
		std::cout << INVERSE << CYAN << "Cat 1 ideas: " << cat1.getIdea(0) << RESET << std::endl;
		Cat		cat2(cat1);
		std::cout << INVERSE << CYAN << "Cat 2 ideas after copy: " << cat2.getIdea(0) << std::endl;
		std::cout << INVERSE << CYAN << "Changing Cat 1 idea" << std::endl;
		cat1.setIdea(0, "I am a new cat");
		std::cout << INVERSE << CYAN << "Cat 1 ideas: " << cat1.getIdea(0) << RESET << std::endl;
		std::cout << INVERSE << CYAN << "Cat 2 ideas after change in Cat 1: " << cat2.getIdea(0) << RESET << std::endl;
	}
	std::cout << std::endl;


	return (0);
}
