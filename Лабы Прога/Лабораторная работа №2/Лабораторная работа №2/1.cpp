#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	double x, y, temp;
	cout << "¬ведите X: ";
	cin >> x;
	cout << "¬ведите Y: ";
	cin >> y;

	if (x > y) {
		temp = x;
		x = y;
		y = temp;
	}
	cout << "X = " << x << ", Y = " << y;
	return 0;
}