#include "ImageReader.hpp"
#include "ImageWriter.hpp"
#include "BMPImage.hpp"
#include "BMPFileContent.hpp"
#include "../include/Iris.hpp"
#include "ImageProcessor.hpp"
#include "Matrix.hpp"
#include <string>
#include <iostream>

void logFileHeaders(BMPFILEHEADER* fileHeader, BMPINFOHEADER* infoHeader, COLOURTABLE* colourTable, PIXELDATA* pixelData)
{
    const std::string filename = "../../log.txt";

    Iris::logInfoToFile("BMP file headers: ", filename);
    Iris::logInfoToFile("Type: " + std::to_string(fileHeader->bfType), filename);
    Iris::logInfoToFile("Size: " + std::to_string(fileHeader->bfSize), filename);
    Iris::logInfoToFile("Reserved Bits 1: " + std::to_string(fileHeader->bfReserved1), filename);
    Iris::logInfoToFile("Reserved Bits 2: " + std::to_string(fileHeader->bfReserved2), filename);
    Iris::logInfoToFile("Bit Offset: " + std::to_string(fileHeader->bfOffBits), filename);

    Iris::logInfoToFile("BMP info headers: ", filename);
    Iris::logInfoToFile("Header Size: " + std::to_string(infoHeader->biSize), filename);
    Iris::logInfoToFile("Image width: " + std::to_string(infoHeader->biWidth), filename);
    Iris::logInfoToFile("Image height: " + std::to_string(infoHeader->biHeight), filename);
    Iris::logInfoToFile("Image planes: " + std::to_string(infoHeader->biPlanes), filename);
    Iris::logInfoToFile("Colour bit count: " + std::to_string(infoHeader->biBitCount), filename);
    Iris::logInfoToFile("Image Compression: " + std::to_string(infoHeader->biCompression), filename);
    Iris::logInfoToFile("Image Size: " + std::to_string(infoHeader->biSizeImage), filename);
    Iris::logInfoToFile("Pels in the X direction: " + std::to_string(infoHeader->biXPelsPerMetre), filename);
    Iris::logInfoToFile("Pels in the Y direction: " + std::to_string(infoHeader->biYPelsPerMetre), filename);
    Iris::logInfoToFile("Colours Used: " + std::to_string(infoHeader->biClrUsed), filename);
    Iris::logInfoToFile("Important Colours: " + std::to_string(infoHeader->biClrImportant), filename);

    Iris::logInfoToFile("Colour table: ", filename);
    Iris::logInfoToFile("Blue: " + std::to_string(colourTable->blue), filename);
    Iris::logInfoToFile("Green: " + std::to_string(colourTable->green), filename);
    Iris::logInfoToFile("Red: " + std::to_string(colourTable->red), filename);
    Iris::logInfoToFile("Reserved: " + std::to_string(colourTable->reserved), filename);

    Iris::logInfoToFile("Pixel data: ", filename);
    Iris::logInfoToFile("Pixel data size: " + std::to_string(pixelData->pixelData.size()), filename);
}


int main()
{
    std::string filename = "/mnt/c/Users/luvai_kcrxbon/C++Projects/upscaler/image/test-image.bmp";
    std::string dest_filename = "/mnt/c/Users/luvai_kcrxbon/C++projects/upscaler/image/processed-image.bmp";
    Iris::info("Reading from file: " + filename + "...");
    
    imageIO::BMPREADER reader(filename);
    BMPFILEHEADER fileHeader;
    BMPINFOHEADER infoHeader;
    COLOURTABLE colourTable;
    PIXELDATA originalPixels;

    reader.readFileHeader(&fileHeader);
    Iris::info("Read image file header.");
    reader.readInfoHeader(&infoHeader);
    Iris::info("Read image info header.");
    reader.readColourTable(&colourTable);
    Iris::info("Read image colour table.");
    reader.readPixelData(&originalPixels, infoHeader.biSizeImage);
    Iris::info("Read image pixel data.");

    logFileHeaders(&fileHeader, &infoHeader, &colourTable, &originalPixels);

    std::vector<uint8_t> r_channel, g_channel, b_channel;
    
    processors::extractBlue(&(originalPixels.pixelData), &b_channel);
    processors::extractGreen(&(originalPixels.pixelData), &g_channel);
    processors::extractRed(&(originalPixels.pixelData), &r_channel);

    Iris::info("Extracted RGB channels from image.");

    PIXELDATA reconstructedPixels;

    processors::recreateColourMatrix(&r_channel, &g_channel, &b_channel, &(reconstructedPixels.pixelData));

    Iris::info("Reconstructed colour matrix with RGB channels.");

    images::BMPIMAGE image(fileHeader, infoHeader, colourTable, reconstructedPixels);

    imageIO::BMPWRITER writer(dest_filename);
    Iris::info("Writing to file: " + dest_filename + "...");
    
    writer.writeFileHeader(image.getFileHeader());
    Iris::info("Written image file header.");
    writer.writeInfoHeader(image.getInfoHeader());
    Iris::info("Written image info header.");
    writer.writeColourTable(image.getColourTable());
    Iris::info("Written image colour table.");
    writer.writePixelData(image.getPixelData());
    Iris::info("Written image pixel data.");
    return 0;
}