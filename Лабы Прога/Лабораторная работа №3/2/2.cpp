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

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0) {
			vec.erase(vec.begin() + i);
		}
	}

	cout << "New massiv: " << endl;
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}


	return 0;
}

