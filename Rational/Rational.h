#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int numerator;
	int denominator;
	void reduce();
public:
	Rational();
	Rational(int num, int den);
	
	friend Rational operator+(const Rational &r1, const Rational &r2);
	friend Rational operator+(const Rational &r);
	Rational &operator+=(const Rational &r);
	friend Rational operator-(const Rational &r1, const Rational &r2);
	friend Rational operator-(const Rational &r);
	Rational &operator-=(const Rational &r);
	friend Rational operator*(const Rational &r1, const Rational &r2);
	Rational &operator*=(const Rational &r);
	friend Rational operator/(const Rational &r1, const Rational &r2);
	Rational &operator/=(const Rational &r);

	friend std::istream &operator>>(std::istream &is, Rational &r);
	friend std::ostream &operator<<(std::ostream &os, const Rational &r);

	double to_double() const;
/*
	void print_double() const;
	void print_str() const;
*/
};

#endif