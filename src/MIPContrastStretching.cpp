/** \file MIPContrastStretching.cpp
 *
 * Module:    CS3303
 *            Medizinische Bild- und Signalverarbeitung
 *            Medizinische Bildverarbeitung
 *
 * Authors:   Jan Ehrhardt, Alexander Schmidt-Richberg
 *
 * Copyright (c) 2010 Institute of Medical Informatics,
 *            University of Luebeck
 ********************************************************/
#include <iostream>

#include "Image.h"
#include "ImageIO.h"
#include "ContrastStretchingFilter.h"

using namespace std;

int main( int argc, char *argv[] )
{
  std::cout << "==========================" << std::endl;
  std::cout << "   MIPContrastStretching  " << std::endl;
  std::cout << "==========================" << std::endl;

  // Check if program is called correctly.
  if( argc < 3 )
  {
    std::cout << "MIPContrastStretching: MIPContrastStretching called incorrectly!" << std::endl;
    std::cout << "MIPContrastStretching: MIPContrastStretching inimage.mha outimage.mha" << std::endl;
    return -1;
  }

  // Declare an image.
  Image* image = new Image();

  // Read image using ImageIO.
  std::cout << "Reading image " << argv[1] << "..." << std::endl;
  if( !ImageIO::Read( argv[1], image ) )
  {
    std::cout << "Error: Reading image failed!" << std::endl;
    return -1;
  }

  // Execute window level filter.
  std::cout << "Executing ContrastStretchingFilter ..." << std::endl;

  // Create the filter with the given min/max.
  ContrastStretchingFilter* stretchingFilter = new ContrastStretchingFilter();

  // Set the input image.
  stretchingFilter->SetInputImage( image );

  // Execute the filter and check for correct execution.
  if( !stretchingFilter->Execute() )
  {
    std::cout << "Error: Executing the ContrastStretchingFilter failed!" << std::endl;
    return -1;
  }

  // Get the resulting output image.
  Image* outImage = stretchingFilter->GetOutputImage();

  // Write image using ImageIO.
  std::cout << "Writing image " << argv[2] << std::endl;
  if( !ImageIO::Write( argv[2], outImage ) )
  {
    std::cout << "Error: Writing image failed!" << std::endl;
    return -1;
  }

  // Delete image to free space.
  delete stretchingFilter;
  delete image;

  std::cout << "==========================" << std::endl;
  return 0;
}
