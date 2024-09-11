#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &rhs);
	virtual ~MateriaSource();

	// Member functions
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

  private:
	AMateria *_materia[4];
};

#endif
