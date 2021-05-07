// roguesecret.cpp : by fixpont

#include <iostream>
#include <algorithm>
#include <array>

std::array<std::array<int, 7>, 7> changematrix{{
    {1,2,1,8,2,0,7},
    {8,1,8,8,3,8,8},
    {0,8,1,1,2,8,8},
    {0,0,1,1,8,3,7},
    {7,0,9,2,1,8,3},
    {2,3,2,7,0,1,1},
    {8,8,9,7,0,3,1}
}};

std::array<int, 7> KeyVector{ 0,0,0,0,0,0,0 };
std::array<int, 7> ResultVector{ 0,0,0,0,0,0,0 };
std::array<int, 7> OriginalVector{ 5,1,0,2,0,5,2 };

void PushBoxesByKey()
{
    ResultVector = OriginalVector;
    for (int i = 0; i < 7; i++)
        for(int z = KeyVector[i]; z > 0; z--)
            for (int j = 0; j < 7; j++) ResultVector[j] = ResultVector[j] + changematrix[i][j];
    for (int i = 0; i < 7; i++) ResultVector[i] = ResultVector[i] % 10;
}

int main()
{
    for (int currentkey = 0; currentkey < 9999999; currentkey++)
    {
        if (currentkey % 100000 == 0) std::cout << "Searching range: [" << currentkey << "..." << currentkey + 100000 << "]" << std::endl;
        for (int position = 6, keycopy = currentkey; position >= 0; keycopy /= 10, position--) KeyVector[position] = keycopy % 10;
        PushBoxesByKey();
        if (std::equal(ResultVector.begin() + 1, ResultVector.end(), ResultVector.begin()))
        {
            for (const auto& i : KeyVector) std::cout << i << " ";
            std::cout << std::endl;
        }
    }
}
