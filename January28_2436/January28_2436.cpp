
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


	//cout 
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
bool binarySearch(const vector<int>& SORTEDnums, const int& targetNumber, int start, int end)
{
	assert(std::is_sorted(SORTEDnums.begin(), SORTEDnums.end())); //NOTE: assert is IGNORED in "Release mode" 

	if (start > end)
	{
		cout << targetNumber << " not found in the array: \n";
		printOneDVector(SORTEDnums); 

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
		return binarySearch(SORTEDnums, targetNumber, start, middle - 1);
	}

	else //middle was "Too low" 
	{
		return binarySearch(SORTEDnums, targetNumber, middle + 1, end);
	}
}


int main()
{

	vector<int> elementCounts = { 10, 100, 1'000/*, 10'000, 100'000, 1'000'000*/ };

	ofstream fout{ "fancyData.csv" };

	for (const auto& N : elementCounts)
	{
		//cout << "N = " << elementCount << " elements required  "
		//	<< measureSequentialSearchTime(elementCount)
		//	<< " nanoseconds to find (or NOT find) some random #\n";

		//long long timeForSearchingN = measureSequentialSearchTime(N); 
		//fout << N << "," << timeForSearchingN << "\n";

		auto vecN = generateRandomNumbersBetwixt0AndN(N); 
		
		std::sort(vecN.begin(), vecN.end()); 


		constexpr int TARGET_VALUE = 212312; 

		binarySearch(vecN, TARGET_VALUE, 0, vecN.size() - 1); 


		//cout << "Did the sort algo work? \n";
		//printOneDVector(vecN); 

		std::cin.get(); //enter a character to continue prog. execution

	}

	fout.close(); 

	//search(oneThousandRandomNums, someNumberBetween0AndOneThousand);

}

