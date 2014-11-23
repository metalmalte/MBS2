/** \file MIPShiftScale.cpp
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
#include "ShiftScaleFilter.h"

using namespace std;

//int main( int argc, char *argv[] )
//{
//  std::cout << "==========================" << std::endl;
//  std::cout << "     MIPShiftScale  " << std::endl;
//  std::cout << "==========================" << std::endl;
//
//  // Check if program is called correctly.
//  if( argc != 5 )
//  {
//    std::cout << "MIPShiftScale: MIPShiftScale called incorrectly!" << std::endl;
//    std::cout << "MIPShiftScale: MIPShiftScale inimage.mha outimage.mha <shift> <scale>" << std::endl;
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
//  // Get the shift and scale values given by command line.
//  double shift = atof( argv[3] );
//  double scale = atof( argv[4] );
//
//  // Execute the filter with given shift and scale.
//  std::cout << "Executing ShiftScaleFilter(shift = " << shift << " and scale = " << scale << ")..." << std::endl;
//
//  // Construct the filter object.
//  ShiftScaleFilter* scaleFilter = new ShiftScaleFilter( shift, scale );
//
//  // Set the input image.
//  scaleFilter->SetInputImage( image );
//
//  // Execute the filter and check for correct execution.
//  if( !scaleFilter->Execute() )
//  {
//    std::cout << "Error: Executing the ShiftScaleFilter failed!" << std::endl;
//    return -1;
//  }
//
//  // Get the resulting output image.
//  Image* outImage = scaleFilter->GetOutputImage();
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
//  delete scaleFilter;
//  delete image;
//
//  std::cout << "==========================" << std::endl;
//  return 0;
//}
