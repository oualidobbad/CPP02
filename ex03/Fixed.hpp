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
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		//The 6 comparison operators: >, <, >=, <=, ==, and !=.
		bool operator<(const Fixed &obj) const;
		bool operator>(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		//The 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed &obj);
		Fixed operator-(const Fixed &obj);
		Fixed operator*(const Fixed &obj);
		Fixed operator/(const Fixed &obj);

		//(pre-increment and post-increment, pre-decrement and post-decrement)
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		
		//==================================static function============================
		static Fixed min(Fixed &obj1, Fixed &obj2);
		static Fixed min(const Fixed &obj1, const Fixed &obj2);
		static Fixed max(Fixed &obj1, Fixed &obj2);
		static Fixed max(const Fixed &obj1, const Fixed &obj2);
		
		~Fixed();
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
