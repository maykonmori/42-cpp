#include "Fixed.hpp"

const int Fixed::bits_frac = 8;

/**
 * Ele define o valor do número do ponto fixo para 0.
 */
Fixed::Fixed()
{
	this->f_number = 0;
}

/**
 * Destruidor da classe Fixed.
 */
Fixed::~Fixed()
{
}

/**
 * Copie o valor do parâmetro no objeto
 */
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

/**
 * Ele pega um número inteiro e o converte em um número de ponto fixo
 */
Fixed::Fixed(const int fixed){
	this->f_number = (int)fixed << this->bits_frac;
}

/**
 * Ele pega um float como parâmetro, arredonda para o inteiro mais próximo e depois o multiplica por 2 
 * elevado a 8
 */
Fixed::Fixed(const float fixed){
	this->f_number = (int)roundf(fixed * (1 << this->bits_frac));
}

/**
 * Ele retorna o valor do ponto fixo armazenado na instância da classe.
 */
int Fixed::getRawBits(void)const{
	return (this->f_number);
}

/**
 * Ele define o valor do ponto fixo para o valor bruto passado como parâmetro.
 */
void Fixed::setRawBits(int const raw){
	this->f_number = raw;
}

/**
 * Se o objeto não for igual ao passado como parâmetro, atribua o valor do parâmetro ao objeto.
 */
Fixed &Fixed::operator= (const Fixed &fixed){
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
 * A função recebe uma referência a um objeto ostream e uma referência 
 * a um objeto Fixed como parâmetros e retorna uma referência a um objeto ostream
 */
std::ostream &operator<<(std::ostream &out, const Fixed &num){
	out << num.toFloat();
	return (out);
}

/**
 * Ele compara o valor do objeto atual com o valor do objeto passado como parâmetro.
 */
bool Fixed::operator> (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 > f2 ? true : false);
}

/**
 * Ele compara o valor do objeto atual com o valor do objeto passado como parâmetro.
 */
bool Fixed::operator< (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 < f2 ? true : false);
}

/**
 * Ele compara o valor do objeto atual com o valor do objeto passado como parâmetro.
 */
bool Fixed::operator>= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 >= f2 ? true : false);
}

/**
 * Ele compara o valor do objeto atual com o valor do objeto passado como parâmetro.
 */
bool Fixed::operator<= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 <= f2 ? true : false);
}

/**
 * Ele compara os dois floats e retorna true se forem iguais.
 */
bool Fixed::operator== (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 == f2 ? true : false);
}

/**
 * Ele compara os dois floats e retorna true se eles não forem iguais.
 */
bool Fixed::operator!= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return(f1 != f2 ? true : false);
}

/**
 * Ele retorna um novo objeto Fixo que é a soma do objeto atual e do parâmetro.
 */
Fixed Fixed::operator+ (const Fixed &fixed){
	Fixed aux(this->toFloat() + fixed.toFloat());
	return (aux);
}

/**
 * Retorna um novo objeto Fixo que é o resultado da subtração do objeto atual 
 * e daquele passado como parâmetro
 */
Fixed Fixed::operator- (const Fixed &fixed){
	Fixed aux(this->toFloat() - fixed.toFloat());
	return (aux);
}

/**
 * Ele pega um objeto Fixo como parâmetro, multiplica-o pelo objeto atual e retorna 
 * o resultado como um novo objeto Fixo
 */
Fixed Fixed::operator* (const Fixed &fixed){
	Fixed aux(this->toFloat() * fixed.toFloat());
	return (aux);
}

/**
 * Ele divide o valor do objeto atual pelo valor do objeto passado como parâmetro e retorna o resultado
 */
Fixed Fixed::operator/ (const Fixed &fixed){
	Fixed aux(this->toFloat() / fixed.toFloat());
	return (aux);
}

/**
 * Esta função incrementa o valor do objeto em 1.
 */
Fixed &Fixed::operator++ (void){
	this->f_number++;
	return (*this);
}

/**
 * Ele retorna o valor do objeto antes de ser incrementado.
 */
Fixed Fixed::operator++ (int){
	Fixed holder = *this;
	this->f_number++;
	return (holder);
}

/**
 * Diminua o valor do valor do ponto fixo em 1.
 */
Fixed &Fixed::operator-- (void){
	this->f_number--;
	return (*this);
}

/**
 * Ele retorna o valor do objeto antes de ser decrementado.
 */
Fixed Fixed::operator-- (int){
	Fixed holder = *this;
	this->f_number--;
	return (holder);
}

/**
 * Se f1 for menor que f2, retorne f1, caso contrário, retorne f2.
 */
Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1 < f2)
		return f1;
	return f2;
}

/**
 * Se f1 for menor que f2, retorne f1, caso contrário, retorne f2.
 */
const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2){
	if (f1 < f2)
		return f1;
	return f2;
}

/**
 * Se f1 for maior que f2, retorne f1, caso contrário, retorne f2.
 */
Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1 > f2)
		return f1;
	return f2;
}

/**
 * Se f1 for maior que f2, retorne f1, caso contrário, retorne f2.
 */
const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2){
	if (f1 > f2)
		return f1;
	return f2;
}