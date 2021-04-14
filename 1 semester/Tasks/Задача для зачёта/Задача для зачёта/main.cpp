#include "Methods.h"

int main() {
	Methods::ReadDataFromFile("Input.csv");
	Methods::SortPortsByCargoVolume();
	Methods::SortPortsByNumberOfShips();
}