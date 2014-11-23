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


  return true;
}
