#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int f_number;
		static const int bits_frac;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		void operator = (const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif