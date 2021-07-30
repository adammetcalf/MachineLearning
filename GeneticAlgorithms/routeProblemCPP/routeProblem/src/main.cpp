#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "classes/Individual.h"
#include "classes/Population.h"

#include <cstring>
#include <cmath>
#include "plplot\plstream.h"

int main()
{
    
	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	

    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    //printVector(World);                                                                        //print the vectors
	
	/* Testing the individual class working properly
	
	Individual individual(World, worldSize);													//create an Individual

	
	std::cout <<  individual.getFitness() << '\n';												//get fitness

	for (auto element : individual.getRoute() ) {												//print route

		std::cout << element << " " << '\n';
	}
	*/

	//plot using plplot

	PLFLT x[50], y[50];
	PLFLT xmin = 0., xmax = 1., ymin = 0., ymax = 100.;
	int   i;
	for (i = 0; i < 50; i++) {
		x[i] = (PLFLT)(i) / (PLFLT)(50 - 1);
		y[i] = ymax * x[i] * x[i];
	}
	auto pls = new plstream();
	plsdev("wingcc");
	pls->init();
	pls->env(xmin, xmax, ymin, ymax, 0, 0);
	pls->lab("x", "y=100 x#u2#d", "Simple PLplot demo of a 2D line plot");
	pls->line(50, x, y);
	delete pls;


	Population popCheck(World, worldSize);														//create a population

	/*Testing the population is generating 10 distinct indivuiduals correctly

	std::vector<Individual> test = popCheck.getPopulation();									//obtain vecotr of individuals

	for (auto element : test) {																	//go through each element in turn	
		std::cout << element.getFitness() << '\n';												//get the fitness of the individual and print to screen
	}

	*/

	std::cin.get();


}








