// Hearthstone Rogue challenge solution, c++17 compiler required - by fixpont
#include <iostream>
#include <array>

static constexpr std::array<std::array<unsigned char, 7>, 7> changematrix{ {
    {1,2,1,8,2,0,7},
    {8,1,8,8,3,8,8},
    {0,8,1,1,2,8,8},
    {0,0,1,1,8,3,7},
    {7,0,9,2,1,8,3},
    {2,3,2,7,0,1,1},
    {8,8,9,7,0,3,1}}};

static constexpr auto mod10lookuptable = [] {
    std::array<unsigned char, 255> array{};
    for (unsigned char i = 0; i < 255; i++) array[i] = i % 10;
    return array;
}();

std::array<unsigned char, 7> KeyVector{ 0,0,0,0,0,0,0 };
std::array<unsigned char, 8> ResultVector{ 0,0,0,0,0,0,0,0 };
std::array<unsigned char, 8> OriginalVector{ 5,1,0,2,0,5,2,0 };

int main()
{
    for (int currentkey = 0; currentkey < 10000000; currentkey++)
    {
        for (int position = 6, keycopy = currentkey; position >= 0; keycopy /= 10, position--) KeyVector[position] = keycopy % 10;
        ResultVector = OriginalVector;
        for (int i = 0; i < 7; i++)
            for (int z = KeyVector[i]; z > 0; z--)
                *(unsigned long long*)(&ResultVector[0]) = *(unsigned long long*)(&ResultVector[0]) + *(unsigned long long*)(&changematrix[i][0]);
        for (int i = 0; i < 7; i++) ResultVector[i] = mod10lookuptable[ResultVector[i]];
        if (*(unsigned int*)(&ResultVector[0]) == *(unsigned int*)(&ResultVector[3]) && *(unsigned short*)(&ResultVector[0]) == *(unsigned short*)(&ResultVector[5]))
        {
            for (const auto& i : KeyVector) std::cout << (unsigned short)i << " ";
            std::cout << std::endl;
        }
    }
}
