#include "Fixed.hpp"

/**
 * Ele cria três objetos Fixos, atribui o segundo ao terceiro e exibe os bits 
 * brutos de cada objeto
 */
int main( void ) {

	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return(0);
}