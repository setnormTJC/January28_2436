
// January22_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"searchAlgos.h"
#include<chrono>
#include<fstream>

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

void demoSequentialSearchOnNElements(const int N)
{
	//constexpr int N1 = 100;
	//const? 
	//constexpr int N2 = 10'000;
	auto NRandomNumbers = generateRandomNumbersBetwixt0AndN(N);
	//auto tenThousandRandomNums = generateRandomNumbersBetwixt0AndN(N2); 

	/****************The code that contained bug:/
	//std::random_device rd{}; //better alternative to passing in time(nullptr) to rng
	//mt19937 rng(rd);
	/**************************************/

	/*THE CHANGE THAT I MADE AFTER LECTURE*/
	std::random_device rd; //better alternative to passing in time(nullptr) to rng
	mt19937 rng(rd());
	/******************************************/

	uniform_int_distribution<int> distribution{ 0, N };

	int theRandomNumber = distribution(rng);
	cout << "Looking for this random number: " << theRandomNumber << "\n";

	std::cin.get();
	printOneDVector(NRandomNumbers);

	if (sequentialSearch(NRandomNumbers, theRandomNumber))
	{
		cout << "it was found\n";
	}

	else
	{
		cout << "Not found\n";
	}

	std::cin.get();
}

int main()
{
	demoSequentialSearchOnNElements(10);
	demoSequentialSearchOnNElements(100);
	demoSequentialSearchOnNElements(1'000);



	//search(oneThousandRandomNums, someNumberBetween0AndOneThousand);

}

