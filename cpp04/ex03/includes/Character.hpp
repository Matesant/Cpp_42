#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
#include "ICharacter.hpp"


class Character : public ICharacter
{
  public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	Character &operator=(const Character &rhs);
	virtual ~Character();

	// Getters
	std::string const &getName() const;

	// Member functions
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

  private:
	std::string _name;
	AMateria *_materia[4];
};

#endif
