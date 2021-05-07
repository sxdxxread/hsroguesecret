// roguesecret.cpp : by fixpont

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > changematrix{
    {1,2,1,8,2,0,7},
    {8,1,8,8,3,8,8},
    {0,8,1,1,2,8,8},
    {0,0,1,1,8,3,7},
    {7,0,9,2,1,8,3},
    {2,3,2,7,0,1,1},
    {8,8,9,7,0,3,1}
};

std::vector<int> KeyVector{ 0,0,0,0,0,0,0 };
std::vector<int> ResultVector{ 0,0,0,0,0,0,0 };
std::vector<int> OriginalVector{ 5,1,0,2,0,5,2 };

void IntToKeyVector(int number)
{
    for (int position = 6; position >= 0; number /= 10, position--) KeyVector[position] = number % 10;
}

void PushBoxesByKey()
{
    ResultVector = OriginalVector;
    for (int i = 0; i <= 6; i++)
        if (KeyVector[i] != 0)
            while (KeyVector[i]--)
                for (int j = 0; j < 7; j++) ResultVector[j] = ResultVector[j] + changematrix[i][j];
    for (int i = 0; i < 7; i++) ResultVector[i] = ResultVector[i] % 10;
}

void PrintVector(const std::vector<int>& vect)
{
    for (const auto& i : vect) std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    for (int currentkey = 0; currentkey < 9999999; currentkey++)
    {
        if (currentkey % 100000 == 0) std::cout << "Searching range: [" << currentkey << "..." << currentkey + 100000 << "]" << std::endl;
        IntToKeyVector(currentkey);
        PushBoxesByKey();
        if (std::all_of(ResultVector.begin(), ResultVector.end(), [&](int i) { return i == ResultVector[0]; }))
        {
            IntToKeyVector(currentkey);
            PrintVector(KeyVector);
        }
    }
}
