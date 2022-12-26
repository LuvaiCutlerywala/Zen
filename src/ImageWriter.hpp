#pragma once

#include "BMPFileContent.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

namespace imageIO
{
    class BMPWRITER
    {

        public:
        BMPWRITER(std::string filename);
        ~BMPWRITER();

        void setFile(std::string filename);
        std::string getFile();

        void writeFileHeader(BMPFILEHEADER* fileHeader);
        void writeInfoHeader(BMPINFOHEADER* infoHeader);
        void writeColourTable(COLOURTABLE* colourTable);
        void writePixelData(PIXELDATA* pixelData);

        private:
        std::string m_filename;
        std::ofstream m_fstream;

    };
}

#endif