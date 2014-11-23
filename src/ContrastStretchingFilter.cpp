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

/* Default constructor */
ContrastStretchingFilter::ContrastStretchingFilter()
{
}

/* Destructor */
ContrastStretchingFilter::~ContrastStretchingFilter()
{
}

/* Execute the window-level filter */
bool ContrastStretchingFilter::Execute()
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

  return true;
}
