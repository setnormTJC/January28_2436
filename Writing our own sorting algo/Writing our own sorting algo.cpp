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

void demoMonkeySort_ForNEquals7()
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

template<typename T>
int partition(vector<T>& list, int first, int last)
{
	T pivot = list[first];
	int left = first + 1;
	int right = last;

	while (true)
	{
		while (left <= right && list[left] <= pivot)
		{
			left++;
		}

		while (left <= right && list[right] >= pivot)
		{
			right--;
		}

		if (left > right)
		{
			break;
		}

		std::swap(list[left], list[right]);
	}

	std::swap(list[first], list[right]);
	return right;
}

template<typename T>
void quickSort(vector<T>& list, int first, int last)
{
	if (first < last)
	{
		int pivotLocation = partition(list, first, last);
		quickSort(list, first, pivotLocation - 1);
		quickSort(list, pivotLocation + 1, last);
	}
}

int main()
{
	//IN order of decreasing efficiency, the sorting algos: 
	//1) Miracle sort -> O(infinity) Big O (Little O)
	//2) Bogosort (AKA: MonkeySort) -> O(N!)
	//3) NaiveSort(nested for loops -> O(N^2)
	//4) QuickSort is coming, and it is O(N*log2(N))

	//one more little demo of NaiveSort:
	//vector<int> alreadySortedNums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//cout << "How many comparison AND SWAPS for N = 10 with ALREADY SORTED array: \n";
	//naiveSort(alreadySortedNums); 


	//vector<int> worstCaseInput = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//cout << "How many comparison AND SWAPS for N = 10 with REVERSE ORDER array: \n";
	//naiveSort(worstCaseInput);

	constexpr int N = 100'000; 

	auto vecN = generateNRandomNumbers(N); 
	auto copyOfVecN = vecN; //make a copy so that after we sort the original using NaiveSort, we can 
							//compare the quickSort time using THE SAME input array 

	auto startQuickTimer = std::chrono::high_resolution_clock::now(); 
	quickSort(vecN, 0, vecN.size() - 1);
	auto endQuickTimer = std::chrono::high_resolution_clock::now();

	cout.imbue(std::locale("")); 
	cout << "Quicksort for N = " << N << " took this many nanoseconds: "
		<< (endQuickTimer - startQuickTimer).count() << "\n";
	//printVec(vecN); 

	auto startSLOWTimer = std::chrono::high_resolution_clock::now(); 
	naiveSort(copyOfVecN); 
	auto endSLOWTimer = std::chrono::high_resolution_clock::now();

	cout << "Naive sort (selection sort) took this many nanoseconds: "
		<< (endSLOWTimer - startSLOWTimer).count() << "\n";




}
