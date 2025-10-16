#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	return (*this);
}

Fixed::Fixed(const Fixed &obj)
{

}

Fixed::~Fixed()
{

}

int Fixed::getRawBits() const{
	return value;
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
