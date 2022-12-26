#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "BMPFileContent.hpp"

#ifndef IMAGEREADER_H
#define IMAGEREADER_H

namespace imageIO
{
    class BMPREADER
    {

        public:
        BMPREADER(std::string filename);
        ~BMPREADER();

        void setFile(std::string filename);
        std::string getFile();

        void readFileHeader(BMPFILEHEADER* fileHeader);
        void readInfoHeader(BMPINFOHEADER* infoHeader);
        void readColourTable(COLOURTABLE* colourTable);
        void readPixelData(PIXELDATA* pixelData, uint32_t imageSize);

        private:
        std::string m_filename;
        std::ifstream m_fstream;

    };
}

#endif