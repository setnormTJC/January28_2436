
// January22_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"searchAlgos.h"
#include<chrono>
#include<fstream>
#include <cassert>

//#include<filesystem>

using std::ofstream;

void demoSearchingThrough2DStringArray()
{
	auto myRoomContents = initializeMyRoomContents();

	print2DArray(myRoomContents);

	string thing_to_search_for = "Bed";

	cout << thing_to_search_for << " was? found at row  = "
		<< search(myRoomContents, thing_to_search_for).first
		<< "and column = "
		<< search(myRoomContents, thing_to_search_for).second << "\n";
}


void demoMeasuringExecutionTime()
{
	auto start = std::chrono::high_resolution_clock::now();
	//chrono is Latin/Greek and means "related to time" 
	//how long (in NANOSECONDS) does it take for my program to count to one billion? 
	for (int i = 0; i < 1'000'000'000; ++i)
	{
		//nothin'
	}
	auto end = std::chrono::high_resolution_clock::now();

	cout.imbue(std::locale(""));
	//puts a comma every three digits for nums >> 1 (on my machine)

	cout << "It took this much time: " << (end - start).count() << "\n";
}

/*CSV stands for "comma-separated values/variables"*/
void demoWritingToACSVFile()
{
	ofstream fout{ "out.csv" };

	fout << 1 << "," << 3 << "\n";
	fout << 2 << "," << 6 << "\n";
	fout << 3 << "," << 9 << "\n";
	fout << 4 << "," << 12 << "\n";
	fout << 5 << "," << 15 << "\n";

	fout.close();
}

//void callSequentialSearchOnNElement

long long measureSequentialSearchTime(const int N)
{
	auto NRandomNumbers = generateRandomNumbersBetwixt0AndN(N);

	/*THE CHANGE THAT I MADE AFTER LECTURE*/
	std::random_device rd; //better alternative to passing in time(nullptr) to rng
	mt19937 rng(rd());
	/******************************************/

	uniform_int_distribution<int> distribution{ 0, N };

	int theRandomNumber = distribution(rng);
	//cout << "Looking for this random number: " << theRandomNumber << "\n";

	//std::cin.get();
	//printOneDVector(NRandomNumbers);

	auto start = std::chrono::high_resolution_clock::now(); 

	//call the algorithm of interest: 
	sequentialSearch(NRandomNumbers, theRandomNumber);

	auto end = std::chrono::high_resolution_clock::now();

	return (end - start).count(); 
}

/*RECURSIVE approach taken from: 
https://www.youtube.com/watch?v=MFhxShGxHWc
*/
bool recursiveBinarySearch(const vector<int>& SORTEDnums, const int& targetNumber, int start, int end,
	int& recursiveCallCount)
{
	assert(std::is_sorted(SORTEDnums.begin(), SORTEDnums.end())); //NOTE: assert is IGNORED in "Release mode" 


	recursiveCallCount++;

	if (start > end)
	{
		cout << targetNumber << " not found in the array: \n";
		printOneDVector(SORTEDnums); 
		
		cout << "\n\nAnd the number of recursive calls was: " << recursiveCallCount << "\n";

		return false; //means "not found"  
	}

	int middle = floor((start + end) / 2);

	if (SORTEDnums[middle] == targetNumber)
	{
		cout << "Found at index = " << middle << "\n";
		return true; 
	}

	else if (SORTEDnums[middle] > targetNumber)
	{
		return recursiveBinarySearch(SORTEDnums, targetNumber, start, middle - 1, recursiveCallCount);
	}

	else //middle was "Too low" 
	{
		return recursiveBinarySearch(SORTEDnums, targetNumber, middle + 1, end, recursiveCallCount);
	}
}

void demoBinarySearchAlgoAnalysis()
{
	vector<int> binarySearchArraySizes =
	{
		(int)pow(2, 3), //8
		(int)pow(2, 4), //16
		(int)pow(2, 5), //32
		(int)pow(2, 6), //etc.
		(int)pow(2, 7),
	};


	for (int currentArraySize : binarySearchArraySizes)
	{
		vector<int> vecN;

		for (int i = 1; i <= currentArraySize; ++i)
		{
			vecN.push_back(i); //ex: for arraySize = 8, this array will be {1, 2, 3, ...8}
		}

		//now "force" a worst case scenario - pick a number outside of the array's range: 
		int targetValue = currentArraySize * 100;

		int recursiveCallCount = 0; //track the number of calls -> for ALGORITHM ANALYSIS
		recursiveBinarySearch(vecN, targetValue, 0, vecN.size() - 1, recursiveCallCount);


		std::cin.get();
	}

}

/*This function was implemented by Copilot - HHOORAY!*/
//void testBinarySearch() {
//	// Test case 1: Element is present in the middle
//	{
//		vector<int> sortedNums = { 1, 2, 3, 4, 5 };
//		int target = 3;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == true);
//	}
//
//	// Test case 2: Element is present at the beginning
//	{
//		vector<int> sortedNums = { 1, 2, 3, 4, 5 };
//		int target = 1;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == true);
//	}
//
//	// Test case 3: Element is present at the end
//	{
//		vector<int> sortedNums = { 1, 2, 3, 4, 5 };
//		int target = 5;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == true);
//	}
//
//	// Test case 4: Element is not present
//	{
//		vector<int> sortedNums = { 1, 2, 3, 4, 5 };
//		int target = 6;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == false);
//	}
//
//	// Test case 5: Empty array
//	{
//		vector<int> sortedNums = {};
//		int target = 1;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == false);
//	}
//
//	// Test case 6: Single element array, element is present
//	{
//		vector<int> sortedNums = { 1 };
//		int target = 1;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == true);
//	}
//
//	// Test case 7: Single element array, element is not present
//	{
//		vector<int> sortedNums = { 1 };
//		int target = 2;
//		assert(binarySearch(sortedNums, target, 0, sortedNums.size() - 1) == false);
//	}
//
//	cout << "All test cases passed!" << std::endl;
//}


int main()
{

	demoBinarySearchAlgoAnalysis(); 


	//testBinarySearch(); 
	std::cin.get(); 
















	vector<int> elementCounts = { 10, 100, 1'000/*, 10'000, 100'000, 1'000'000*/ };


	for (const auto& N : elementCounts)
	{

		auto vecN = generateRandomNumbersBetwixt0AndN(N); 
		
		std::sort(vecN.begin(), vecN.end()); 

		//INTENTIONALLY search for a value that will not be in the array
		//trigger a "worst-case" scenario:
		int TARGET_VALUE = N * 50; 

		//binarySearch(vecN, TARGET_VALUE, 0, vecN.size() - 1); 

		std::cin.get(); //enter a character to continue prog. execution

	}


}

