#pragma once
#include <vector>
#include <algorithm>																			//for randomiseing vector
#include <iostream>

class individual {
private:
	std::vector<int> p_route{};																	//vector to hold the route
	float p_fitness{};																			//variable to hold the fitness
public:

	individual(std::vector<std::vector<float> >& World, int worldSize)							//constructor
	{
		p_route = randomiseRoute(worldSize, p_route);											//generate a random rout between cities
	}

	~individual()																				//destructor
	{

	}

	std::vector<int> randomiseRoute(int worldSize, std::vector<int>& p_route)
	{

		for (int i = 0; i < worldSize; i++)                                                     //Create vector from 0 to worldSize
		{
			p_route.push_back(i);
		}

		std::random_shuffle(p_route.begin(), p_route.end());									//use algroithm library to shuffle the vector

		for (auto element : p_route) {															//print route

			std::cout << element << " ";

			std::cout << "\n";
		}

		return p_route;
	}
};

