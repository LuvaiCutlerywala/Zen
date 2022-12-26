#include "BMPImage.hpp"

using namespace images;

BMPIMAGE::BMPIMAGE(BMPFILEHEADER fileHeader, BMPINFOHEADER infoHeader, COLOURTABLE colourTable, PIXELDATA pixelData)
    : m_fileHeader(fileHeader), m_infoHeader(infoHeader), m_colourTable(colourTable), m_pixelData(pixelData)
{}

BMPIMAGE::~BMPIMAGE()
{}

void BMPIMAGE::setFileHeader(BMPFILEHEADER fileHeader)
{
    this->m_fileHeader = fileHeader;
}

void BMPIMAGE::setInfoHeader(BMPINFOHEADER infoHeader)
{
    this->m_infoHeader = infoHeader;
}

void BMPIMAGE::setColourTable(COLOURTABLE colourTable)
{
    this->m_colourTable = colourTable;
}

void BMPIMAGE::setPixelData(PIXELDATA pixelData)
{
    this->m_pixelData = pixelData;
}

BMPFILEHEADER* BMPIMAGE::getFileHeader()
{
    return &(this->m_fileHeader);
}

BMPINFOHEADER* BMPIMAGE::getInfoHeader()
{
    return &(this->m_infoHeader);
}

COLOURTABLE* BMPIMAGE::getColourTable()
{
    return &(this->m_colourTable);
}

PIXELDATA* BMPIMAGE::getPixelData()
{
    return &(this->m_pixelData);
}