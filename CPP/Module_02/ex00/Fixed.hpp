#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int 				_value;
		static const int	_point;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
