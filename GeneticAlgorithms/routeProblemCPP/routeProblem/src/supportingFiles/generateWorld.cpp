# include "generateWorld.h"

std::vector < std::vector<float> > generateWorld(int worldSize) {                               //multidimensional vector since it must be dynamic at runtime
    srand(static_cast <unsigned> (time(0)));                                                    //seeding the rand() for good random number generation
    std::vector<std::vector<float> > World;
    for (int i = 0; i < 2; i++)                                                                   //number of rows
    {
        std::vector<float> temp;
        for (int j = 0; j < worldSize; j++)                                                       //number of columns
        {
            float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0)); //create a random float between 0 and 1000.0
            temp.push_back(r2);                                                                 //add an element to the end of the vector, containing a random number
        }

        World.push_back(temp);                                                                  //append the temp vector to the World vector of vectors
    }


    return World;
}