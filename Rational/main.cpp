#include <iostream>

#include "Rational.h"

using namespace std;

int main() {
	Rational r1, r2;
	cout << "Please input Rational R1 and R2:" << endl;
	cin >> r1 >> r2;

	cout << "R1 R2:" << endl;

	cout << r1 << "\t" << r1.to_double() << endl;

	cout << r2 << "\t" << r2.to_double() << endl;

	cout << "R1+R2, R1-R2, R1*R2, R1/R2" << endl;
	Rational r;
	r = r1 + r2;
	cout << r << "\t" << r.to_double() << endl;

	r = r1 - r2;
	cout << r << "\t" << r.to_double() << endl;

	r = r1 * r2;
	cout << r << "\t" << r.to_double() << endl;

	r = r1 / r2;
	cout << r << "\t" << r.to_double() << endl;

	system("pause");
	return 0;
}