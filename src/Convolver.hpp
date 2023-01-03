#pragma once

#include <cstdint>
#include <vector>

#ifndef CONVOLVER_H
#define CONVOLVER_H

namespace processors
{
    class CONVOLVER
    {  
        public:
        static void convolveImageWithBoxFilter(std::vector<std::vector<uint8_t>>* image, std::vector<std::vector<uint8_t>>* convolvedImage);
        static void convolveImageWithGaussianFilter(std::vector<std::vector<uint8_t>>* image, std::vector<std::vector<uint8_t>>* convolvedImage);

        private:
        static void extractSampleMatrix(std::vector<std::vector<uint8_t>>* imageMatrix, std::vector<std::vector<uint8_t>>* sampleMatrix, int x, int y, int i, int j);
        static void convolveMatrices(std::vector<std::vector<uint8_t>>* imageMatrix, std::vector<std::vector<uint8_t>>* filterMatrix);
    };
}

#endif