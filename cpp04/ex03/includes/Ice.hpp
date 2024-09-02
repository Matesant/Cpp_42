
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
  public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &rhs);
	virtual ~Ice();

	// Member functions
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
