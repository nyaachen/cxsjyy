#include <cstdio>
#include <iostream>

#include "Rational.h"


int find_gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

void Rational::reduce() {
	if (denominator == 0) throw		"Constructing a Rational with its denominator = 0!"; // The <exception> standard library is unavailable in VS2010?
	if (numerator == 0) denominator = 1;
	else {
		bool symbol = (numerator*denominator<0);
		numerator = numerator<0?-numerator:numerator;
		denominator = denominator<0?-denominator:denominator;
		int common = find_gcd(numerator, denominator);
		numerator /= common;
		denominator /= common;
		if (symbol) numerator = -numerator;
	}
}

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int den) : numerator(num), denominator(den) {
	reduce();
}

Rational operator+(const Rational &r1, const Rational &r2) {
	return Rational(r1.numerator*r2.denominator + r1.denominator*r2.numerator, r1.denominator*r2.denominator);
}

Rational operator+(const Rational &r) {
	return r;
}

Rational &Rational::operator+=(const Rational &r){
	numerator = numerator * r.denominator + denominator * r.numerator;
	denominator *= r.denominator;
	reduce();
	return *this;
}

Rational operator-(const Rational &r1, const Rational &r2){
	return Rational(r1.numerator*r2.denominator - r1.denominator*r2.numerator, r1.denominator*r2.denominator);
}

Rational operator-(const Rational &r) {
	return Rational(-r.numerator, r.denominator);
}

Rational &Rational::operator-=(const Rational &r){
	numerator = numerator * r.denominator - denominator * r.numerator;
	denominator *= r.denominator;
	reduce();
	return *this;
}

Rational operator*(const Rational &r1, const Rational &r2){
	return Rational(r1.numerator*r2.numerator, r1.denominator*r2.denominator);
}

Rational &Rational::operator*=(const Rational &r){
	numerator *= r.numerator;
	denominator *= r.denominator;
	reduce();
	return *this;
}
Rational operator/(const Rational &r1, const Rational &r2){
	return Rational(r1.numerator*r2.denominator,r1.denominator*r2.numerator);
}

Rational &Rational::operator/=(const Rational &r){
	numerator *= r.denominator;
	denominator *= r.numerator;
	reduce();
	return *this;
}

std::istream &operator>>(std::istream &is, Rational &r) {
	char ch;
	int a, b;
	is >> a >> ch >> b;
	if(is.fail()) {
		;
	}
	else {
		r.numerator = a;
		r.denominator = b;
		r.reduce();
	}
	return is;
}
std::ostream &operator<<(std::ostream &os, const Rational &r) {
	os << r.numerator << "/" << r.denominator;
	return os;
}

double Rational::to_double() const {
	return (double) numerator / denominator;
}

/*
void Rational::print_double() const {
	printf("%f", (double) numerator / denominator);
}

void Rational::print_str() const {
	if (numerator == 0) printf("0");
	else printf("%d/%d", numerator, denominator);
}
*/