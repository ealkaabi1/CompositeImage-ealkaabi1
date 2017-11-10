// Eisa Alkaabi
// Project 3

#include "bitmap.h"
#include <iostream>
using namespace std;

// read in the files of the bmp images and store them in the vector that
// is passed in to it
void fill_bitmap_vector(vector<Bitmap>& bmps);

//do the logic to make the composite in this function
Bitmap make_composite(Bitmap bmp);

// helper function to check if the filename pass in is a valid bmp file
bool is_good_bmp(string filename);

// helper function to check two bitmap have the same dimension
bool equal_dimensions(Bitmap first, Bitmap second);

int main()
{
  vector<Bitmap> bmps;
  Bitmap composite;
  
  fill_bitmap_vector(bmps);
  //bmps = make_composite(bmps);

  // save the finish product!
  composite.save("composite-ealkaabi1.bmp");

  return 0;
}


void fill_bitmap_vector(vector<Bitmap>& bmps)
{
  string filename;
  int count = 0;

  // read in the filenames
  while (count < 10 && filename != "DONE")
  {
    Bitmap temp;

    cout << "Filename #" << count+1 <<": ";
    getline(cin, filename);

    if (filename != "DONE" && is_good_bmp(filename))
    {
      if (bmps.size() > 0)
      {
        temp.open(filename);

        if (!equal_dimensions(bmps[0], temp))
          cout << "\"" << filename << "\" does not have the same dimensions"
            << " as the first image loaded." << endl;
        else
        {
          count++;
          bmps.push_back(temp);
        }
      }
      else
      {
        count++;
        bmps.push_back(temp);
      }
    }
  }
}

Bitmap make_composite(Bitmap bmp)
{
  Bitmap implement;
  return implement;
}
bool is_good_bmp(string filename)
{
  Bitmap temp;
  temp.open(filename);

  if (!temp.isImage())
    return false;
  
  return true;
}

bool equal_dimensions(Bitmap first, Bitmap second)
{
  PixelMatrix first_matrix = first.toPixelMatrix();
  PixelMatrix second_matrix = second.toPixelMatrix();
        
  if (first_matrix.size() != second_matrix.size())
    return false;
  else
    for (int i = 0; i < first_matrix.size(); i++)
      if (first_matrix[i].size() != second_matrix[i].size())
        return false;

  return true;
}
