#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <set>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string str;
	ifstream text;
	text.open("C:\\Users\\nikit\\OneDrive\\Рабочий стол\\Лабы Прога\\Лабораторная работа №5\\2\\string.txt");
	getline(text, str);
	int cntr = 0;
	int n = str.length();
	if (str.length() != 0) cntr++;
	for (int i = 1; i < n - 1; i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
		{
			cntr++;
		}
	}
	if (str[0] == ' '){
		cout << " count = 0";
		return 0;
	}
	cout << "count = " << cntr;
	return 0;
}