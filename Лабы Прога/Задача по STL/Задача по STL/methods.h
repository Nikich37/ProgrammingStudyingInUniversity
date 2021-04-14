#pragma once
#include "classes.h"
list <Clumb> clumbs_list;
map <string, Clumb> clumbs_map;
class Methods {
public:
	//1 (container is list)
	static void ReadClumbsToList(string file){
		ifstream text;
		text.open(file);
		string clumbs;
		while (getline(text, clumbs)) {
			stringstream clumb(clumbs);
			string number;
			string shape;
			string flower;
			vector <string> flowers;
			getline(clumb, number, ' ');
			getline(clumb, shape, ' ');
			while (getline(clumb, flower, ' ')) {
				flowers.push_back(flower);
			}
			Clumb clumb_(number, shape, flowers);
			clumbs_list.push_back(clumb_);
		}
	}
	//2
	static void SortClumbsByShapes() {
		clumbs_list.sort([](Clumb& clumb1, Clumb& clumb2) {return clumb1.get_shape() < clumb2.get_shape(); });
	}
	//3 (key is clumb number)
	static void MoveDataFromListToMap() {
		for (Clumb clumb : clumbs_list) {
			clumbs_map.insert(clumbs_map.begin(), pair <string, Clumb>(clumb.get_number(), clumb));
		}
	}
	//4.4
	static void OutputListOfClumbsWithSameFlowers() {
		vector <Clumb> clumbs_with_same_flowers;
		for (pair<string, Clumb> clumb1 : clumbs_map) {
			vector <string> flowers1 = clumb1.second.get_flowers_vector();
			sort(flowers1.begin(), 
				flowers1.end(), [](string flower1, string flower2) {return flower1 < flower2; });
			clumbs_with_same_flowers.clear();
			for (pair<string, Clumb> clumb2 : clumbs_map) {
				vector <string> flowers2 = clumb2.second.get_flowers_vector();
				sort(flowers2.begin(),
					flowers2.end(), [](string flower1, string flower2) {return flower1 < flower2; });
				if (flowers1 == flowers2) {
					clumbs_with_same_flowers.push_back(clumb2.second);
				}
			}
			if (clumbs_with_same_flowers.size() > 1) {
				break;
			}
		}
		if (clumbs_with_same_flowers.size() > 0) {
			cout << "Clumbs with same flowers: ";
			for (Clumb clumb : clumbs_with_same_flowers) {
				cout << clumb.get_number() << " ";
			}
		}
		else {
			cout << "There are no clumbs with same flowers!";
		}
		cout << endl;
	}
	//5.5
	static void FindFlowersOnAllClumbs() {
		vector <string> flowers_on_all_clumbs;
		Clumb clumb1 = clumbs_map["1"];
		for (string flower1 : clumb1.get_flowers_vector()) {
			int counter_flower1 = 0;
			for (pair<string, Clumb> clumb2 : clumbs_map) {
				for (string flower2 : clumb2.second.get_flowers_vector()) {
					if (flower1 == flower2) {
						counter_flower1++;
					}
				}
			}
			if (counter_flower1 == clumbs_map.size()) {
				flowers_on_all_clumbs.push_back(flower1);
			}
		}
		if (flowers_on_all_clumbs.size() > 0) {
			cout << "Flowers on all clumbs: ";
			for (int i = 0; i < flowers_on_all_clumbs.size(); i++) {
				cout << flowers_on_all_clumbs[i] << " ";
			}
		}
		else {
			cout << "There are no flowers on all clumbs!";
		}
		cout << endl;
	}
	//6.1
	static int flowers_on_clumb(Clumb& clumb) {
		int flowers = clumb.get_flowers_vector().size();
		return flowers;
	}
	static void CalculateFlowersOnCircleClumbs() {
		int flowers_on_circle_clumbs = 0;
		for (pair<string, Clumb> clumb : clumbs_map) {
			if (clumb.second.get_shape() == "Circle") {
				flowers_on_circle_clumbs += flowers_on_clumb(clumb.second);
			}
		}
		cout << "Number of flowers on circle clumbs is "
			<< flowers_on_circle_clumbs << endl;
	}
};