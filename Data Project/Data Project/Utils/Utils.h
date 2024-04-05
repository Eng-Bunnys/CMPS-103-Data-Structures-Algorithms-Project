/*
I went for the <random> lib since it gives us better control over randomness
when testing using the time method it always returned the same elements and this is not ideal (yes I've tested it multiple times)
after doing some research I decided to use this method & I have documented what I've done incase you don't know what's going on here

Docs:
https://cplusplus.com/reference/random/
https://en.cppreference.com/w/cpp/numeric/random/random_device
https://cplusplus.com/reference/random/mt19937/
https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
*/
#ifndef Utils_H
#define Utils_H

#include <random>

/**
 * Generates a random number between the specified minimum and maximum values
 *
 * @param Min Minimum value of the range
 * @param Max Maximum value of the range
 * @return Random number within the specified range [min, max]
 */
int GenerateRandomNumber(int Min = 0, int Max = 100)
{
    // Seed for the random number generator
    static std::random_device RandomDevice;
    static std::mt19937 RandomEngine(RandomDevice());

    // Defining the distribution for random numbers
    std::uniform_int_distribution<int> UniformDistribution(Min, Max);

    // Returning the generated random number
    return UniformDistribution(RandomEngine);
}

/**
 * Returns a random element from an array of pointers
 *
 * @param Array Pointer to an array of pointers
 * @param size Size of the array
 * @return Random element from the array
 */
template <typename T>
T GetRandomFromArray(T *const *Array, int Size)
{
    if (Size == 0)
        throw std::exception("Array size is zero.");

    // Generate a random index
    int RandomIndex = GenerateRandomNumber(0, Size - 1);

    // Return the random element from the array
    return *Array[RandomIndex];
}

#endif // !Utils_H