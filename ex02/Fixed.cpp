#include "Fixed.hpp"

int const Fixed::fractBits = 8;

Fixed::Fixed()
{
	this->value = 0;
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = (nb * (1 << fractBits));
}
Fixed::Fixed(const float nb_f){

	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(nb_f * (1 << fractBits));
}
Fixed& Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
	return (float) this->value / (1 << fractBits);
}


//=============The 6 comparison operators: >, <, >=, <=, ==, and !=.=======================
bool Fixed::operator>(const Fixed &obj) const{

	return this->value > obj.value;
}
bool Fixed::operator<(const Fixed &obj) const{
	
	return this->value < obj.value;
}
bool Fixed::operator>=(const Fixed &obj) const{
	
	return this->value >= obj.value;
}
bool Fixed::operator<=(const Fixed &obj) const{
	
	return this->value <= obj.value;
}
bool Fixed::operator==(const Fixed &obj) const{
	
	return this->value == obj.value;
}
bool Fixed::operator!=(const Fixed &obj) const{
	
	return this->value != obj.value;
}

//===================The 4 arithmetic operators: +, -, *, and /.================
Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed copy;

	copy.value = (this->value + obj.value);
	return copy;
}
Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed copy;

	copy.value = (this->value - obj.value);
	return copy;
}
Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed copy;

	copy.value = (this->value * obj.value) / 256;
	return copy;
}
Fixed Fixed::operator/(const Fixed &obj)
{ 	
	Fixed copy;

	copy.value = (this->value / obj.value) * 256;
	return copy;
}

// (pre-increment and post-increment, pre-decrement and post-decrement)
Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed copy;

	copy = *this;
	this->value++;
	return copy;
}
Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed copy;

	copy = *this;
	this->value--;
	return copy;
}

//==================================static function============================
Fixed Fixed::min(Fixed &obj1, Fixed &obj2)
{

	if (obj1 > obj2)
		return obj2;
	else
		return obj1;
}
Fixed Fixed::min(const Fixed &obj1, const Fixed &obj2)
{

	if (obj1 > obj2)
		return obj2;
	else
		return obj1;
}
Fixed Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 > obj2)
		return obj1;
	else
		return obj2;
}
Fixed Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 > obj2)
		return obj1;
	else
		return obj2;
}

