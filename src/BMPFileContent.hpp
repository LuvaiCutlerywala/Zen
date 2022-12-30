#pragma once

#include <cstdint>
#include <vector>

#include "ImageComponents.hpp"

#ifndef BMPFILEHEADERS_H

/**
 * @brief Defines the structures to house the data for the individual components of a BMP file.
*/
#define BMPFILEHEADERS_H

/**
 * @brief Structure holding the values for a BMP file header. Source can be found at: 
 *        https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html
 *          
 *        The bytes are ordered as such:
 *        2 - bfType : The type of file. Always set to 19778 to indicate Bitmap.
 *        4 - bfSize : The header size.
 *        2 - bfReserved1 : Reserved bytes. Must always be set to 0.
 *        2 - bfReserved2 : Reserved bytes. Must always be set to 0.
 *        4 - bfOffBits : The offset from the header to the pixel data in bytes.
 * */ 
struct __attribute__((__packed__)) BMPFILEHEADER
{

    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;

};

/**
 * @brief Structure holding the values for a BMP information header. Source can be found at: 
 *        https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html
 * 
 *        The bytes are ordered as such:
 *        4 - biSize : The size of the information header.
 *        4 - biWidth : The image width.
 *        4 - biHeight : The image height.
 *        2 - biPlanes : The number of planes the image has, e.g. viewing angles.
 *        2 - biBitCount : The number of bits used to represent a single pixel.
 *        4 - biCompression : The amount of compression applied to the image, usually set to 0 to indicate no compression
 *                            used.
 *        4 - biSizeImage : The image size in bytes. If the compression is set to 0, it can be set to 0.
 *        4 - biXPelsPerMetre : The number of horizontal pixels on the target device. Can be set to 0.
 *        4 - biYPelsPerMetre : The number of vertical pixels on the target device. Can be set to 0.
 *        4 - biClrUsed : The number of colours used. If bit count is set, it can be set to 0.
 *        4 - biClrImportant : The number of important colours for the Bitmap, to help determine what to keep when
 *                             compressing the image. It can be set to 0, indicating that all colours are important.
 * */
struct __attribute__((__packed__)) BMPINFOHEADER
{

    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMetre;
    uint32_t biYPelsPerMetre;
    uint32_t biClrUsed;
    uint32_t biClrImportant;

};

/**
 * @brief Structure holding the values for a BMP colour table. Source can be found at: 
 *        https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html
 * 
 *        The bytes are ordered as such:
 *        1 - blue : Specifies the blue part of the colour.
 *        1 - green : Specifies the green part of the colour.
 *        1 - red : Specifies the red part of the colour.
 *        1 - reserved : Specifies the reserved bits in the colour. Can be sometimes used to indicate an alpha channel.
 * */
struct __attribute__((__packed__)) COLOURTABLE
{

    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;

};

/**
 * @brief Structure holding the values for the BMP image data. A vector that wraps an array of PIXELARRAY units.
 * 
 *        The pixels are stored in a FILO arrangement, therefore the top of the image is acutally stored near to the end of
 *        file. This is handled by the image viewing application, as it adjusts for the image pixel ordering. Each pixel is
 *        stored as the three sub-pixels, which when read means that the raw data is read into a buffer, and then grouped
 *        PIXELARRAY units, each of which represents an individual pixel, with its three RGB components. The pixels are
 *        currently stored as a one-dimensional array, without any structure. This probably will be amended, but currently
 *        the idea is to use matrix representation to read the pixels into before committing any operations. The structure
 *        is only relegated to when there are operations being done on the pixels, so as to not bring extra and unnecessary
 *        complications into a simple storage container.
*/
struct PIXELDATA
{

    std::vector<PIXELARRAY> pixelData;
      
};



#endif