#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	double x, y, temp;
	cout << "������� X: ";
	cin >> x;
	cout << "������� Y: ";
	cin >> y;

	if (x > y) {
		temp = x;
		x = y;
		y = temp;
	}
	cout << "X = " << x << ", Y = " << y;
	return 0;
}