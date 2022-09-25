#include "Serialize.hpp"

int main(void)
{
	Data *data = new Data;

	data->value = 10;
	uintptr_t ptr = serialize(data);

	data = deserialize(ptr);

	std::cout << data->value << std::endl;
	return 0;
}