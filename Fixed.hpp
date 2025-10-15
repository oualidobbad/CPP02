#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractBits;

	public:
	Fixed();
	Fixed(const Fixed &obj);

};
