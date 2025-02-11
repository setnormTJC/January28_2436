#include "SortAlgos.h"



void demoSwapFunction(vector<string>& vectorOfStrings, const int firstIndex, const int secondIndex)
{
	//std::swap(vectorOfStrings[firstIndex], vectorOfStrings[secondIndex]);

	string tempValue = vectorOfStrings[firstIndex];

	vectorOfStrings[firstIndex] = vectorOfStrings[secondIndex];

	vectorOfStrings[secondIndex] = tempValue;
}

vector<int> generateNRandomNumbers(const int N)
{
	vector<int> nRandomNumbers;

	random_device rd{};

	mt19937 rng{ rd() };

	uniform_int_distribution<int> distribution(0, N);

	for (int i = 0; i < N; ++i)
	{
		int randomNumber = distribution(rng);

		nRandomNumbers.push_back(randomNumber);
	}

	return nRandomNumbers;
}


void naiveSort(vector<string>& vectorOfStrings)
{
	for (int outer = 0; outer < vectorOfStrings.size() - 1; ++outer)
	{
		for (int inner = outer + 1; inner < vectorOfStrings.size(); ++inner)
		{
			if (vectorOfStrings[inner] < vectorOfStrings[outer])
			{
				std::swap(vectorOfStrings[inner], vectorOfStrings[outer]);
			}
		}
	}
}

/*Complexity (the TIME complexity) ~ the number of operations (the execution time) is
O(N^2)
*/
void naiveSort(vector<int>& nums)
{
	int numberOfComparisions = 0; 
	int numberOfSwaps = 0; 

	for (int outer = 0; outer < nums.size() - 1; ++outer) //N - 1 iterations 
	{
		for (int inner = outer + 1; inner < nums.size(); ++inner) //N - 2 iterations 
		{
			
			if (nums[inner] < nums[outer]) //change < to > for DESCENDING sort
			{
				std::swap(nums[inner], nums[outer]);
				numberOfSwaps++; 
			}

			numberOfComparisions++; 

		}
	} //end outer loop 

	cout << nums.size() << " elements required " << numberOfComparisions
		<< " COMPARISONS and " << numberOfSwaps << " swaps\n";

	//sum of xi from i = 0 to N = (N(N-1)/2)

}

/*What is the time complexity of THIS algorithm? */
void MiracleSort(vector<int>& nums)
{
	while (!std::is_sorted(nums.begin(), nums.end()))
	{
		//Wait for Zeus to come down from Mt. Olympus and sort the array

		//std::this_thread::sleep_for(1ms); //<thread>, <chrono> std::chrono_literals
	}
}

void MonkeySort(vector<string>& names)
{
	std::random_device rd{}; 
	std::mt19937 rng{ rd() };


	while (!std::is_sorted(names.begin(), names.end()))
	{
		std::shuffle(names.begin(), names.end(), rng);

		//cout << "After shuffling, vector is:\n";
		printVec(names); 
	}
}

void printVec(const vector<string>& vectorOfStrings)
{
	for (const auto& currentString : vectorOfStrings)
	{
		cout << currentString << "\n";
	}
}


void printVec(const vector<int>& vectorOfInts)
{
	for (const auto& currentNumber : vectorOfInts)
	{
		cout << currentNumber << " ";
	}
}
