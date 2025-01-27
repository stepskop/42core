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
		Fixed &operator = (const Fixed &src);
		~Fixed(void);

		int 	getRawBits(void) const;
		void	setRawBits(const int raw);

		int		toInt(void) const;
		float 	toFloat(void) const;
};
std::ostream &operator << (std::ostream &out, const Fixed &src);
#endif
