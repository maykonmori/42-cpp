#include "Fixed.hpp"

const int Fixed::bits_frac = 8;

/**
 * Fixed::Fixed() é um construtor que inicializa o valor do ponto fixo para 0
 */
Fixed::Fixed()
{
	this->f_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

/**
 * O destruidor é chamado quando o objeto é destruído
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * Construtor de cópia chamado quando um objeto é inicializado com outro objeto do mesmo tipo
 */
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/**
 * O operador de atribuição de cópia é chamado quando um objeto já inicializado recebe 
 * um novo valor de outro objeto existente.
 */
void Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->f_number = fixed.getRawBits();
}

/**
 * Ele retorna o valor do valor de ponto fixo armazenado no objeto que o chama
 */
int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->f_number);
}

/**
 * Ele define o valor do ponto fixo para o valor bruto passado como parâmetro.
 */
void Fixed::setRawBits(int const raw){
	this->f_number = raw;
}