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