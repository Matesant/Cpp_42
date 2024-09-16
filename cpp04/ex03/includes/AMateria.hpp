
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Utils.hpp"
# include "ICharacter.hpp"

class AMateria
{
  public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria();

	// Getters
	std::string const &getType() const;

	// Member functions
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

  protected:
	std::string _type;
};

#endif
