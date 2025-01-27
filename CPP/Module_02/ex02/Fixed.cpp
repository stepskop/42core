#include "Fixed.hpp"

const int Fixed::_point = 8;

Fixed::Fixed(void): _value(0) {
}

Fixed::Fixed(const int value): _value(value << this->_point) {
}

Fixed::Fixed(const float value): _value((int)roundf(value * (1 << this->_point))) {
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed(void) {
}

Fixed &Fixed::operator = (const Fixed &src) {
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed Fixed::operator + (const Fixed &src) const {
	Fixed res(this->toFloat() + src.toFloat());
	return res;
}

Fixed Fixed::operator - (const Fixed &src) const {
	Fixed res(this->toFloat() - src.toFloat());
	return res;
}

Fixed Fixed::operator / (const Fixed &src) const {
	Fixed res(this->toFloat() / src.toFloat());
	return res;
}

Fixed Fixed::operator * (const Fixed &src) const {
	Fixed res(this->toFloat() * src.toFloat());
	return res;
}

bool Fixed::operator == (const Fixed &src) const {
	return this->_value == src.getRawBits();
}

bool Fixed::operator < (const Fixed &src) const {
	return this->_value < src.getRawBits();
}

bool Fixed::operator > (const Fixed &src) const {
	return this->_value > src.getRawBits();
}

bool Fixed::operator <= (const Fixed &src) const {
	return this->_value <= src.getRawBits();
}

bool Fixed::operator >= (const Fixed &src) const {
	return this->_value >= src.getRawBits();
}

bool Fixed::operator != (const Fixed &src) const {
	return this->_value != src.getRawBits();
}

Fixed &Fixed::operator ++ ( void ) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator ++ ( int ) {
	Fixed tmp = *this;
	this->_value++;
	return tmp;
}

Fixed &Fixed::operator -- ( void ) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator -- ( int ) {
	Fixed tmp = *this;
	this->_value--;
	return tmp;
}

std::ostream &operator << (std::ostream &out, const Fixed &src) {
	out << src.toFloat();
	return out;
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

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if ( a >= b )
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if ( a >= b )
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if ( a <= b )
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if ( a <= b )
		return a;
	return b;
}
