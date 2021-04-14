#pragma once

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI 3.14159265

using namespace std;
enum TypeOfShape {cylinder, cone};
enum TypeOfSort {square, volume};
class shape
{
private:
	static int id_counter;
	int id;
	TypeOfShape type;
public:
	shape(TypeOfShape type) : type(type) {
		id = id_counter;
		id_counter++;
	}
	int GetID() { return id; }
	virtual string GetType() { return 0; }
	virtual string ToString() { return 0; }
};
class shape3d: public shape
{
public:
	shape3d(TypeOfShape type) : shape(type) {}
	
	virtual double square() { return 0; };
	virtual double volume() { return 0; };
};
class Cylinder : public shape3d
{
public:
	Cylinder(TypeOfShape type, double Radius, double Height) : shape3d(type) {
		this->Radius = Radius;
		this->Height = Height;
	}
	double square() {
		double square = 2 * PI * Radius * Height + 2 * PI * Radius * Radius;
		return square;
	}
	double volume() {
		double volume = PI * Radius * Radius * Height;
		return volume;
	}
	string GetType() { return "Cylinder"; }
	string ToString() {
		return to_string(this->GetID()) + " Cylinder " + to_string(Radius) + " " + to_string(Height);
	}
private:
	double Radius;
	double Height;
};
class Cone : public shape3d
{
public:
	Cone(TypeOfShape type, double Radius, double Height) : shape3d(type) {
		this->Radius = Radius;
		this->Height = Height;
	}
	double square() {
		double square = PI * Radius * sqrt(Radius * Radius + Height * Height) + PI * Radius * Radius;;
		return square;
	}
	double volume() {
		double volume = PI * Radius * Radius * Height/3;
		return volume;
	}
	string GetType() { return "Cone"; }
	string ToString() {
		return to_string(this->GetID()) + " Cone " + to_string(Radius) + " " + to_string(Height);
	}
private:
	double Radius;
	double Height;
};
int shape::id_counter = 1;
void ReadAndSortShapesFromFile(string file) {
	vector <shape3d*> shapes;
	ifstream text;
	text.open(file);
	string sort_;
	int NumberOfShapes;
	string tmpNumberOfShapes;
	getline(text, tmpNumberOfShapes);
	NumberOfShapes = stoi(tmpNumberOfShapes);
	getline(text, sort_);
	string TypeOfShape;
	for (int i = 1; i <= NumberOfShapes; i++) {
		getline(text, TypeOfShape, ' ');
		if (TypeOfShape == "cylinder") {
			string Radius, Height;
			getline(text, Radius, ' ');
			getline(text, Height, '\n');
			shapes.push_back(new Cylinder(cylinder, stoi(Radius), stoi(Height)));
		}
		else if (TypeOfShape == "cone") {
			string Radius, Height;
			getline(text, Radius, ' ');
			getline(text, Height, '\n');
			shapes.push_back(new Cone(cone, stoi(Radius), stoi(Height)));
		}
		else { getline(text, TypeOfShape); }
	}
	ofstream out("output.txt");
	out.precision(2);

	if (sort_ == "volume") {
		sort(shapes.begin(), shapes.end(), [](shape3d* shape1, shape3d* shape2) {return shape1->volume() < shape2->volume(); });
		for (shape3d* it : shapes) {
			cout << it->ToString() << " " << it->volume() << endl;
			out << it->ToString() << " " << it->volume() << endl;
		}
	}
	if (sort_ == "square") {
		sort(shapes.begin(), shapes.end(), [](shape3d* shape1, shape3d* shape2) {return shape1->square() < shape2->square(); });
		for (shape3d* it : shapes) {
			cout << it->ToString() << " " << it->volume() << endl;
			out << it->ToString() << " " << it->volume() << endl;
		}
	}
}


int main() {
	ReadAndSortShapesFromFile("input.txt");
	return 0;
}