#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "supportingFiles/gnuPlotIostream.h"
#include "classes/Individual.h"
#include "classes/Population.h"

#include<random>
#include<numeric>

#include <cstdio>




int main()
{



	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	

    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    //printVector(World);                                                                         //print the vectors
	
	Gnuplot gp1;

	gp1 << "set title 'test Graph1 eh' \n";
	gp1 << "plot '-' with points title 'v0' \n";
	gp1.send(World);
	gp1.flush();

	/*
	//Testing the individual class working properly
	
	Individual individual(World, worldSize);													//create an Individual

	
	std::cout <<  individual.getFitness() << '\n';												//get fitness

	for (auto element : individual.getRoute() ) {												//print route

		std::cout << element << " " << '\n';
	}
	*/

	Population popCheck(World, worldSize);														//create a population

	///*//Testing the population is generating 10 distinct indivuiduals correctly

	std::vector<Individual> test = popCheck.getPopulation();									//obtain vecotr of individuals

	for (auto element : test) {																	//go through each element in turn	
		std::cout << element.getFitness() << '\n';												//get the fitness of the individual and print to screen
	}

	//*/

	



	Gnuplot gp; 
	
	gp << "set title 'test Graph2 eh' \n";
	gp << "plot '-' with points title 'v0' \n";
	gp.send(World);
	gp.flush();


	std::cin.get();
	return 0;

}








