#include "Filters.hpp"
#include "../include/Iris.hpp"
#include <assert.h>
#include <math.h>

using namespace processors;

void GAUSSIANFILTER::getFilterMatrix(MATRIX<uint8_t>* filterMatrix, int x, int y)
{
    assert(x % 2 != 0 && y % 2 != 0);

    const int SIGMA = 3;

    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            filterMatrix->setElement(gaussianKernel(i, j, SIGMA), (i + 1), (j + 1));
        }
    }
}

double GAUSSIANFILTER::gaussianKernel(int x, int y, int sigma)
{
    return exp(-1 * (pow(x, 2) + pow(y, 2)) / (2 * pow(sigma, 2))) / (2 * M_PI * pow(sigma, 2));
}

void BOXFILTER::getFilterMatrix(MATRIX<uint8_t>* filterMatrix, int x, int y, uint8_t blur)
{
    assert(x % 2 != 0 && y % 2 != 0);

    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            filterMatrix->setElement(blur, (i + 1), (j + 1));
        }
    }
}