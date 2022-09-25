#if !defined(ARRAY_HPP)
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	int _size;
public:
	Array(/* args */){
		std::cout << "Array default constructor called" << std::endl;
		this->_size = 0;        
	}
	Array(unsigned int n){
		std::cout << "Array constructor called with value." << std::endl;
		this->_array = new T[n];
		this->_size = n;
	}
	~Array(){
		std::cout << "Array destructor called" << std::endl;
	}
};

#endif // ARRAY_HPP