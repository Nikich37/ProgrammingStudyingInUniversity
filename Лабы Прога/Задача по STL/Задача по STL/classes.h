#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Clumb {
private:
	string clumb_number;
	string clumb_shape;
	vector <string> clumb_flowers;
public:
	Clumb() {};
	Clumb(string number, string shape, vector <string> flowers) {
		this->clumb_number = number;
		this->clumb_shape = shape;
		this->clumb_flowers = flowers;
	}
	string get_number() {
		return clumb_number;
	}
	string get_shape() {
		return clumb_shape;
	}
	string get_flowers() {
		string flowers = "";
		for (int flower = 0; flower < clumb_flowers.size(); flower++) {
			flowers = flowers + clumb_flowers[flower] + " ";
		}
		return flowers;
	}
	vector <string> get_flowers_vector() {
		return clumb_flowers;
	}
};

