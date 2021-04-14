#include <iostream>
#include <vector>
using namespace std;
int main() {

	int n;
	cout << "Vvedite razmer massiva: ";
	cin >> n;
	vector<double> vec(n);


	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	int counter_zero = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (vec[i + counter_zero] == 0) {
			vec.insert(vec.begin(), vec[i + counter_zero]);
			counter_zero++;
		}
	}

	int j = 0;
	while (j != counter_zero) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (vec[i] == 0) {
				vec.erase(vec.begin() + i);
				j++;
				break;
			}
		}
	}

	int counter_neg = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (vec[i + counter_neg] < 0) {
			vec.insert(vec.begin(), vec[i + counter_neg]);
			counter_neg++;
		}
	}

	j = 0;
	while (j != counter_neg) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (vec[i] < 0) {
				vec.erase(vec.begin() + i);
				j++;
				break;
			}
		}
	}

	

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	return 0;

}





