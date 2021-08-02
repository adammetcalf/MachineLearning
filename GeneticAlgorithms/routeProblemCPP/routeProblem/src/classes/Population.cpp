#include "Population.h"


Population::Population(std::vector<std::vector<float> >& World, int worldSize) {																	//constructor

	for (int i = 0; i < 10; i++)
	{
		m_pop.push_back(Individual(World, worldSize));
		//std::cout << m_pop[i].getFitness() << '\n';
	}

	sortFitness();
}

const std::vector<Individual> Population::getPopulation() const
{

	return m_pop;

}



void Population::sortFitness()																														//sort by fitness (low to high). 
{

	std::sort(m_pop.begin(), m_pop.end(), [](Individual& one, Individual& two) {return one.getFitness() < two.getFitness(); });

}

std::vector < std::vector<float> > Population::getBestRoute(std::vector<std::vector<float> >& World, int worldSize)
{
	sortFitness();																//sort
	std::vector<int> bestRouteIndex = m_pop[0].getRoute();						//gets route index from best individual

	//sort World into order of best route

	//World[0];	xrow
	//World[1]; yrow

	std::vector<std::vector<float> > BestRoute;

	std::vector<float> xtemp;																//xtemp
	for (int j = 0; j < worldSize; j++)                                                    //number of columns
	{
		xtemp.push_back(World[0][bestRouteIndex[j]]);                                                                 //add an element to the end of the vector, containing a random number
	}

	std::vector<float> ytemp;																//xtemp
	for (int j = 0; j < worldSize; j++)                                                    //number of columns
	{
		ytemp.push_back(World[1][bestRouteIndex[j]]);                                                                 //add an element to the end of the vector, containing a random number
	}

	BestRoute.push_back(xtemp);
	BestRoute.push_back(ytemp);

	return BestRoute;
}