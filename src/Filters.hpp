#pragma once

#include <cstdint>
#include <vector>
#include "Matrix.hpp"

#ifndef FILTERS_H
#define FILTERS_H

namespace processors
{ 
    /**
     * @brief A util class that provides methods to generate a Gaussian filter matrix.
     *        A Gaussian filter is an evaluation of the Gaussian function at a point (x,y), with the mean centred around the
     *        actual value being evaluated. It uses the shape of the normal bell curve to assign certain weights to the mean
     *        as well as neighbouring values, which can then be used to calculate a more fairly-distributed average.
     * 
    */
    class GAUSSIANFILTER
    {
        public:
        /**
         * @brief Generates a filter matrix of dimensions X x Y that is centred around the centre pixel, that is the pixel
         *        at point (X/2, Y/2) in the matrix. The Gaussian function is evaluated with the centre pixel being the mean
         *        with sigma, the standard deviation, usually set to 3sigmas.
         * @param filterMatrix The container for the filter matrix.
         * @param x The size of the matrix in the xth dimension.
         * @param y The size of the matrix in the yth dimension.
        */
        static void getFilterMatrix(MATRIX<uint8_t>* filterMatrix, int x, int y);

        private:
        /**
         * @brief Evaluates the Gaussian function at the point (x, y) with the standard deviation being sigma. The Gaussian
         *        function, in 2 dimensions, is of the form: e^(-(x ^ 2 + y ^ 2) / (2 * sigma ^ 2)) / (2 * sigma ^ 2 * pi).
         * @param x The position in the xth dimension.
         * @param y The position in the yth dimension.
         * @param sigma The standard deviation.
        */
        static double gaussianKernel(int x, int y, int sigma);
    };

    /**
     * @brief A util class that provides methods to generate a Box filter matrix.
     *        A box filter is a simple matrix with the same value repeated at every location, therefore making it so that 
     *        all the points around the target pixel have the same weight as in the convolution as the pixel itself. This
     *        makes the blur more reductive, as it eliminates the difference between the foreground and the background
     *        subjects.
    */
    class BOXFILTER
    {
        public:
        /**
         * @brief Generates a filter matrix with dimensions X x Y that has equal weights all across the matrix, meaning that
         *        all the pixels around the target pixel are averaged equally. The amount of blur, the weight, can be set by
         *        the blur parameter.
         * @param filterMatrix The container for the filter matrix.
         * @param x The size of the matrix in the xth dimension.
         * @param y The size of the matrix in the yth dimension.
         * @param blur The weight assigned to each pixel that the filter matrix is convolved with.
        */
        static void getFilterMatrix(MATRIX<uint8_t>* filterMatrix, int x, int y, uint8_t blur);
    };
}

#endif