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

namespace Utils
{
    /**
     * Generates a random number between the specified minimum and maximum values
     *
     * @param Min Minimum value of the range
     * @param Max Maximum value of the range
     * @return Random number within the specified range [min, max]
     */
    int GenerateRandomNumber(int Min = 0, int Max = 100);

    /// To-Do: Add JSDocs

    double SafeSubtraction(double Value, double Subtrahend);
    double SafeDivision(double Numerator, double Denominator);
}
#endif // !Utils_H