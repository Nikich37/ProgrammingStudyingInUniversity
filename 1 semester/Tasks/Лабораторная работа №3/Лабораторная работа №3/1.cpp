#include <iostream>
#include <vector>
using namespace std;
int main() {

	int n;
	cout << "Vvedite razmer massiva: ";
	cin >> n;
	vector<double> vec(n);


	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	double sum_pos = 0;
	int counter_pos = 0;
	double sum_neg = 0;
	int counter_neg = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > 0) {
			sum_pos = sum_pos + vec[i];
			counter_pos++;
		}
		if (vec[i] < 0) {
			sum_neg = sum_neg + vec[i];
			counter_neg++;
		}
	}

	cout << "Srednee arifmeticheskoe polozhytelnyh: " << sum_pos / counter_pos << "\n";
	cout << "Srednee arifmeticheskoe otricatelnyh: " << sum_neg / counter_neg;

	return 0;
}



	