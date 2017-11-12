// Eisa Alkaabi
// Project 3

#include "bitmap.h"
#include <iostream>
using namespace std;

// read in the files of the bmp images and store them in the vector that
// is passed in to it
void fill_bitmap_vector(vector<Bitmap>& bmps);

//do the logic to make the composite in this function
Bitmap make_composite(vector<Bitmap> bmps);

// helper function to check if the filename pass in is a valid bmp file
bool is_good_bmp(string filename);

// helper function to check two bitmap have the same dimension
bool equal_dimensions(Bitmap first, Bitmap second);

int main()
{
  vector<Bitmap> bmps;
  Bitmap composite;
  
  fill_bitmap_vector(bmps);
  
  if (bmps.size() >= 2)
  {
    composite = make_composite(bmps);
    composite.save("composite-ealkaabi1.bmp");
    cout << endl;
    cout << "Saved the composite image to \"composite-ealkaabi1.bmp\"."
      << endl;
  }
  else
  {
    cout << endl;
    cout << "You did not enter at least two bitmap images with same "
     << "dimension." << endl;
  }

  return 0;
}

void fill_bitmap_vector(vector<Bitmap>& bmps)
{
  string filename;
  int count = 0;

  // read in the filenames
  while (count < 10 && filename != "DONE")
  {
    cout << bmps.size() << endl;

    Bitmap temp;

    cout << "Filename #" << count+1 <<": ";
    getline(cin, filename);

    if (filename != "DONE" && is_good_bmp(filename))
    {
      temp.open(filename);
      
      if (bmps.size() > 0)
      {

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

Bitmap make_composite(vector<Bitmap> bmps)
{
  Bitmap composite;
  PixelMatrix composite_matrix(bmps.size());
  PixelMatrix bmps_matrix[bmps.size()];

  // iterate the images and get the pixel matrices
  for (int i = 0; i < bmps.size(); i++)
    bmps_matrix[i] = bmps[i].toPixelMatrix();

  cout << endl;

  // iterate the pixel matrices
  for (int i = 0; i < bmps.size(); i++)
  {
    composite_matrix[i].resize(bmps_matrix[i].size());

    for (int j = 0; j < bmps_matrix[i].size(); j++)
    {
      for (int k = 0; k < bmps_matrix[i][j].size(); k++)
      {
        composite_matrix[i][j].red += bmps_matrix[i][j][k].red;
        composite_matrix[i][j].green += bmps_matrix[i][j][k].green;
        composite_matrix[i][j].blue += bmps_matrix[i][j][k].blue;
      }
    }
    cout << "Image " << i + 1 << " of " << bmps.size() << " done." << endl;
  }

  for (int i = 0; i < composite_matrix.size(); i++)
  {
    for (int j = 0; j < composite_matrix[i].size(); j++)
    {
      composite_matrix[i][j].red /= bmps.size();
      composite_matrix[i][j].green /= bmps.size();
      composite_matrix[i][j].blue /= bmps.size();
    }
  }

  composite.fromPixelMatrix(composite_matrix);

  return composite;
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
