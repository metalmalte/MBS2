/** \file ContrastStretchingFilter.cpp
*
* Module:    CS3303
*            Medizinische Bild- und Signalverarbeitung
*            Medizinische Bildverarbeitung
*
* Authors:   Jan Ehrhardt, Alexander Schmidt-Richberg
*
* Student:   TODO Fill in your name(s) here
*
* Matr.-No.: TODO Fill in your matriculation number(s) here
*
* Copyright (c) 2010 Institute of Medical Informatics,
*            University of Luebeck
********************************************************/

#include "ContrastStretchingFilter.h"
#include "climits"

/* Default constructor */
ContrastStretchingFilter::ContrastStretchingFilter() {
}

/* Destructor */
ContrastStretchingFilter::~ContrastStretchingFilter() {
}

/* Execute the window-level filter */
bool ContrastStretchingFilter::Execute() {
    // First, create a valid output image by calling CreateOutputImage()
    // of the base class ImageFilter.
    // The resulting output image has the same size and spacing as the input
    // image and is accessible by the member variable m_OutputImage.

    // This returns false, if no valid input image is available
    // or an other error occurs.
    if (!CreateOutputImage())
        return false;

    /*
     * TODO: Task 5: Compute the contrast-stretched output image.
     *
     * Each gray value in the image will be mapped to a gray value in [0, 255]
     *
     * Use m_InputImage->GetPixel(..) to get the values from the input image.
     * Use m_OutputImage->SetPixel(..) to set the computed values in the output
     * image.
     *
     * Please remember: Arithmetic operations in C++ are type-dependent. You can
     * use the operator static_cast<T>() to convert values to type T!
     */

    // we need to get min and max first. lets implement this

    short min = SHRT_MAX; // our min will be smaller than this
    short max = SHRT_MIN; // our max will be bigger than this

    for (unsigned int y = 0; y < m_InputImage->GetSizeY(); y++) {

        for (unsigned int x = 0; x < m_InputImage->GetSizeX(); x++) {

            Image::PixelType pixel = m_InputImage->GetPixel(x, y);

            // min
            if(pixel < min) {
                min = pixel;
            }

            // max
            if(pixel > max) {
                max = pixel;
            }


        }

    }

    // now we can compute image with contrast stretching

    for (unsigned int y = 0; y < m_InputImage->GetSizeY(); y++) {

        for (unsigned int x = 0; x < m_InputImage->GetSizeX(); x++) {

            Image::PixelType pixel = m_InputImage->GetPixel(x, y);

            // S(g)= 255 * (g - g_min)/(g_max - g_min)
            short value = 255 * (pixel - min) / (max - min);

            m_OutputImage->SetPixel(x, y, value);

        }

    }


    return true;
}
