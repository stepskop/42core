#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int 				_value;
		static const int	_point;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed &operator = (const Fixed &src);
		Fixed operator + (const Fixed &src) const;
		Fixed operator - (const Fixed &src) const;
		Fixed operator / (const Fixed &src) const;
		Fixed operator * (const Fixed &src) const;

		Fixed &operator ++ (void);
		Fixed operator ++ (int);
		Fixed &operator -- (void);
		Fixed operator -- (int);

		bool	operator < (const Fixed &src) const;
		bool	operator > (const Fixed &src) const;
		bool	operator <= (const Fixed &src) const;
		bool	operator >= (const Fixed &src) const;
		bool	operator == (const Fixed &src) const;
		bool	operator != (const Fixed &src) const;
		
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);

		int		toInt(void) const;
		float 	toFloat(void) const;

		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};
std::ostream &operator << (std::ostream &out, const Fixed &src);
#endif
