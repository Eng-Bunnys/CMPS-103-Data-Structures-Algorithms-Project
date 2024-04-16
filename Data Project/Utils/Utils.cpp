#include "Utils.h"

namespace Utils
{
    int GenerateRandomNumber(int Min, int Max)
    {
        // Seed for the random number generator
        static std::random_device RandomDevice;
        static std::mt19937 RandomEngine(RandomDevice());

        // Defining the distribution for random numbers
        std::uniform_int_distribution<int> UniformDistribution(Min, Max);

        // Returning the generated random number
        return UniformDistribution(RandomEngine);
    }
}