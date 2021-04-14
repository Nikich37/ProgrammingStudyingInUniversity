#pragma once
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Ship {
private:
	string name;
	string port;
	string cargo_volume;
public:
	Ship() {}
	Ship(string name, string port, string cargo_volume) {
		this->name = name;
		this->port = port;
		this->cargo_volume = cargo_volume;
	}
	string get_name() {
		return name;
	}
	string get_port() {
		return port;
	}
	int get_cargo_volume() {
		return stoi(cargo_volume);
	}
	string to_string() {
		return name + " " + port + " " + cargo_volume;
	}

};