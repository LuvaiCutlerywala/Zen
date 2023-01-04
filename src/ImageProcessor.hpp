#pragma once

#include <vector>
#include <cstdint>

#include "ImageComponents.hpp"
#include "BMPFileContent.hpp"
#include "Matrix.hpp"

#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

/**
 * @brief A container of all classes and methods related to image processing. Image processing, in this case, is
 *        specifically defined as any filters applied, or rearranging done to the image so as to preserve the
 *        original size of the image.
*/
namespace processors
{   
    /**
     * @brief Extracts the blue channel from an array of PIXELARRAY units.
     * @param pixels The array of PIXELARRAY units to be extracted from.
     * @param b_channel The target container for the blue sub-matrix.
    */
    void extractBlue(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* b_channel);

    /**
     * @brief Extracts the green channel from an array of PIXELARRAY units.
     * @param pixels The array of PIXELARRAY units to be extracted from.
     * @param g_channel The target container for the green sub-matrix.
    */
    void extractGreen(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* g_channel);

    /**
     * @brief Extracts the red channel from an array of PIXELARRAY units.
     * @param pixels The array of PIXELARRAY units to be extracted from.
     * @param r_channel The target container for the red sub-matrix.
    */
    void extractRed(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* r_channel);

    /**
     * @brief A method to take the raw data read from the image file and to group them into PIXELARRAY sub-units, which
     *        would be part of the PIXELARRAY container.
     * @param buffer The container housing the raw data read from the image file.
     * @param container The container for the PIXELARRAY units.
    */
    void groupPixelUnits(std::vector<uint8_t>* buffer, std::vector<PIXELARRAY>* container);

    /**
     * @brief A method to take the data arranged in the PIXELARRAY units in its respective container and order it into a raw
     *        data container to be written to the image file.
     * @param buffer The container housing the raw data to be written to the image file.
     * @param container The container for the PIXELARRAY units.
    */
    void ungroupPixelUnits(std::vector<uint8_t>* buffer, std::vector<PIXELARRAY>* container);
    
    /**
     * @brief A method to reconstruct a PIXELARRAY matrix provided the three component channel sub-matrices.
     * @param r_channel The array for the red matrix.
     * @param g_channel The array for the green matrix.
     * @param b_channel The array for the blue matrix.
     * @param matrix The container matrix for the PIXELARRAY units to be constructed.
    */
    void recreateColourMatrix(std::vector<uint8_t>* r_channel, 
                              std::vector<uint8_t>* g_channel, 
                              std::vector<uint8_t>* b_channel,
                              std::vector<PIXELARRAY>* matrix);
}

#endif