#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Utils.hpp"
#include "Data.hpp"

// Class declaration
class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &rhs);
	~Serializer();

  public:
	// methods
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif // SERIALIZER_HPP
