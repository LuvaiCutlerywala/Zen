#pragma once

#include <cstdint>

#ifndef FILTERS_H
#define FILTERS_H

namespace processors
{   
    /**
     * @brief A util class that provides methods to generate a Gaussian filter matrix.
     *        A Gaussian filter is an evaluation of the Gaussian function at a point (x,y), with the mean centred around the
     *        actual value being evaluated. It uses the shape of the normal bell curve to assign certain weights to the mean
     *        as well as neighbouring values, which can then be used to calculate a more well-distributed average.
     * 
    */
    class GAUSSIANFILTER
    {
        
    };
}

#endif