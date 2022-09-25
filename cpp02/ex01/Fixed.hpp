#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int f_number;
		static const int bits_frac;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int fixed);
		Fixed(const float fixed);
		Fixed	&operator = (const Fixed &fixed);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat()const;
		int		toInt()const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif