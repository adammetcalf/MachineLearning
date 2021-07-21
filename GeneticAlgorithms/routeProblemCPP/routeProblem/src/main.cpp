#include <iostream>
#include <vector>
#include "supportingFiles/generateWorld.h"
#include "supportingFiles/printVector.h"
#include "supportingFiles/gnuPlotIostream.h"
#include "classes/Individual.h"
#include "classes/Population.h"

#include<random>
#include<numeric>




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

	/*Testing the population is generating 10 distinct indivuiduals correctly

	std::vector<Individual> test = popCheck.getPopulation();									//obtain vecotr of individuals

	for (auto element : test) {																	//go through each element in turn	
		std::cout << element.getFitness() << '\n';												//get the fitness of the individual and print to screen
	}

	*/


	Gnuplot gp("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\"");								//must explicitely point to gnuplot binary

	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<double> normdist(0., 1.);

	std::vector<double> v0, v1;
	for (int i = 0; i < 1000; i++)
	{
		v0.push_back(normdist(mt));
		v1.push_back(normdist(mt));
	}

	std::partial_sum(v0.begin(), v0.end(), v0.begin());
	std::partial_sum(v1.begin(), v1.end(), v1.begin());

	gp << "set title 'test Graph eh' \n";
	gp << "plot '-' with lines title 'v0',"
		<< "'-' with lines title 'v1' \n";
	gp.send(v0);
	gp.send(v1);


	std::cin.get();


}








