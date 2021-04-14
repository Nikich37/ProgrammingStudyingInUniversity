#pragma once

#include "methods.h"
#include "classes.h"
int main(void) {
	Methods::ReadClumbsToList("Input.txt");
	Methods::SortClumbsByShapes();
	Methods::MoveDataFromListToMap();
	Methods::OutputListOfClumbsWithSameFlowers();
	Methods::FindFlowersOnAllClumbs();
	Methods::CalculateFlowersOnCircleClumbs();
}