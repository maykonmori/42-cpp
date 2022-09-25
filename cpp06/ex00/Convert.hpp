#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cctype>


class Convert
{
protected:
    std::string _input;
    int _int;
    float _float;
    double _double;
    char _char;

public:
    Convert();
    Convert(std::string input);
	Convert(const Convert &ref);
    Convert	&operator=(Convert const &ref);
    ~Convert();
	void toInt( void );
	void toChar( void );
	void toFloat( void );
	void toDouble( void );
	bool isFloat( void );
	bool isPoint( void );
    void parse();
    void printInf();
    void printNan();
    void validate();
    void print();
    void special();
};



#endif