#include "ImageProcessor.hpp"
#include "BMPFileContent.hpp"

void processors::groupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData)
{
    for(uint32_t i = 0; i < buffer->size(); i += 3)
    {
        PIXELARRAY pixel = {buffer->at(i + RED), buffer->at(i + GREEN), buffer->at(i + BLUE)};
        pixelData->pixelData.push_back(pixel);
    }
}

void processors::ungroupPixelUnits(std::vector<uint8_t>* buffer, PIXELDATA* pixelData)
{
    for(uint32_t i = 0; i < pixelData->pixelData.size(); ++i)
    {
        buffer->push_back(pixelData->pixelData.at(i)[RED]);
        buffer->push_back(pixelData->pixelData.at(i)[GREEN]);
        buffer->push_back(pixelData->pixelData.at(i)[BLUE]);
    }
}