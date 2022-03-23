#include <iostream>
#include <vector>
// #include <algorithm>
#include <random>
#include "1.3.h"

void Print(std::vector<int> const& v)
{
    for (int i : v) {
        std::cout << i << ' ';
    }
}

//void ShuffleVector(std::vector<int>& v)
//{
//    std::shuffle(std::begin(v), std::end(v), std::default_random_engine());
//
//    std::cout << "Shuffle vector is: " << " ";
//   
//    Print(v);
//}

void ShuffleVector(std::vector<int>& v)
{
    int randomNumb;
    for (int i = 0; i < v.size(); ++i)
    {
        randomNumb = rand() % v.size();
        std::swap(v[i], v[randomNumb]);
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6};

    std::cout << "Origin vector is: " << " ";

    Print(v);
 
    char isRepeating = 'y';
    	do
    	{
            ShuffleVector(v);
            std::cout << "Shuffle vector is: " << " ";
            
            Print(v);
            
    		std::cout << "\nShuffle again? y/n : ";
    		std::cin >> isRepeating;
    	} while (isRepeating == 121);
    
    return 0;
}


