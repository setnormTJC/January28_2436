// Writing our own sorting algo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"SortAlgos.h"

#include<chrono>
#include<fstream> 

using std::chrono::high_resolution_clock;
using std::ofstream;

void demoTestingNaiveSort_OnListOfStrings()
{
	vector<string> unsortedNames =
	{
		"Bob",
		"Alice",
		"Darth",
		"Carol"
	};

	//demoSwapFunction(unsortedNames, 0, unsortedNames.size() - 1);

	//let's sort (NOT using std::sort)
	naiveSort(unsortedNames);

	//print to verify that OUR sorting algo worked
	printVec(unsortedNames);
}


long long measureSortTimeForNRandomNumbers(const int N)
{
	auto vecN = generateNRandomNumbers(N);

	auto start = high_resolution_clock::now(); //start clock
	naiveSort(vecN); //execute the algorithm that we're benchmarking
	auto end = high_resolution_clock::now(); //stop the clock 

	return (end - start).count(); 
}


void demoNaiveSortBenchmarking()
{
	cout << "TIME: " << __TIME__ << "\n";


	std::cin.get();

	vector<int> elementCounts =
	{
		100,
		1'000,
		5'000,
		10'000,
		50'000,
		100'000,
	};

#pragma region filename stuff
	//write results out to csv file for plotting: 
	ofstream fout;// { "filename.txt" };

	// For timestamping the filename - Get the compile time (hh:mm:ss)
	std::string time_string = __TIME__; //this is the "Time" macro

	// Replace colons with underscores to make it a valid filename (no colons allowed in filenames)
	std::replace(time_string.begin(), time_string.end(), ':', '_');

	fout.open(time_string + ".csv"); //14_49_12.csv

#pragma endregion

	for (const int N : elementCounts)
	{
		long long timeForSortingNElements = measureSortTimeForNRandomNumbers(N);

		fout << N << "," << timeForSortingNElements << "\n";
	}

	fout.close();
}


int main()
{
	vector<string> names =
	{
		"Alice",
		"Carol",
		"Bob", 
		"Darth", 
		"Eve", 
		"Frank", 
		"Gus"
	}; 

	MonkeySort(names); 
	cout << "Done\n";

}
