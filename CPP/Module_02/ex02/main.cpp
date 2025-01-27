#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	Fixed c = a;
    std::cout << Fixed::min(c, b) << std::endl; // 0.0078125
    std::cout << b / Fixed(2) << std::endl; // 5.05078
    std::cout << b + Fixed(-3.14f) << std::endl; // 6.96094
    std::cout << b - Fixed(18) << std::endl; // -7.89844
    std::cout << (c != a) << std::endl; // 0
    std::cout << (c == a) << std::endl; // 1
	std::cout << Fixed ( 8 ) - Fixed( -2.4f ) << std::endl;
	return 0;
}
