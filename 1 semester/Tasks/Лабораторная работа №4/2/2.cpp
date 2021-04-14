#include <iostream>
#include <vector>

using namespace std;

int kor(int n) {
	if (n < 10)
		return n;
	else {
		int sum = 0;
		while (n) {
			sum = n % 10 + sum;
			n /= 10;
		}
		kor(sum);
	}
}
		



	int main(){
		cout << kor(11111);
	}