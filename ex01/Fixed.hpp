#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractBits;

	public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed &obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
