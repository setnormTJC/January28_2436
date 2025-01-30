// Moving on to std library algos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include <iostream>
#include <vector>


bool isGreaterThan5(int num)
{
    return (num > 5);
}


int main()
{
    //std::cout << "Hello World!\n";
    //std::vector<int> someNums = { 11, 2222, 3333, 4444, 5555 };

    //int a = 123123; 

    //std::cout << std::boolalpha; 
    //std::cout << "Are all of the nums greater than 5? "
    //    << std::all_of(someNums.begin(), someNums.end(), isGreaterThan5);

    //that last arg is an example of a "function pointer" 

    std::vector<std::string> names = { "Alice", "Bob", "Carol", "Darth" }; //the usual "cryptographic" actors
    
    
    while (std::next_permutation(names.begin(), names.end()))
    {
        for (const auto& currentName : names)
        {
            std::cout << currentName << " ";
        }

        std::cout << "\n";
    }
}
