#pragma once

#include <vector>
#include <cstdint>

#include "ImageComponents.hpp"
#include "BMPFileContent.hpp"

#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

enum CHANNELS
{
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

namespace processors
{
    void extractBlue(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* b_channel);
    void extractGreen(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* g_channel);
    void extractRed(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* r_channel);

    void groupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData);
    void ungroupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData);
    
    void recreateColourMatrix(std::vector<uint8_t>* r_channel, 
                              std::vector<uint8_t>* g_channel, 
                              std::vector<uint8_t>* b_channel,
                              std::vector<PIXELARRAY>* matrix);
}

#endif