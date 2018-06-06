//============================================================================
// Name        : HelloWorld.cpp
// Author      : Alex
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <vector>
#include <iostream>

using namespace std;

int find_even_index(const vector<int> numbers)
{
    int sortingSum = numbers[0];
    int arraySize = numbers.size();

    cout << arraySize << endl;
    // cout << sortingSum  << endl;

    // for all element equal 0 or Right Side sum = 0
    int ret = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        if (numbers[i] == 0)
        {
            ret++;
        }
        sortingSum += numbers[i];
    }
    if (ret == arraySize || sortingSum == 0)
    {
        return 0;
    }


    sortingSum = 0;

    cout << arraySize << endl;
    // cout << sortingSum  << endl;


    // for not all zero elements
    // for (int i = 1; i < arraySize; i += 2)
    // {
    //     int LeftVal, RightVal;

    //     for (int Left = 0; Left < i; ++i)
    //     {
    //         LeftVal += numbers[Left];
    //     }
    //     for (int Right = i; Right < arraySize; ++i)
    //     {
    //         RightVal += numbers[Right];
    //     }

    //     if (LeftVal == RightVal) {
    //         return i;
    //     }

    // }

    return -1;
}

int main()
{

    vector<int> numbers{1, 2, 3, 4, 3, 2, 1};
    int expected = 0;

    cout << "Final value: " << find_even_index(numbers) << endl;

    return 0;
}
