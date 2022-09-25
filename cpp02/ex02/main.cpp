#include "Fixed.hpp"

/**
* Cria dois objetos Fixed, um com o construtor padrão e outro com o construtor de cópia, 
* depois os imprime, incrementa o primeiro, multiplica por dois, imprime, incrementa, imprime, 
* imprime o segundo, imprime o máximo dos dois, e retorna 0
*/
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a:  " << a << std::endl;
	std::cout << "++a:" << ++a << std::endl;
	std::cout << "2a: " << a << std::endl;
	std::cout << "a++:" << a++ << std::endl;
	std::cout << "3a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;

	std::cout << "max: " << Fixed::max( a, b ) << std::endl;

	return 0;
}