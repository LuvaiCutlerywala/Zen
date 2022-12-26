#pragma once

#include "BMPFileContent.hpp"
#include <vector>

#ifndef BMPIMAGE_H
#define BMPIMAGE_H

namespace images
{
    class BMPIMAGE
    {

        public:
        BMPIMAGE(BMPFILEHEADER fileHeader, 
                BMPINFOHEADER infoHeader, 
                COLOURTABLE colourTable, 
                PIXELDATA pixeldata);

        ~BMPIMAGE();

        //Getters
        void setFileHeader(BMPFILEHEADER fileHeader);
        void setInfoHeader(BMPINFOHEADER infoHeader);
        void setColourTable(COLOURTABLE colourTable);
        void setPixelData(PIXELDATA pixelData);

        //Setters
        BMPFILEHEADER* getFileHeader();
        BMPINFOHEADER* getInfoHeader();
        COLOURTABLE* getColourTable();
        PIXELDATA* getPixelData();

        private:
        BMPFILEHEADER m_fileHeader;
        BMPINFOHEADER m_infoHeader;
        COLOURTABLE m_colourTable;
        PIXELDATA m_pixelData;

    };
}

#endif