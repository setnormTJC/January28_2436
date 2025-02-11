// SortingObjectsOfAClassByCustomCriteria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include<iomanip>
#include <iostream>
#include <vector>

class Pokemon {
public:
    std::string name;
    std::string type;
    int level;

    Pokemon(std::string n, std::string t, int l) 
        : name(n), type(t), level(l) 
    {
    }

    //bool operator < 
};

void printPokeDex(const std::vector<Pokemon>& pokemons)
{
    for (const Pokemon& currentPoke : pokemons)
    {
        std::cout << std::left << std::setw(15) << currentPoke.name;
        std::cout << std::left << std::setw(10) << currentPoke.type;
        std::cout << std::left << std::setw(3) << currentPoke.level;
        std::cout << "\n";
    }

}

bool comparePokemonByName(const Pokemon& poke1, const Pokemon& poke2)
{
    //the "long" way:
    //if (poke1.name > poke2.name)
    //{
    //    return true; 
    //}

    //else
    //{
    //    return true; 
    //}

    return (poke1.name > poke2.name);
}

int main()
{
    std::vector<Pokemon> pokemons = 
    {
        Pokemon("Pikachu", "Electric", 25),
        Pokemon("Charizard", "Fire", 36),
        Pokemon("Bulbasaur", "Grass", 15),
        Pokemon("Squirtle", "Water", 10)
    };

    printPokeDex(pokemons); 

    std::cout << "\n\nSorted (DESCENDING) by name:\n";
    std::sort(pokemons.begin(), pokemons.end(), comparePokemonByName);
    printPokeDex(pokemons); 


    std::cout << "\n\nSorted (ascending) by LEVEL:\n";
    std::sort(pokemons.begin(), pokemons.end(),
        [](const Pokemon& p1, const Pokemon& p2)
        {
            return p1.level < p2.level;
        });
    printPokeDex(pokemons);
}
