#include "Filters.hpp"
#include "../include/Iris.hpp"
#include <assert.h>
#include <math.h>

using namespace processors;

void GAUSSIANFILTER::getFilterMatrix(std::vector<std::vector<uint8_t>>* filterMatrix, int x, int y)
{
    assert(x % 2 != 0 && y % 2 != 0);

    const int SIGMA = 3;

    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            filterMatrix->at(i).push_back(gaussianKernel(i, j, SIGMA));
        }
    }
}

double GAUSSIANFILTER::gaussianKernel(int x, int y, int sigma)
{
    return exp(-1 * (pow(x, 2) + pow(y, 2)) / (2 * pow(sigma, 2))) / (2 * M_PI * pow(sigma, 2));
}

void BOXFILTER::getFilterMatrix(std::vector<std::vector<uint8_t>>* filterMatrix, int x, int y, int blur)
{
    assert(x % 2 != 0 && y % 2 != 0);

    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            filterMatrix->at(i).push_back(blur);
        }
    }
}