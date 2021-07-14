# include "printVector.h"

void printVector(std::vector<std::vector<float> > &World)                                       //pass in dereferenced world vectors (a vector is already a pointer, derefferencing gets the actuall useful values)
{
    for (auto element : World) {
        for (auto atom : element) {
            std::cout << atom << " ";
        }
        std::cout << "\n";
    }
}