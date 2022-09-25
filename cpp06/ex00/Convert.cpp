#include "Convert.hpp"

/**
 * Convert::Convert() is a constructor for the class Convert.
 */
Convert::Convert(){}

/**
 * This function takes a string as an argument and sets the value of the private variable _input to the
 * value of the argument.
 * 
 * @param input The string to be converted.
 */
Convert::Convert(std::string input){
	this->_input = input;
}

/**
 * This function is a copy constructor that takes a reference to a Convert object and copies the value
 * of the _input variable from the referenced object to the _input variable of the object that called
 * the function.
 * 
 * @param ref The reference to the object that is being copied.
 */
Convert::Convert(const Convert &ref){
	this->_input = ref._input;
}

/**
 * If the object being assigned to is not the same as the object being assigned, assign the object
 * being assigned to the object being assigned.
 * 
 * @return A reference to the object that was assigned to.
 */
Convert	&Convert::operator=(Convert const &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}

/**
 * The destructor is called when the object is destroyed.
 */
Convert::~Convert(){}

/**
 * It converts the string to an integer, then converts the integer to a float, double, and char
 */
void Convert::toInt(){
	std::stringstream temp(this->_input.c_str());
	
	temp >> this->_int;
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	this->_char = static_cast<char>(this->_int);
}

/**
 * It takes the input string, converts it to a char, and then converts the char to a float, double, and
 * int
 */
void Convert::toChar(){
	std::stringstream temp(this->_input.c_str());
	std::cout << this->_input.c_str() << std::endl;
	
	temp >> this->_char;
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
	this->_int = static_cast<int>(this->_char);
}

/**
 * It converts the input string to a float, then converts the float to an int, double, and char
 */
void Convert::toFloat(){
	std::stringstream temp(this->_input.c_str());
	
	temp >> this->_float;
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
	this->_char = static_cast<char>(this->_float);
}

/**
 * This function takes the input string and converts it to a double, then converts the double to a
 * float, char, and int
 */
void Convert::toDouble(){
	std::stringstream holder(this->_input.c_str());
	
	holder >> this->_double;
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
}

/**
 * This function parses the input string and converts it to a double
 */
void Convert::parse(){
	this->special();
	this->validate();
	this->print();
}

/**
 * It prints the result of the conversion of the input string into a char, int, float and double
 */
void Convert::printInf(){
	if (this->_input == "inff" || this->_input == "+inff" || this->_input == "inf" || this->_input == "+inf"){
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " <<  "inf"<< std::endl;
	} else if (this->_input == "-inff"  || this->_input == "-inf" ){
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " <<  "-inf"<< std::endl;
	} else {
		std::cerr << "invalid convertion" << std::endl;
	}
	this->~Convert();
	std::exit(0);
}

/**
 * It prints "impossible" for char and int, "nanf" for float, and "nan" for double.
 */
void Convert::printNan(){
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " <<  "nan"<< std::endl;
	this->~Convert();
	std::exit(0);
}

/**
 * It checks if the input is a number, a float, a double, or a char
 */
void Convert::validate(){
	int i = 0;

	if((this->_input[i] >= '0' && this->_input[i] <= '9') || this->_input[i] == '-' || this->_input[i] == '+')
	{
		if(this->_input[i] == '-' || this->_input[i] == '+')
			i++;
		while(std::isdigit(this->_input[i]))
			i++;
		if (this->_input[i] == '\0'){
			this->toInt();
		} else if (this->_input[i] == '.'){
			i++;
			if (this->_input[i] == '\0'){
				std::cerr << "invalid convertion" << std::endl;
				this->~Convert();
				std::exit(0);
			}
			while (std::isdigit(this->_input[i]))
				i++;
			if (this->_input[i] == 'f' && this->_input[i + 1] == '\0'){
				this->toFloat();
			} else if (this->_input[i] == '\0') {
				this->toDouble();
			} else {
				std::cerr << "invalid convertion" << std::endl;
				this->~Convert();
				std::exit(0);
			}
		} else {
			std::cerr << "invalid convertion" << std::endl;
			this->~Convert();
			std::exit(0);
		}
	} else if (std::isalpha(this->_input[i])) {
		if (this->_input.length() > 1){
			std::cerr << "invalid convertion" << std::endl;
			this->~Convert();
			std::exit(0);
		}
		this->toChar();
	}
}

/**
 * It prints the value of the class' attributes, with the appropriate format
 */
void Convert::print(){
	std::cout << "char: " ;
	if (std::isprint(this->_char))
		std ::cout << this->_char << std::endl;
	else
		std ::cout << "Not displayable" << std::endl;
	
	std::cout << "int: " << this->_int << std::endl;
	
	std::cout << "float: " << this->_float ;
	if (this->_input.find('.') == static_cast<size_t>(-1))
		std::cout << ".0" ;
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << this->_double ;
	if (this->_input.find('.') == static_cast<size_t>(-1))
		std::cout << ".0" ;
	std::cout << std::endl;
}

/**
 * @brief If the input is "inf" or "nan", print the corresponding value
 */
void Convert::special(){
	int i = 0;
	if(this->_input[i] == '-' || this->_input[i] == '+')
			i++;
	if (!this->_input.compare(i, 3, "inf")){
		this->printInf();
	} else if (this->_input == "nan" || this->_input == "nanf"){
		this->printNan();
	}
}
