#include"searchAlgos.h"

vector<int> generateRandomNumbersBetwixt0AndN(int N)
{

    mt19937 rng(time(nullptr));


    uniform_int_distribution<int> distribution{ 0, N };

    vector<int> randomNumbersBetwixt0AndN;

    for (int i = 0; i < N; ++i)
    {
        randomNumbersBetwixt0AndN.push_back(distribution(rng));
    }

    return randomNumbersBetwixt0AndN;
}

void printOneDVector(const vector<int>& oneDVector)
{
    for (auto& num : oneDVector)
    {
        cout << num << " ";
    }
    cout << "\n";
}

array<array<string, 4>, 4> initializeMyRoomContents()
{
    array<array<string, 4>, 4> myRoom =
    { {
        {"Bed", "Desk", "Chair", "Lamp"},
        {"Bookshelf", "Wardrobe", "Mirror", "Rug"},
        {"Window", "Curtains", "Plant", "Clock"},
        {"Laptop", "Notebook", "Pen", "Backpack"}
    } };

    return myRoom;
}

void print2DArray(array<array<string, 4>, 4> twoDArray)
{
    for (const auto& row : twoDArray)
    {
        for (const auto& element : row)
        {
            cout << element << "\t";
        }
        cout << "\n"; //puts a newline between each row of myRoom (or whatever 2D array we're dealing with) 
    }
}


/*Complexity (~the number of operations) is BigO(N)*/
pair<int, int> search(array<array<string, 4>, 4> twoDArray, const string& thingWeSearchFor)
{
    unsigned int comparisonCount = 0;

    pair<int, int> position = { -1, -1 }; // Initialize with -1, -1 to indicate not found

    for (int i = 0; i < twoDArray.size(); ++i)
    {
        for (int j = 0; j < twoDArray[i].size(); ++j)
        {
            comparisonCount++;

            if (twoDArray[i][j] == thingWeSearchFor)
            {
                position = { i, j };

                cout << "Number of comparisons performed: " << comparisonCount << "\n";
                return position;
            }
        }
    }

    cout << "Number of comparisons performed: " << comparisonCount << "\n";
    return position; // Return -1, -1 if not found
}
