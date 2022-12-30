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
    /**
     * @brief A util class providing methods to write to a new BMP file. All the logic specific to the serialisation of the
     *        BMP file, such as ordering of the headers, or the subpixel ordering should all be contained in this class.
    */
    class BMPWRITER
    {

        public:
        /**
         * @brief Constructor for the class.
         * @param filename Name of file to write to.
        */
        BMPWRITER(std::string filename);
        ~BMPWRITER();

        /**
         * @brief Sets the filename for the file to be written to.
         * @param filename The filename of the image file to be written to.
        */
        void setFile(std::string filename);
        
        /**
         * @brief Returns the filename of the image file being written to.
         * @returns The filename of the image file to be written to.
        */
        std::string getFile();

        /**
         * @brief Writes the BMP file header, starting from byte 1 to byte 15.
         * @param fileHeader The BMP file header.
        */
        void writeFileHeader(BMPFILEHEADER* fileHeader);

        /**
         * @brief Writes the BMP information header, starting from byte 16 through to byte 55.
         * @param infoHeader The BMP information header.
        */
        void writeInfoHeader(BMPINFOHEADER* infoHeader);

        /**
         * @brief Writes the BMP colour table, starting from byte 56 through to byte 59.
         * @param colourTable The BMP colour table.
        */
        void writeColourTable(COLOURTABLE* colourTable);

        /**
         * @brief Writes the BMP image data, starting from byte 59 to the end of the file.
         * @param pixelData The BMP image data.
        */
        void writePixelData(PIXELDATA* pixelData);

        private:
        std::string m_filename;
        std::ofstream m_fstream;

    };
}

#endif