#include "Individual.h"

Individual::Individual(std::vector<std::vector<float> >& World, int worldSize)								//constructor
{
	m_route = randomiseRoute(worldSize, m_route);															//generate a random rout between cities
	evaluateFitness(m_route, World, worldSize);																//evaluate the fitness (distance of full route)
}

Individual::~Individual()																					//destructor
{

}

std::vector<int> Individual::randomiseRoute(int worldSize, std::vector<int>& m_route)
{

	for (int i = 0; i < worldSize; i++)																		//Create vector from 0 to worldSize
	{
		m_route.push_back(i);
	}

	std::random_shuffle(m_route.begin(), m_route.end());													//use algroithm library to shuffle the vector

	/*
	for (auto element : m_route) {																			//print route

		std::cout << element << " " << '\n';
	}
	*/

	return m_route;
}

float Individual::evaluateFitness(std::vector<int>& m_route, std::vector<std::vector<float> >& World, int worldSize)	//use the route and the city locations to determine the fitness of the Individual
{

	m_fitness = 0;																							//init m_fitness

	for (int i = 0; i < worldSize - 1; i++) {																//iterate n-1 times, where n is the worldsiz
		int y = i + 1;
		int city1Loc = m_route[i];																			//get 1st city location
		int city2Loc = m_route[y];																			//get second city location

		float city1X = World[city1Loc][0];																	//get city 1 x
		float city1Y = World[city1Loc][1];																	//get city 1 y

		float city2X = World[city2Loc][0];																	//get city 2 x
		float city2Y = World[city2Loc][1];																	//get city 2 y

		m_fitness = m_fitness + sqrt(pow(city1X - city2X, 2.0) + pow(city1Y - city2Y, 2.0));				//pythag.
	}

	//std::cout << m_fitness << '\n';
	return m_fitness;
}

float Individual::getFitness()																				//getter for the fitness
{
	return m_fitness;
}

const std::vector<int> Individual::getRoute()	const																				//gets the route
{
	return m_route;
}