#include <iostream>
#include <cmath>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	double x, y, s;
	cout << "¬ведите X: ";
	cin >> x;
	cout << "¬ведите Y: ";
	cin >> y;

	if (x > y)
		s = y * sqrt(fabs(x)) + 3 * sin(x);
	if (x < y)
		s = x * sqrt(fabs(x));
	if (x == y)
		s = pow(fabs(x), 1. / 3) + pow(x, 3) / y;

	cout << "s = " << s;

}
