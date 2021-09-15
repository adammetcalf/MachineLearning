#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "supportingFiles/gnuPlotIostream.h"
#include "classes/Individual.h"
#include "classes/Population.h"



int main()
{

	int worldSize{ 0 };														                    //Variable for number of cities in the world
	std::cout << "How many cities are in the world? " << '\n';
	std::cin >> worldSize;
	

    std::vector < std::vector<float> > World = generateWorld(worldSize);                        //generate the world
    //printVector(World);                                                                        //print the vectors
	
	Gnuplot gp1;

	gp1 << "set xrange [0:1000]\nset yrange [0:1000]\n";
	gp1 << "set title 'test Graph1 eh' \n";
	gp1 << "plot '-' with points pt 7 ps 1 title 'v0' \n";
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

	//need to start the epoch (while epoch <30 etc, do a lot of breeding)

	/*
		set epoch number, run while epoch < x,
			evolution while loop, evolve while convolution < 50ish?
				evolve, get fittest individual from population

				if no improvement in fitness, increase conv
				else, conv == 0;
			end evolution while loop
		end epoch while loop
	*/

	Population popCheck(World, worldSize);														//create a population

	int epoch = 0;
	while (epoch < 30)
	{
		int convolution = 0;
		while (convolution < 50)
		{


			convolution++;
		}

		epoch++;
	}
	//need end of while loop, get actuall fittest individual

	/*//Testing the population is generating 10 distinct indivuiduals correctly
	
	std::vector<Individual> test = popCheck.getPopulation();									//obtain vecotr of individuals

	for (auto element : test) {																	//go through each element in turn	
		std::cout << element.getFitness() << '\n';												//get the fitness of the individual and print to screen
	}

	*/

	

	std::vector < std::vector<float> > bestRoute = popCheck.getBestRoute(World,worldSize);		//get best individual

	Gnuplot gp; 
	
	gp << "set xrange [0:1000]\nset yrange [0:1000]\n";
	gp << "set title 'test Graph2 eh' \n";
	gp << "plot '-' with lines title 'v0' \n";
	gp.send(bestRoute);
	gp.flush();


	std::cin.get();
	return 0;

}








