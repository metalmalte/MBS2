/** \file WindowLevelFilter.cpp
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
#include <iostream>
#include "WindowLevelFilter.h"

 /* Default constructor */
WindowLevelFilter::WindowLevelFilter()
{
  m_Window = 1;
  m_Level = 0;
}

/* Constructor for a given  window and level. */
WindowLevelFilter::WindowLevelFilter( const double window, const double level )
{
  m_Window = window;
  m_Level = level;
}

/* Destructor is empty*/
WindowLevelFilter::~WindowLevelFilter()
{
}

bool WindowLevelFilter::Execute()
{
  // First, create a valid output image by calling CreateOutputImage()
  // of the base class ImageFilter.
  // The resulting output image has the same size and spacing as the input
  // image and is accessible by the member variable m_OutputImage.

  // This returns false, if no valid input image is available
  // or an other error occurs.
  if( !CreateOutputImage() )
    return false;

  /*
   * TODO: Task 4: Compute the window/level output value for each input
   *               gray value.
   *
   * Each gray value in the range specified by the window/level will be
   * mapped to a gray value in [0, 255] in the output image. Each gray value
   * below the range will be mapped to 0 and each gray value above to 255.
   *
   * Use m_InputImage->GetPixel(..) to get the values from the input image.
   * Use m_OutputImage->SetPixel(..) to set the computed values in the output
   * image.
   *
   * Please remember: Arithmetic operations in C++ are type-dependent. You can
   * use the operator static_cast<T>() to convert values to type T!
   */

    const double min = m_Level - 0.5 * m_Window;
    const double max = m_Level + 0.5 * m_Window;

    const double c1 = -min;
    const double c2 = static_cast<double> (255/(max - min));

    std::cout << "min: " << min << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    for (unsigned int y = 0; y < m_InputImage->GetSizeY(); y++) {

        for (unsigned int x = 0; x < m_InputImage->GetSizeX(); x++) {

            double const pixelValue = static_cast<double> (m_InputImage->GetPixel(x, y));

            double const result = (pixelValue + c1) * c2;
            Image::PixelType value = 0;

            // zero values
            if(result < 0) {
                // nothing to do here, because value is already 0
            } else if(result > 255) {
                value = 255;
            } else {
                value = static_cast<short> (result);
            }

            m_OutputImage->SetPixel(x, y, value);

        }

    }

  return true;
}
