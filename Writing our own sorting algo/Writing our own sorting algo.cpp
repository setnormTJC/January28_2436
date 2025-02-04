// Writing our own sorting algo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"SortAlgos.h"

int main()
{
	vector<string> unsortedNames =
	{
		"Bob",
		"Alice",
		"Darth",
		"Carol"
	}; 

	//demoSTDSwapFunction(unsortedNames, 0, unsortedNames.size() - 1);

	//let's sort (NOT using std::sort)
	naiveSort(unsortedNames);
	//print to verify that OUR sorting algo worked
	printVec(unsortedNames); 
}
