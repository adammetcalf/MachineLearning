#pragma once
#include <cstdlib>							                                                    //for rand()
#include <ctime>                                                                                //for random number seeding
#include <vector>

std::vector < std::vector<float> > generateWorld(int worldSize);                                //forwards declare generateWorld