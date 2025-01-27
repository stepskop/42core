#include "Fixed.hpp"

const int Fixed::_point = 8;

Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _value(value << this->_point) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value): _value(roundf(value * (1 << this->_point))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

std::ostream &operator << (std::ostream &out, const Fixed &src) {
	out << src.toFloat();
	return out;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return this->_value >> this->_point;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_point);
}
