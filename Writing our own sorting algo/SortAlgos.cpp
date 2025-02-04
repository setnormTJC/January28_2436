#include "SortAlgos.h"

void printVec(const vector<string>& vectorOfStrings)
{
	for (const auto& currentString : vectorOfStrings)
	{
		cout << currentString << "\n";
	}
}

void demoSTDSwapFunction(vector<string>& vectorOfStrings, const int firstIndex, const int secondIndex)
{
	//std::swap(vectorOfStrings[firstIndex], vectorOfStrings[secondIndex]);

	string tempValue = vectorOfStrings[firstIndex];

	vectorOfStrings[firstIndex] = vectorOfStrings[secondIndex];

	vectorOfStrings[secondIndex] = tempValue;
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


void naiveSort(vector<int>& nums)
{
	for (int outer = 0; outer < nums.size() - 1; ++outer)
	{
		for (int inner = outer + 1; inner < nums.size(); ++inner)
		{
			if (nums[inner] < nums[outer])
			{
				std::swap(nums[inner], nums[outer]);
			}
		}
	}
}

vector<int> generateNRandomNumbers(const int N)
{
	vector<int> nRandomNumbers; 

	random_device rd{}; 

	mt19937 rng{ rd()};

	uniform_int_distribution<int> distribution(0, N); 

	for (int i = 0; i < N; ++i)
	{
		int randomNumber = distribution(rng); 

		nRandomNumbers.push_back(randomNumber);
	}

	return nRandomNumbers;
}
