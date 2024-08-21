#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include "./includes/WrongCat.hpp"

int main(void)
{
	Animal *randonAnimal;
	Animal *dogAnimal;
	Animal *catAnimal;

	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "--------- INSTANTIATE DOG, CAT & ANIMAL OBJECTS ------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	randonAnimal = new Animal();
	dogAnimal = new Dog();
	catAnimal = new Cat();

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------- PRINTING ANIMAL TYPES --------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	std::cout << BOLD << "THE ANIMAL CLASS HAS TYPE: " << MAGENTA << randonAnimal->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "THE DOG CLASS HAS TYPE: " << MAGENTA << dogAnimal->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "THE CAT CLASS HAS TYPE: " << MAGENTA << catAnimal->getType() << " " << RESET << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------- MAKING SOUNDS ----------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	randonAnimal->makeSound();
	dogAnimal->makeSound();
	catAnimal->makeSound();

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "--------- INSTANTIATE WRONG ANIMAL & CAT OBJECTS -----------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	WrongAnimal *wrongAnimal = new WrongAnimal();
	WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "--------------- PRINTING WRONG ANIMAL TYPES ----------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	std::cout << BOLD << "THE WRONG ANIMAL CLASS HAS TYPE: " << MAGENTA << wrongAnimal->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "THE WRONG CAT CLASS HAS TYPE: " << MAGENTA << wrongCat->getType() << " " << RESET << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "----------------- MAKING SOUNDS ----------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << INVERSE << YELLOW << "----------------- DELETING OBJECTS -------------------------" << std::endl;
	std::cout << INVERSE << YELLOW << "------------------------------------------------------------" << RESET << std::endl;

	delete randonAnimal;
	delete dogAnimal;
	delete catAnimal;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
