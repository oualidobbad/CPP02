#include "Fixed.hpp"

int const Fixed::fractBits = 8;

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (nb * (1 << fractBits));
}

Fixed::Fixed(const float nb_f){

	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(nb_f * (1 << fractBits));
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->value = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{

	return value;
}

void Fixed::setRawBits( int const raw )
{	
	this->value = raw;
}

int Fixed::toInt( void ) const {
	return this->value / (1 << fractBits);
}

float Fixed::toFloat( void ) const{
	return (float)this->value / (1 << fractBits);
}
