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
 * Copie o valor do parâmetro no objeto
 */
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/**
 * Fixed::Fixed(const int fixed) é um construtor que recebe um int como parâmetro e o 
 * atribui à variável membro f_number
 */
Fixed::Fixed(const int fixed){
	std::cout << "Int constructor called" << std::endl;
	this->f_number = (int)fixed << this->bits_frac;
}

/**
 * Ele pega um float como parâmetro, arredonda para o inteiro mais próximo e 
 * depois o multiplica por 2 elevado a 8
 */
Fixed::Fixed(const float fixed){
	std::cout << "Float constructor called" << std::endl;
	this->f_number = (int)roundf(fixed * (1 << this->bits_frac));
}

/**
 * Ele retorna o valor do ponto fixo armazenado no objeto que o chama.
 */
int Fixed::getRawBits(void)const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->f_number);
}

/**
 * Ele define o valor do ponto fixo para o valor bruto passado como parâmetro.
 */
void Fixed::setRawBits(int const raw){
	this->f_number = raw;
}

/**
 * Se o objeto atribuído não for o mesmo que o objeto atribuído, 
 * atribua o valor do objeto atribuído ao objeto atribuído
 */
Fixed &Fixed::operator= (const Fixed &fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->f_number = fixed.getRawBits();
	return (*this);
}

/**
 * Retorna a parte inteira do número de ponto fixo
 */
int Fixed::toInt()const{
	return((int)this->f_number >> Fixed::bits_frac);
}

/**
 * Retorna o valor do número do ponto fixo como um float
 */
float Fixed::toFloat()const{
	return((float)(this->f_number) / (1 << this->bits_frac));
}

/**
 * Ele recebe um objeto Fixed e um objeto ostream como parâmetros e retorna um objeto ostream
 */
std::ostream &operator<<(std::ostream &out, const Fixed &num){
	out << num.toFloat();
	return (out);
}