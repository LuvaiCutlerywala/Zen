#include "ImageProcessor.hpp"
#include "../include/Iris.hpp"

static void extractChannel(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* buffer, CHANNELS channel);

void processors::groupPixelUnits(std::vector<uint8_t>* buffer, std::vector<PIXELARRAY>* container)
{
    for(uint32_t i = 0; i < buffer->size(); i += 3)
    {
        PIXELARRAY pixel = {buffer->at(i + RED), buffer->at(i + GREEN), buffer->at(i + BLUE)};
        container->push_back(pixel);
    }
}

void processors::ungroupPixelUnits(std::vector<uint8_t>* buffer, std::vector<PIXELARRAY>* container)
{
    for(uint32_t i = 0; i < container->size(); ++i)
    {
        buffer->push_back(container->at(i)[RED]);
        buffer->push_back(container->at(i)[GREEN]);
        buffer->push_back(container->at(i)[BLUE]);
    }
}

void extractBlue(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* b_channel)
{
    extractChannel(pixels, b_channel, BLUE);
}

void extractGreen(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* g_channel)
{
    extractChannel(pixels, g_channel, GREEN);
}

void extractRed(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* r_channel)
{
    extractChannel(pixels, r_channel, RED);
}

void extractChannel(std::vector<PIXELARRAY>* pixels, std::vector<uint8_t>* buffer, CHANNELS channel)
{
    for(unsigned int i = 0; i < pixels->size(); ++i)
    {
        buffer->push_back(pixels->at(i)[channel]);
    }
}

void recreateColourMatrix(std::vector<uint8_t>* r_channel, 
                          std::vector<uint8_t>* g_channel, 
                          std::vector<uint8_t>* b_channel,
                          std::vector<PIXELARRAY>* matrix)
{
    Iris::logWarnIfFalse((r_channel->size() == g_channel->size()) && (r_channel->size() == b_channel->size()),
                         "Channel dimensions are not equal.");

    for(unsigned int i = 0; i < r_channel->size(); ++i)
    {
        matrix->push_back({r_channel->at(i), g_channel->at(i), b_channel->at(i)});
    }
}