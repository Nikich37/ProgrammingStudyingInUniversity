#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	multiset <int> A;
	multiset <int> B;

	cout << "Введите размер первого множества: ";
	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		A.insert(temp);
	}

	cout << "Введите размер второго множества: ";
	int b;
	cin >> b;

	for (int i = 0; i < b; i++) {
		int temp;
		cin >> temp;
		B.insert(temp);
	}

	multiset <int> uni = A;
	for (auto it = B.begin(); it != B.end(); it++)
	{
		uni.insert(*it);
	}

	multiset <int> enter;
	for (auto itA = A.begin(); itA != A.end(); itA++)
		for (auto itB = B.begin(); itB != B.end(); itB++)
			if (*itB == *itA)
				enter.insert(*itA);

	multiset <int> A_B;
	vector <int> b_temp;
	for (auto itB = B.begin(); itB != B.end(); itB++) {
		b_temp.push_back(*itB);
	}
	int n = b_temp.size();
	for (auto itA = A.begin(); itA != A.end(); itA++) {
		bool cond = true;
		for (int i = 0; i < n; i++) {
			if (*itA == b_temp[i]) {
				cond = false;
				b_temp.erase(b_temp.begin() + i);
				n--;
				break;
			}
		}
		if (cond)
			A_B.insert(*itA);
	}

	multiset <int> B_A;
	for (auto itB = A.begin(); itB != A.end(); itB++) {
		b_temp.push_back(*itB);
	}
	n = b_temp.size();
	for (auto itA = B.begin(); itA != B.end(); itA++) {
		bool cond = true;
		for (int i = 0; i < n; i++) {
			if (*itA == b_temp[i]) {
				cond = false;
				b_temp.erase(b_temp.begin() + i);
				n--;
				break;
			}
		}
		if (cond)
			B_A.insert(*itA);
	}

	cout << "Uni: ";
	for (auto t : uni) {
		cout << t << ' ';
	}

	cout << "Enter: ";
	for (auto t : enter) {
		cout << t << ' ';
	}

	cout << "Comp A - B: ";
	for (auto t : A_B) {
		cout << t << ' ';
	}

	cout << "Comp B - A: ";
	for (auto t : B_A) {
		cout << t << ' ';
	}
	return 0;
}
