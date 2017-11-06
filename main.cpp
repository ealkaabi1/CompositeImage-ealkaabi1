// Eisa Alkaabi
// Project 3

#include "bitmap.h"
#include <iostream>
#include <fstream>
using namespace std;


//not sure if i should put this in a loop or make function
//ask the user for filename and returns a bitmap of the file
// all the file io is done in this function
Bitmap get_file();

//do the logic to make the composite in this function
Bitmap make_composite(Bitmap bmp);

//hmm what else

int main()
{
  // repeat
    // ask user for filename until they enter 10 filenames or the input is 
    // "DONE"
    //
    //
    // if a filename has problems then print them error msg
    //   -print if the file does not exist
    //   -print if the file is not valid bitmap
    //   -print of the file is not the same width and height dimension as
    //    the first image loaded
    //
    // continue with other files but disregard the problem files
    //
    // after all of the files are read in,
    //
    // if the user did not give at least 2 images with width and height
    //   -print error message
    //   -do nothing else
    //
    // else combine the images
    //
    // loop through all of the images by the pixels
    //    -make each pixel average of RGB values of all the pixels
    //    -print progress updates in middle of loop to screen
    //
    // save file as composite-ealkaabi1.bmp
    // exit
  return 0;
}
