#pragma once
#include <vector>
#include <iostream>
#include "Individual.h"





class Population
{
private:
	std::vector<Individual> m_pop{};														//vector of 'Individual' objects
public:

	Population(std::vector<std::vector<float> >& World, int worldSize);																		//constructor

	
};

