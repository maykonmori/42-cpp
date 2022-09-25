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
		~Fixed();

		Fixed	&operator = (const Fixed &fixed);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat()const;
		int		toInt()const;

		bool operator> (const Fixed &fixed)const;
		bool operator< (const Fixed &fixed)const;
		bool operator>= (const Fixed &fixed)const;
		bool operator<= (const Fixed &fixed)const;
		bool operator== (const Fixed &fixed)const;
		bool operator!= (const Fixed &fixed)const;

		Fixed operator+ (const Fixed &fixed);
		Fixed operator- (const Fixed &fixed);
		Fixed operator* (const Fixed &fixed);
		Fixed operator/ (const Fixed &fixed);

		Fixed operator++ (int);
		Fixed &operator++ (void);
		Fixed operator-- (int);
		Fixed &operator-- (void);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(Fixed const &f1, Fixed const &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(Fixed const &f1, Fixed const &f2);

};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif