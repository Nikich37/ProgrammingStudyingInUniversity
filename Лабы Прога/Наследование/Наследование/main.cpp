#include <string>
#include <iostream>


using namespace std;
class Parent {
private:
	string name;
public:
	string surname;
	string GetSurname() {
		return surname;
	}
	string ToString() {
		return name + " " + surname + " Age: " + to_string(age);
	}
protected:
	int age;
	string GetName() {
		return name;
	}
	string GetAge() {
		return to_string(age);
	}
	
};

class ChildPublic : public Parent {
private:
	string name;
	string name_parent;
	string surname;
	int age;
public:
	ChildPublic(Parent* parent, string name_, int age_) {
		name = name_;
		age = age_;
		surname = parent->surname; //public поля родителя доступны для потомка
		name_parent = parent->name; //private поля родителя недоступны для потомка
	}
};

class ChildPrivate : private Parent {

};

class ChildProtected : protected Parent {

};