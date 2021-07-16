#include "Population.h"


Population::Population(std::vector<std::vector<float> >& World, int worldSize) {																	//constructor

	std::vector<Individual> m_pop(10, Individual(World, worldSize));
	
	std::cout << m_pop[0].getFitness() << '\n';
	std::cout << m_pop[1].getFitness() << '\n';
	std::cout << m_pop[9].getFitness() << '\n';

}

