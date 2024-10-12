# include "Serializer.hpp"

// Constructor
Serializer::Serializer()
{
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

// Assignment operator=

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

// Destructor

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
