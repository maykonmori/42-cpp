#include "iter.hpp"

void toLower(char c){
    unsigned char	i;

	i = c;
	if (i >= 'A' && i <= 'Z')
		i = i + 32;
    std::cout << i << std::endl;
}

int main (void){
	std::string string("AdklcoSFDA");

	iter(const_cast<char *>(string.c_str()), string.size(), toLower);
}
