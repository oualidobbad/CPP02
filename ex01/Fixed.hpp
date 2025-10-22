#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractBits;

	public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed &obj);
	Fixed (const int nb);
	Fixed (const float nb_f);
	float toFloat( void ) const;
	int toInt( void ) const;
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
