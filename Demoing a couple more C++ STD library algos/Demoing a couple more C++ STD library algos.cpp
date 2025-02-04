// Feb4_LecturePrep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm> 
#include <iostream>
#include<set> 
#include<vector> 

using std::cout, std::vector, std::set, std::string;

void printSet(const set<string>& setOfStrings)
{
	for (const auto& currentString : setOfStrings)
	{
		cout << currentString << "\n";
	}
}


void printVec(const vector<string>& vectorOfStrings)
{
	for (const auto& currentString : vectorOfStrings)
	{
		cout << currentString << "\n";
	}
}

template<typename T>
void printContainerContents(const T& container)
{
	for (const auto& element : container)
	{
		cout << element << "\n";
	}
}

void demoSetIntersection()
{
	set<string> peopleWhoLikeDogs =
	{
		"Hayden",
		"Ibrahim",
		"Cayne",
		"Cayne" //intentionally clone Cayne
	};

	cout << "4? ..." << peopleWhoLikeDogs.size() << "\n";
	cout << "People who like dogs set: \n";
	printSet(peopleWhoLikeDogs);


	set<string> peopleWhoLikeCats =
	{
		"Cayne",
		"Jayda",
		"Satoshi",
		"Ibrahim",
		"Luna"
	};

	//std::sort(peopleWhoLikeCats.begin(), peopleWhoLikeCats.end()); //not needed!
	//std::sort(peopleWhoLikeDogs.begin(), peopleWhoLikeDogs.end());

	set<string> peopleWhoLikeBoth;

	//std::set_intersection()
	std::set_intersection(peopleWhoLikeDogs.begin(), peopleWhoLikeDogs.end(),
		peopleWhoLikeCats.begin(), peopleWhoLikeCats.end(),
		std::inserter(peopleWhoLikeBoth, peopleWhoLikeBoth.begin()));

	cout << "\n\nPeople who like both cats and dogs:\n";
	printSet(peopleWhoLikeBoth);

}

void demoMerge_withVector()
{
	vector<string> firstLane =
	{
		"Dean",
		"Daniel",
		"Aiden"
	};

	vector<string> secondLane =
	{
		"Esohe",
		"Andrew",
		"Connor"
	};

	std::sort(firstLane.begin(), firstLane.end());
	std::sort(secondLane.begin(), secondLane.end()); 

	vector<string> mergedLane;

	std::merge(firstLane.begin(), firstLane.end(), secondLane.begin(), secondLane.end(),
		std::back_inserter(mergedLane));

	//IN DEBUG MODE: triggers "sequence not ordered"! (if vectors are not sorted)

	//printVec(mergedLane); 
	printContainerContents(mergedLane);

}


int main()
{
	//demoSetIntersection(); 

	demoMerge_withVector();


}
