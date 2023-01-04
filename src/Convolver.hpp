#pragma once

#include <cstdint>
#include <vector>
#include "Matrix.hpp"

#ifndef CONVOLVER_H
#define CONVOLVER_H

namespace processors
{
    /**
     * @brief Provides methods to convolve images with filters to provide blurring. Blurring is a very commonly used
     *        technique that allows for methods of upscaling and downscaling such as Lanczos resampling to be effectively
     *        used. Resampling, or more commonly, rescaling, is a process which generally incurs certain problems such as
     *        patterns, called Moire patterns, or aliasing. This causes the image to look like it is superimposed with some
     *        copyright mark, or is very noisy, and blurring allows the image to be blurred enough to remove the most
     *        noticeable parts of the aliasing, which leaves the image being relatively denoised. Convolution is essentially
     *        averaging a function with another windowing function, which acts only in a certain region. The convolved
     *        average presents us with the average of the initial function.
    */
    class CONVOLVER
    {  
        public:
        /**
         * @brief Convolves the image with a box filter. This means that the image blurs pretty evenly, where the contrast
         *        between the colours in the image is lost.
         * @param image The image matrix.
         * @param convolvedImage The matrix to store the convolved image.
        */
        static void convolveImageWithBoxFilter(MATRIX<uint8_t>* image, MATRIX<uint8_t>* convolvedImage);

        /**
         * @brief Convolves the image with a Gaussain filter. This means that the image blurs rather evenly, but the
         *        contrast between sharply differing colours is not lost, which leaves the image with an impression of
         *        depth.
         * @param image The image matrix.
         * @param convolvedImage The matrix to store the convolved image.
        */
        static void convolveImageWithGaussianFilter(MATRIX<uint8_t>* image, MATRIX<uint8_t>* convolvedImage);

        private:
        /**
         * @brief Extracts a sub-matrix from the image matrix with dimensions of the sample matrix. It is used when
         *        convoluting images with filters to create a matrix to convolve the filter with.
         * @param imageMatrix The image matrix.
         * @param sampleMatrix The sample matrix.
         * @param i The location of the pointer in the image matrix in the y direction.
         * @param j The location of the pointer in the image matrix in the x direction.
         * 
        */ 
        static void extractSampleMatrix(MATRIX<uint8_t>* imageMatrix, MATRIX<uint8_t>* sampleMatrix, int i, int j);

        /**
         * @brief Convolves a sample and filter matrix to produce a single value, which will then be the value used in the
         *        convolved image.
         * @param imageMatrix The image matrix.
         * @param filterMatrix The filter matrix.
        */
        static uint8_t convolveMatrices(MATRIX<uint8_t>* imageMatrix, MATRIX<uint8_t>* filterMatrix);
    };
}

#endif