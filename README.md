# CPP02

C++ Module 02: fixed-point arithmetic class with Orthodox Canonical Form, operator overloading, and a geometric BSP (Binary Space Partitioning) exercise.

## Project Overview
- What it does: implements a `Fixed` class representing fixed-point numbers (8 fractional bits), with full operator overloading and a point-in-triangle test.
- Core themes: OCF (default/copy/assign/destructor), operator overloading, `static` methods.

## Architecture & Design
- **ex00**: bare `Fixed` class with OCF — `getRawBits()`/`setRawBits()`, `static const int fractBits = 8`.
- **ex01**: add `Fixed(int)` and `Fixed(float)` constructors, `toFloat()`/`toInt()` conversions, `operator<<` for stream output.
- **ex02**: add all 6 comparison operators (`<`, `>`, `<=`, `>=`, `==`, `!=`), 4 arithmetic operators (`+`, `-`, `*`, `/`), pre/post increment/decrement, and `static min()`/`max()`.
- **ex03 (BSP)**: `Point` class (two `Fixed` members); `bsp()` function determines if a point lies inside a triangle using cross-product area tests.

## Core Concepts (with code)
- Fixed-point class with OCF:
```cpp
// Fixed.hpp
class Fixed {
    int value;
    static const int fractBits;  // = 8
public:
    Fixed();
    Fixed(const Fixed& obj);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
```
- Arithmetic operator overload:
```cpp
// Fixed.cpp (ex02)
Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}
```

## Code Walkthrough
1) ex00: OCF implementation with verbose constructor/destructor messages to trace object lifecycle.
2) ex01: bit-shifting for int→fixed (`value = n << fractBits`), rounding for float→fixed (`roundf(n * (1 << fractBits))`).
3) ex02: full operator suite; `min`/`max` as static methods returning references.
4) ex03: BSP uses sign of cross products to determine point position relative to triangle edges.

## Installation & Setup
- `make` per exercise (C++98).

## Technical Deep Dive
- 8 fractional bits = 1/256 precision (~0.004 resolution).
- Multiplication via `toFloat()` avoids overflow from raw fixed-point multiply.
- BSP uses the sign-of-area method: point is inside if all three cross products have the same sign.

## Improvements & Future Work
- Add overflow detection for fixed-point arithmetic.
- Implement fixed-point division without float conversion.

## Author
Oualid Obbad (@oualidobbad)