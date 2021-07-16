#include "Population.h"


Population::Population(std::vector<std::vector<float> >& World, int worldSize) {																	//constructor

	for (int i = 0; i < 10; i++)
	{
		m_pop.push_back(Individual(World, worldSize));
		//std::cout << m_pop[i].getFitness() << '\n';
	}

	sortFitness(m_pop);
}

const std::vector<Individual> Population::getPopulation() const
{

	return m_pop;

}


void Population::sortFitness(std::vector<Individual> m_pop)																	//sort by fitness (low to high). 
{
	int i, j;																											//udsing bubble sort (better sorts exist, but only 10 elements so meh
	for (i = 0; i < 10 - 1; i++)

		for (j = 0; j < 10 - i - 1; j++)

			if (m_pop[j].getFitness() > m_pop[j + 1].getFitness());
				std::swap(m_pop[j], m_pop[j+1]);


}
