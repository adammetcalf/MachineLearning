#pragma once
#include <vector>
#include <algorithm>																							//for randomiseing vector
#include <iostream>
#include <cmath>																								//for maths, would you believe

class individual {
private:
	std::vector<int> p_route{};																					//vector to hold the route
	float p_fitness{};																							//variable to hold the fitness
public:

	individual(std::vector<std::vector<float> > &World, int worldSize)											//constructor
	{
		p_route = randomiseRoute(worldSize, p_route);															//generate a random rout between cities
		evaluateFitness(p_route, World, worldSize);																//evaluate the fitness (distance of full route)
	}

	~individual()																								//destructor
	{

	}

	std::vector<int> randomiseRoute(int worldSize, std::vector<int> &p_route)
	{

		for (int i = 0; i < worldSize; i++)																		//Create vector from 0 to worldSize
		{
			p_route.push_back(i);
		}

		std::random_shuffle(p_route.begin(), p_route.end());													//use algroithm library to shuffle the vector

		for (auto element : p_route) {																			//print route

			std::cout << element << " " << '\n';
		}

		return p_route;
	}

	float evaluateFitness(std::vector<int> &p_route, std::vector<std::vector<float> > &World, int worldSize)	//use the route and the city locations to determine the fitness of the individual
	{

		p_fitness = 0;																							//init p_fitness

		for (int i = 0; i < worldSize-1; i++) {																	//iterate n-1 times, where n is the worldsiz
			int y = i + 1;
			int city1Loc = p_route[i];																			//get 1st city location
			int city2Loc = p_route[y];																			//get second city location

			float city1X = World[city1Loc][0];																	//get city 1 x
			float city1Y = World[city1Loc][1];																	//get city 1 y

			float city2X = World[city2Loc][0];																	//get city 2 x
			float city2Y = World[city2Loc][1];																	//get city 2 y

			p_fitness = p_fitness + sqrt(pow(city1X-city2X, 2.0) + pow(city1Y - city2Y, 2.0));					//pythag.
		}

		
		return p_fitness;
	}
};

