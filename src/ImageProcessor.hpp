#pragma once

#include <vector>
#include <cstdint>

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
    void extractBlue(PIXELDATA* pixel);
    void extractGreen(PIXELDATA* pixels);
    void extractRed(PIXELDATA* pixels);

    void groupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData);
    void ungroupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData);
}

#endif