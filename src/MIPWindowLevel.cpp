/** \file MIPWindowLevel.cpp
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
#include "WindowLevelFilter.h"

using namespace std;

//int main( int argc, char *argv[] )
//{
//  std::cout << "==========================" << std::endl;
//  std::cout << "      MIPWindowLevel      " << std::endl;
//  std::cout << "==========================" << std::endl;
//
//  // Check if program is called correctly.
//  if( argc != 5 )
//  {
//    std::cout << "MIPWindowLevel: MIPWindowLevel called incorrectly!" << std::endl;
//    std::cout << "MIPWindowLevel: MIPWindowLevel inimage.mha outimage.mha window level" << std::endl;
//    return -1;
//  }
//
//  // Declare an image.
//  Image* image = new Image();
//
//  // Read image using ImageIO.
//  std::cout << "Reading image " << argv[1] << "..." << std::endl;
//  if( !ImageIO::Read( argv[1], image ) )
//  {
//    std::cout << "Error: Reading image failed!" << std::endl;
//    return -1;
//  }
//
//  // Read the window and level from the command line
//  double window = atof( argv[3] );
//  double level = atof( argv[4] );
//
//  // Execute window level filter.
//  std::cout << "Executing WindowLevelFilter (window=" << window << ", level=" << level << ")..." << std::endl;
//
//  // create the filter with the given window/level
//  WindowLevelFilter* winLevelFilter = new WindowLevelFilter( window, level );
//
//  // set the input image
//  winLevelFilter->SetInputImage( image );
//
//  // Execute the filter and check for correct execution
//  if( !winLevelFilter->Execute() )
//  {
//    std::cout << "Error: Executing the WindowLevelFilter failed!" << std::endl;
//    return -1;
//  }
//
//  // Get the resulting output image
//  Image* outImage = winLevelFilter->GetOutputImage();
//
//  // Write image using ImageIO.
//  std::cout << "Writing image " << argv[2] << std::endl;
//  if( !ImageIO::Write( argv[2], outImage ) )
//  {
//    std::cout << "Error: Writing image failed!" << std::endl;
//    return -1;
//  }
//
//  // Delete images to free space.
//  delete winLevelFilter;
//  delete image;
//
//  std::cout << "==========================" << std::endl;
//  return 0;
//}
