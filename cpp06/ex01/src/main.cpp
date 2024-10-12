#include "./Serializer.hpp"

int	main(void)
{
	Data *data = new Data;

	data->name = "John";
	data->id = 42;
	data->value = 3.14f;
	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "--------------- data before serialization ---------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	newLine();
	std::cout << BLUE << "id: " << data->id << RESET << std::endl;
	std::cout << BLUE << "name: " << data->name << RESET << std::endl;
	std::cout << BLUE << "value: " << data->value << RESET << std::endl;
	std::cout << BLUE << "data: " << data << RESET << std::endl;
	newLine();
	uintptr_t raw = Serializer::serialize(data);

	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "--------------- data after serialization ----------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	
	newLine();
	std::cout << BLUE << "raw: " << raw << RESET << std::endl;
	newLine();
	
	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "--------------- data after deserialization --------------" << RESET << std::endl;
	std::cout << YELLOW << INVERSE << "---------------------------------------------------------" << RESET << std::endl;
	
	newLine();
	Data *data2 = Serializer::deserialize(raw);
	newLine();
	std::cout << BLUE << "id: " << data2->id << RESET << std::endl;
	std::cout << BLUE << "name: " << data2->name << RESET << std::endl;
	std::cout << BLUE << "value: " << data2->value << RESET << std::endl;
	std::cout << BLUE << "data2: " << data2 << RESET << std::endl;
	newLine();

	delete data;
	return (0);
}
