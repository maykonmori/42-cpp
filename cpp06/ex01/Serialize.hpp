#ifndef SEREALIZE_HPP
#define SEREALIZE_HPP

#include <stdint.h>
#include <iostream>

typedef struct s_Data
{
	int value;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif