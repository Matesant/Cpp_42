
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &rhs);
	virtual ~Cure();

	// Member functions
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
