#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"



int main()
{
    
	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	
	


    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    printVector(World);                                                                         //print the vectors


	std::cin.get();


}








