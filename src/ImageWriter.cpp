#include "ImageWriter.hpp"
#include "ImageProcessor.hpp"
#include "../include/Iris.hpp"
#include <assert.h>

using namespace imageIO;

BMPWRITER::BMPWRITER(std::string filename)
    : m_filename(filename)
{
    this->m_fstream = std::ofstream(this->m_filename, std::ios::out | std::ios::binary);
}

BMPWRITER::~BMPWRITER()
{
    this->m_fstream.close();
}

void BMPWRITER::setFile(std::string filename)
{
    this->m_filename = filename;
}

std::string BMPWRITER::getFile()
{
    return this->m_filename;
}

void BMPWRITER::writeFileHeader(BMPFILEHEADER* fileHeader)
{

    assert(m_fstream.is_open());

    m_fstream.write(reinterpret_cast<char*>(&(fileHeader->bfType)), sizeof(fileHeader->bfType));
    m_fstream.write(reinterpret_cast<char*>(&(fileHeader->bfSize)), sizeof(fileHeader->bfSize));
    m_fstream.write(reinterpret_cast<char*>(&(fileHeader->bfReserved1)), sizeof(fileHeader->bfReserved1));
    m_fstream.write(reinterpret_cast<char*>(&(fileHeader->bfReserved2)), sizeof(fileHeader->bfReserved2));
    m_fstream.write(reinterpret_cast<char*>(&(fileHeader->bfOffBits)), sizeof(fileHeader->bfOffBits));
}

void BMPWRITER::writeInfoHeader(BMPINFOHEADER* infoHeader)
{
    assert(m_fstream.is_open());

    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biSize)), sizeof(infoHeader->biSize));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biWidth)), sizeof(infoHeader->biWidth));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biHeight)), sizeof(infoHeader->biHeight));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biPlanes)), sizeof(infoHeader->biPlanes));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biBitCount)), sizeof(infoHeader->biBitCount));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biCompression)), sizeof(infoHeader->biCompression));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biSizeImage)), sizeof(infoHeader->biSizeImage));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biXPelsPerMetre)), sizeof(infoHeader->biXPelsPerMetre));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biYPelsPerMetre)), sizeof(infoHeader->biYPelsPerMetre));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biClrUsed)), sizeof(infoHeader->biClrUsed));
    m_fstream.write(reinterpret_cast<char*>(&(infoHeader->biClrImportant)), sizeof(infoHeader->biClrImportant));
}

void BMPWRITER::writeColourTable(COLOURTABLE* colourTable)
{
    assert(m_fstream.is_open());

    m_fstream.write(reinterpret_cast<char*>(&(colourTable->blue)), sizeof(colourTable->blue));
    m_fstream.write(reinterpret_cast<char*>(&(colourTable->green)), sizeof(colourTable->green));
    m_fstream.write(reinterpret_cast<char*>(&(colourTable->red)), sizeof(colourTable->red));
    m_fstream.write(reinterpret_cast<char*>(&(colourTable->reserved)), sizeof(colourTable->reserved));
}

void BMPWRITER::writePixelData(PIXELDATA* pixelData)
{
    assert(m_fstream.is_open());

    std::vector<uint8_t> buffer;

    processors::ungroupPixelUnits(&buffer, pixelData);

    for(uint32_t i = 0; i < buffer.size(); ++i)
    {
        m_fstream.write(reinterpret_cast<char*>(&(buffer.at(i))), sizeof(buffer.at(i)));
    }
    
}