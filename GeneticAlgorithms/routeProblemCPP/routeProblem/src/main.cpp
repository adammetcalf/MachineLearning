#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "classes/Individual.h"
#include "classes/Population.h"


int main()
{
    
	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	

    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    //printVector(World);                                                                         //print the vectors
	
	/* Testing the individual class working properly
	
	Individual individual(World, worldSize);													//create an Individual

	
	std::cout <<  individual.getFitness() << '\n';												//get fitness

	for (auto element : individual.getRoute() ) {												//print route

		std::cout << element << " " << '\n';
	}
	*/

	Population popCheck(World, worldSize);														//create a population

	

	std::cin.get();


}








