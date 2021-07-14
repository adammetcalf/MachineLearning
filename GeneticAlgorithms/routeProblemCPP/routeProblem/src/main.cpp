#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "classes/Individual.h"


int main()
{
    
	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	

    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    printVector(World);                                                                         //print the vectors

	individual Individual(World, worldSize);													//create an individual



	std::cin.get();


}








