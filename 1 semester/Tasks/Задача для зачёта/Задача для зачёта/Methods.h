#pragma once
#include "Classes.h"

multimap <string, vector<Ship>> ports;
set <string> unique_ports;
vector <Ship> ships;
int cargo_volume_of_port = 0;
int counter_of_ships_of_port = 0;
vector <string> sorted_ports_by_cargo_volume;
vector <string> sorted_ports_by_number_of_ships;
class Methods {
public:
	static void ReadDataFromFile(string file) {
		ifstream text;
		text.open(file);
		string str;
		getline(text, str);
		while (getline(text, str)) {
			stringstream ship_str(str);
			string name;
			getline(ship_str, name, ';');
			string port;
			getline(ship_str, port, ';');
			string cargo_volume;
			getline(ship_str, cargo_volume,';');
			Ship ship(name, port, cargo_volume);
			cout << ship.to_string() << endl;
			ships.push_back(ship);
			unique_ports.insert(port);
		}
		for (string port : unique_ports) {
			vector <Ship> port_ships;
			for (Ship ship : ships) {
				if (ship.get_port() == port) {
					port_ships.push_back(ship);
				}
			}
			ports.insert(pair<string, vector <Ship>>(port, port_ships));
		}
	}
	static int CalculateCargoVolumeOfPort(string port) {
		cargo_volume_of_port = 0;
		vector <Ship> ships_of_port = ports.find(port)->second;
		for (Ship ship : ships) {
			cargo_volume_of_port += ship.get_cargo_volume();
		}
		return cargo_volume_of_port;
	}
	static int CalculateNumberOfShipsOfPort(string port) {
		counter_of_ships_of_port = 0;
		vector <Ship> ships_of_port = ports.find(port)->second;
		for (Ship ship : ships) {
			counter_of_ships_of_port += ship.get_cargo_volume();
		}
		return counter_of_ships_of_port;
	}
	static void SortPortsByCargoVolume() {
		for (string port : unique_ports) {
			sorted_ports_by_cargo_volume.push_back(port);
		}
		sort(sorted_ports_by_cargo_volume.begin(), sorted_ports_by_cargo_volume.end(),
			[](string port1, string port2) {return CalculateCargoVolumeOfPort(port1) > CalculateCargoVolumeOfPort(port2); });
		cout << "Ports sorted by cargo volume: ";
		for (string port : sorted_ports_by_cargo_volume) {
			cout << port << " ";
		}
		cout << endl;
	}
	static void SortPortsByNumberOfShips() {
		for (string port : unique_ports) {
			sorted_ports_by_number_of_ships.push_back(port);
		}
		sort(sorted_ports_by_number_of_ships.begin(), sorted_ports_by_number_of_ships.end(),
			[](string port1, string port2) {return CalculateNumberOfShipsOfPort(port1) > CalculateNumberOfShipsOfPort(port2); });
		cout << "Ports sorted by number of ships: ";
		for (string port : sorted_ports_by_number_of_ships) {
			cout << port << " ";
		}
		cout << endl;
	}
};