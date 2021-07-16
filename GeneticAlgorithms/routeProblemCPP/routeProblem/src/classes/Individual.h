#pragma once
#include <vector>
#include <algorithm>																							//for randomiseing vector
#include <iostream>
#include <cmath>																								//for maths, would you believe

class Individual {
private:
	std::vector<int> m_route{};																					//vector to hold the route
	float m_fitness{};																							//variable to hold the fitness
public:

	Individual(std::vector<std::vector<float> >& World, int worldSize);											//constructor


	~Individual();																								//destructor


	std::vector<int> randomiseRoute(int worldSize, std::vector<int>& m_route);


	float evaluateFitness(std::vector<int>& m_route, std::vector<std::vector<float> >& World, int worldSize);	//use the route and the city locations to determine the fitness of the Individual

	float getFitness();																							//getter for fitness

	const std::vector<int> getRoute() const;																	//gets the route
};

