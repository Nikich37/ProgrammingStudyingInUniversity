#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <locale>

using namespace std;

//Classes
class Route {
private:
	pair <string, string> bus;
	string driver;
	string route_number;
public:
	Route() {};
	Route(vector<string> vec) {
		this->route_number = vec[0];
		this->driver = vec[1];
		this->bus.first = vec[2];
		this->bus.second = vec[3];
	}
	Route(string route_number, string surname, string number_of_bus, 
		string mark_of_bus) {
		this->route_number = route_number;
		this->driver = surname;
		this->bus.first = number_of_bus;
		this->bus.second = mark_of_bus;
	}
	string get_bus() {
		return bus.first + bus.second;
	}
	string get_surname_of_driver() {
		return driver;
	}
	string get_route_number() {
		return route_number;
	}
	string to_string() {
		return route_number + driver + bus.first + bus.second;
	}
	void change_driver_of_route(string driver) {
		this->driver = driver;
	}

};

//Methods
vector<vector<string>> data_vec;
void ReadData(string filename) {
	ifstream text;
	text.open(filename);
	string str;
	while (getline(text, str)){
		vector <string> tmp_vec;
		stringstream stream_str(str);
		string tmp_str;
		for (int i = 0; i < 3; i++) {
			getline(stream_str, tmp_str, ' ');
			tmp_vec.push_back(tmp_str);
		}
		getline(stream_str, tmp_str, '\n');
		tmp_vec.push_back(tmp_str);
		data_vec.push_back(tmp_vec);
	}
	
}

vector<Route> routes;
void Collect(vector <vector<string>>& vectors) {
	for (vector<string> tmp_vec : vectors) {
		Route route(tmp_vec);
		routes.push_back(route);
		route.to_string();
	}
}

void SortByRouteNumber() {
	sort(routes.begin(), routes.end(),
		[](Route route1, Route route2)
		{return route1.get_route_number() > route2.get_route_number(); });
}

multimap<string, Route> routes_of_drivers;
void MakeAssociativeContainer() {
	for (Route route : routes) {
		routes_of_drivers.insert(pair<string, Route>
			(route.get_surname_of_driver(), route));
	}
}

vector <string> drivers_of_route;
void MakeListOfDriversOfRoute() {
	cout << "Enter number of route: ";
	string number_of_route;
	cin >> number_of_route;
	for (Route route : routes) {
		if (route.get_route_number() == number_of_route) {
			drivers_of_route.push_back(route.get_surname_of_driver());
		}
	}
	cout << "List of drivers of this route: ";
	for (int i = 0; i < drivers_of_route.size(); i++) {
		cout << drivers_of_route[i];
		if (i != drivers_of_route.size() - 1) {
			cout << ", ";
		}
		else { 
			cout << "."; 
		}
	}
	cout << endl;
}

void ChangeDriverOfRoute() {
	cout << "Enter number of route and surname of driver, that should be changed.";
	cout << endl << "Number of route: ";
	string route_number;
	cin >> route_number;
	cout << "Surname of driver: ";
	string surname_of_driver;
	cin >> surname_of_driver;
	for (Route route : routes) {
		if (route.get_route_number() == route_number && 
			route.get_surname_of_driver() == surname_of_driver) {
			cout << "Enter changed driver's surname: ";
			string changed_driver_surname;
			cin >> changed_driver_surname;
			route.change_driver_of_route(changed_driver_surname);
			cout << "Driver's surname was changed successfully!";
			return;
		}
	}
	cout << "There is no route with this number and driver!";
}

//main
int main() {
	ReadData("Input.txt");
	Collect(data_vec);
	SortByRouteNumber();
	MakeAssociativeContainer();
	MakeListOfDriversOfRoute();
	ChangeDriverOfRoute();
	return 0;
}