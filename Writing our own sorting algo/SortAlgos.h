#pragma once


#include <iostream>
#include<vector>
#include<string> 

using std::cout, std::vector, std::string; 

void printVec(const vector<string>& vectorOfStrings);

void demoSTDSwapFunction(vector<string>& vectorOfStrings, const int firstIndex, const int secondIndex);

//template<typename T> //do later ... if desired  
void naiveSort(vector<string>& vectorOfStrings); //funcy dec. 