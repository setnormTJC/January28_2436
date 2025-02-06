#pragma once


#include<algorithm> 
#include <iostream>
#include<random>
#include<string> 
#include<vector>

using std::cout, std::vector, std::string; 


using std::mt19937, std::random_device, std::uniform_int_distribution;






void demoSwapFunction(vector<string>& vectorOfStrings, const int firstIndex, const int secondIndex);


vector<int> generateNRandomNumbers(const int N);

void printVec(const vector<string>& vectorOfStrings);

//template<typename T> //do later ... if desired
/*
@param this overload takes STRINGS
*/
void naiveSort(vector<string>& vectorOfStrings); 

/*
@param this overload takes INTS
*/
void naiveSort(vector<int>& nums);

void MiracleSort(vector<int>& nums);

void MonkeySort(vector<string>& names);
