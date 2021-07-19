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
