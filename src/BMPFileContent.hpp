#pragma once

#include <cstdint>
#include <vector>

#include "ImageComponents.hpp"

#ifndef BMPFILEHEADERS_H
#define BMPFILEHEADERS_H

struct __attribute__((__packed__)) BMPFILEHEADER
{

    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;

};

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

struct __attribute__((__packed__)) COLOURTABLE
{

    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;

};

struct PIXELDATA
{

    std::vector<PIXELARRAY> pixelData;
      
};



#endif