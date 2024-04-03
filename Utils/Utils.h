#ifndef Utils_H
#define Utils_H

#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
T GetRandomFromArray(T *const *Array, std::size_t size)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::size_t RandomIndex = std::rand() % size;

    return *Array[RandomIndex];
}

#endif // !Utils_H
