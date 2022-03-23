// 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

void PrintArr(vector<int>& inputArr)
{
    for (int i = 0; i < inputArr.size(); ++i)
        cout << inputArr[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Enter the number of array elements: ";
    int numberOfElems;
    cin >> numberOfElems;
    cout << "\n";

    boost::timer t;
    t.restart();

    int numberOfElemsWithBorders = numberOfElems + 2;

    vector<int> currentPermutation(numberOfElemsWithBorders);
    vector<int> reversePermutation(numberOfElemsWithBorders);
    vector<int> direction(numberOfElemsWithBorders);

    for (int i = 1; i <= numberOfElems; ++i)
    {
        currentPermutation[i] = i;
        reversePermutation[i] = i;
        direction[i] = -1;
    }

    direction[0] = 0;
    currentPermutation[0] = numberOfElems + 1;
    currentPermutation.back() = numberOfElems + 1;

    int border = 0;

    while (border != 1)
    {
        PrintArr(currentPermutation);
        border = numberOfElems;

        while (currentPermutation[reversePermutation[border] + direction[border]] >
            border && border > 1)
        {
            direction[border] = -direction[border];
            border = border - 1;
        }

        swap(currentPermutation[reversePermutation[border]],
            currentPermutation[reversePermutation[border] + direction[border]]);
        swap(reversePermutation[currentPermutation[reversePermutation[border]]],
            reversePermutation[border]);
    }

    double duration = t.elapsed();
    cout << duration << endl;
}

