#pragma once
#include <vector>
#include <iostream>
#include "Individual.h"
#include <algorithm>





class Population
{
private:
	std::vector<Individual> m_pop{};														//vector of 'Individual' objects
public:

	Population(std::vector<std::vector<float> >& World, int worldSize);						//constructor

	const std::vector<Individual> getPopulation() const;									//gets the population

	void sortFitness();																		//sort by fitness (low to high). 


};

