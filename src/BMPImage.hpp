#pragma once

#include "BMPFileContent.hpp"
#include <vector>

#ifndef BMPIMAGE_H
#define BMPIMAGE_H

/**
 * @brief A container for the classes representing all the different image types, such as Bitmap or JPEG.
*/
namespace images
{   
    /**
     * @brief A container class representing a Bitmap or BMP image. It should be used to encapsulate all the specifics of
     *        the BMP file format, decoupling and exposing only the image data, which the operation should be completed on.
    */
    class BMPIMAGE
    {

        public:
        /**
         * @brief Constructor for the BMPIMAGE class.
         * @param fileHeader Struct for the BMP file header.
         * @param infoHeader Struct for the BMP information header.
         * @param colourTable Struct for the BMP colour table.
         * @param pixelData Struct for the BMP image data.
        */
        BMPIMAGE(BMPFILEHEADER fileHeader, 
                BMPINFOHEADER infoHeader, 
                COLOURTABLE colourTable, 
                PIXELDATA pixeldata);

        ~BMPIMAGE();

        /**
         * @brief Sets the file header.
         * @param fileHeader The file header.
        */
        void setFileHeader(BMPFILEHEADER fileHeader);

        /**
         * @brief Sets the information header.
         * @param infoHeader The information header.
        */
        void setInfoHeader(BMPINFOHEADER infoHeader);

        /**
         * @brief Sets the colour table.
         * @param colourTable The colour table.
        */
        void setColourTable(COLOURTABLE colourTable);

        /**
         * @brief Sets the image data.
         * @param pixelData The image data.
        */
        void setPixelData(PIXELDATA pixelData);

        /**
         * @brief Returns the file header.
         * @returns The file header.
        */
        BMPFILEHEADER* getFileHeader();

        /**
         * @brief Returns the information header.
         * @returns The information header.
        */
        BMPINFOHEADER* getInfoHeader();

        /**
         * @brief Returns the colour table.
         * @returns The colour table.
        */
        COLOURTABLE* getColourTable();

        /**
         * @brief Returns the image data.
         * @returns The image data.
        */
        PIXELDATA* getPixelData();

        private:
        BMPFILEHEADER m_fileHeader;
        BMPINFOHEADER m_infoHeader;
        COLOURTABLE m_colourTable;
        PIXELDATA m_pixelData;

    };
}

#endif