#pragma once

#include <array>

#ifndef IMAGECOMPONENTS_H

/**
 * @brief Contains the components of an image that are common to all kinds of image formats.
*/
#define IMAGECOMPONENTS_H 

/**
 * @brief The values represent the indices of the channels that are placed in the PIXELARRAY unit.
*/
enum CHANNELS
{
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

/**
 * @brief An array type that represents the individual pixel values, with three sub-pixel values being stored at the indices
 *        0, 1, 2, representing the values Red, Green, Blue respectively.
*/
typedef std::array<uint8_t, 3> PIXELARRAY;

#endif