#include "ImageReader.hpp"
#include "ImageProcessor.hpp"
#include "../include/Iris.hpp"
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace imageIO;

BMPREADER::BMPREADER(std::string filename)
    : m_filename(filename)
{
    this->m_fstream = std::ifstream(m_filename, std::ios::in | std::ios::binary);  
}

BMPREADER::~BMPREADER()
{
    this->m_fstream.close();
}

void BMPREADER::setFile(std::string filename)
{
    this->m_filename = filename;
}

std::string BMPREADER::getFile()
{
    return this->m_filename;
}

void BMPREADER::readFileHeader(BMPFILEHEADER* fileHeader)
{
    assert(m_fstream.is_open());

    m_fstream.read(reinterpret_cast<char*>(&(fileHeader->bfType)), sizeof(fileHeader->bfType));
    m_fstream.read(reinterpret_cast<char*>(&(fileHeader->bfSize)), sizeof(fileHeader->bfSize));
    m_fstream.read(reinterpret_cast<char*>(&(fileHeader->bfReserved1)), sizeof(fileHeader->bfReserved1));
    m_fstream.read(reinterpret_cast<char*>(&(fileHeader->bfReserved2)), sizeof(fileHeader->bfReserved2));
    m_fstream.read(reinterpret_cast<char*>(&(fileHeader->bfOffBits)), sizeof(fileHeader->bfOffBits));
}

void BMPREADER::readInfoHeader(BMPINFOHEADER* infoHeader)
{
    assert(m_fstream.is_open());

    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biSize)), sizeof(infoHeader->biSize));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biWidth)), sizeof(infoHeader->biWidth));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biHeight)), sizeof(infoHeader->biHeight));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biPlanes)), sizeof(infoHeader->biPlanes));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biBitCount)), sizeof(infoHeader->biBitCount));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biCompression)), sizeof(infoHeader->biCompression));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biSizeImage)), sizeof(infoHeader->biSizeImage));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biXPelsPerMetre)), sizeof(infoHeader->biXPelsPerMetre));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biYPelsPerMetre)), sizeof(infoHeader->biYPelsPerMetre));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biClrUsed)), sizeof(infoHeader->biClrUsed));
    m_fstream.read(reinterpret_cast<char*>(&(infoHeader->biClrImportant)), sizeof(infoHeader->biClrImportant));
}

void BMPREADER::readColourTable(COLOURTABLE* colourTable)
{
    assert(m_fstream.is_open());

    m_fstream.read(reinterpret_cast<char*>(&(colourTable->blue)), sizeof(colourTable->blue));
    m_fstream.read(reinterpret_cast<char*>(&(colourTable->green)), sizeof(colourTable->green));
    m_fstream.read(reinterpret_cast<char*>(&(colourTable->red)), sizeof(colourTable->red));
    m_fstream.read(reinterpret_cast<char*>(&(colourTable->reserved)), sizeof(colourTable->reserved));
}

void BMPREADER::readPixelData(PIXELDATA* pixelData, uint32_t imageSize)
{
    assert(m_fstream.is_open());

    std::vector<uint8_t> buffer(imageSize);
    m_fstream.read(reinterpret_cast<char*>(buffer.data()), imageSize);

    processors::groupPixelUnits(&buffer, pixelData);

}
