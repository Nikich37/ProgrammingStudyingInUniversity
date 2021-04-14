#include <string> 
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class sportsman {
private:
	string name;
public:
	sportsman(string name) : name(name) {}
	string get_name() { return name; }
	virtual int get_result() { return 0; }
};
class sportsman_1 : public sportsman {
private:
	int result;
public:
	sportsman_1(string name, int result) : sportsman(name) {
		this->result = result;
	}
	int get_result() { return result; }
};
class sportsman_2 : public sportsman {
private:
	int result;
public:
	sportsman_2(string name, int result) : sportsman(name) {
		this->result = result;
	}
	int get_result() { return result; }
};
class sportsman_3 : public sportsman {
private:
	int result;
public:
	sportsman_3(string name, int result) : sportsman(name) {
		this->result = result;
	}
	int get_result() { return result; }
};

multimap <string, sportsman*> results;
void ReadResultsFromFile(string file) {
	ifstream text;
	text.open(file);
	string name;
	string result; 
	string championship;
	while (getline(text, name, ' ')) {
		getline(text, result, ' ');
		getline(text, championship, '\n');
		switch (stoi(championship)) {
		case 1:
			results.insert(pair <string, sportsman*>(name, new sportsman_1(name, stoi(result))));
			break;
		case 2:
			results.insert(pair <string, sportsman*>(name, new sportsman_2(name, stoi(result))));
			break;
		case 3:
			results.insert(pair <string, sportsman*>(name, new sportsman_3(name, stoi(result))));
			break;
		}
	}
}

map <string, sportsman_1*> results_1;
map <string, sportsman_2*> results_2;
map <string, sportsman_3*> results_3;
void SortResultsToMaps() {
	for (auto it : results) {
		if (dynamic_cast<sportsman_1*>(it.second)) {
			results_1.insert(pair<string, sportsman_1*>(it.first, dynamic_cast<sportsman_1*>(it.second)));
		}
		if (dynamic_cast<sportsman_2*>(it.second)) {
			results_2.insert(pair<string, sportsman_2*>(it.first, dynamic_cast<sportsman_2*>(it.second)));
		}
		if (dynamic_cast<sportsman_3*>(it.second)) {
			results_3.insert(pair<string, sportsman_3*>(it.first, dynamic_cast<sportsman_3*>(it.second)));
		}
	}
}

vector <string> sportsmen_with_increasing_results;
vector <string> sportsmen_with_high_results;
void SortSportsmenToLists() {
	for (auto it_1 : results_1) {
		for (auto it_2 : results_2) {
			for (auto it_3 : results_3) {
				if (it_1.first == it_2.first && it_2.first == it_3.first)
					if (it_1.second->get_result() < it_2.second->get_result() 
						&& it_2.second->get_result() < it_3.second->get_result()) {
						sportsmen_with_increasing_results.insert(sportsmen_with_increasing_results.begin(), it_1.first);
					}
				if (it_1.first == it_2.first && it_2.first == it_3.first) {
					if (it_1.second->get_result() > 8 && it_2.second->get_result() > 8 && it_3.second->get_result() > 8) {
						sportsmen_with_high_results.insert(sportsmen_with_high_results.begin(), it_1.first);
					}
				}
			}
		}
	}
}

double average_results_1() {
	double average_results;
	double sum_results = 0;
	int i = 0;
	for (auto it : results_1) {
		sum_results += it.second->get_result();
		i++;
	}
	average_results = sum_results / i;
	return average_results;
}
double average_results_2() {
	double average_results;
	double sum_results = 0;
	int i = 0;
	for (auto it : results_2) {
		sum_results += it.second->get_result();
		i++;
	}
	average_results = sum_results / i;
	return average_results;
}
double average_results_3() {
	double average_results;
	double sum_results = 0;
	int i = 0;
	for (auto it : results_3) {
		sum_results += it.second->get_result();
		i++;
	}
	average_results = sum_results / i;
	return average_results;
}

void Output() {
	cout << "Sportsmen with increasing results: ";
	for (int i = 0; i < sportsmen_with_increasing_results.size(); i++)
		cout << sportsmen_with_increasing_results[i] << " ";
	cout << endl;

	cout << "Sportsmen with high results: ";
	for (int i = 0; i < sportsmen_with_high_results.size(); i++)
		cout << sportsmen_with_high_results[i] << " ";
	cout << endl;

	cout << "Average results of championship 1: " << average_results_1() << endl;
	cout << "Average results of championship 2: " << average_results_2() << endl;
	cout << "Average results of championship 3: " << average_results_3() << endl;
}

int main() {
	ReadResultsFromFile("input.txt");
	SortResultsToMaps();
	SortSportsmenToLists();
	Output();
}