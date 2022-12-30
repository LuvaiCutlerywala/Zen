#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "BMPFileContent.hpp"

#ifndef IMAGEREADER_H
#define IMAGEREADER_H

/**
 * @brief Contains all classes that contain the methods for reading and writing images, be it Bitmap or JPEG.
*/
namespace imageIO
{
    /**
     * @brief A util class providing methods to read a BMP file. All the logic pertaining to the reading BMP files, such as
     *        the ordering of the headers, or the subpixel storage should be contained here.
    */
    class BMPREADER
    {

        public:
        /**
         * @brief Constructor for the class.
         * @param filename The filename of the file to be read.
        */
        BMPREADER(std::string filename);
        ~BMPREADER();

        /**
         * @brief Sets the file name.
         * @param filename The filename to be set.
        */
        void setFile(std::string filename);

        /**
         * @brief Returns the filename of the file to be read from.
         * @returns The filename of the file to be read from.
        */
        std::string getFile();

        /**
         * @brief Reads the file header in a Bitmap file. Reads from byte 1 to byte 14.
         * @param fileHeader The file header.
        */
        void readFileHeader(BMPFILEHEADER* fileHeader);

        /**
         * @brief Reads the information header in a Bitmap file. Reads from byte 15 to byte 54. 
         * @param infoHeader The information header.
        */
        void readInfoHeader(BMPINFOHEADER* infoHeader);

        /**
         * @brief Reads the colour table in a Bitmap file. Reads from byte 55 to byte 59.
         * @param colourTable The colour table.
        */
        void readColourTable(COLOURTABLE* colourTable);

        /**
         * @brief Reads the pixel data from a Bitmap file. Reads from byte 60 to the end of file.
         *        The pixel data is arranged backwards, meaning that the pixels that are near to the top of the image are
         *        near the end of the file. This is an implementation detail that is only concerning the viewing
         *        application, as it does not actually make a difference whether the image is forwards or backwards when
         *        committing operations. Another detail is that the image is read as the raw bytes, meaning that there is no
         *        structure that represents the actual pixel. That is why, currently, a PIXELARRAY unit is used to
         *        encapsulate the three bytes forming the actual pixel. This may be changed in the future, depending if
         *        support for images with differing bit counts is added or not, but currently, it is simply an unnecessary
         *        implementation detail that need not be considered as of yet.
         * @param pixelData The container for the pixel data.
         * @param imageSize The number of pixels to be read.
        */
        void readPixelData(PIXELDATA* pixelData, uint32_t imageSize);

        private:
        std::string m_filename;
        std::ifstream m_fstream;

    };
}

#endif