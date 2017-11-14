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

// change the dimensions to conform to the dimension of the bmps
void adjust_dimensions(PixelMatrix& pm, vector<Bitmap> bmps);

int main()
{
  vector<Bitmap> bmps;
  Bitmap composite;
  
  fill_bitmap_vector(bmps);
  
  if (bmps.size() >= 2)
  {
    cout << endl;
    cout << endl;
    composite = make_composite(bmps);
    composite.save("composite-ealkaabi1.bmp");
    cout << endl;
    cout << "Saved the composite image to \"composite-ealkaabi1.bmp\"!"
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
  PixelMatrix composite_matrix;
  int image = 0;

  adjust_dimensions(composite_matrix, bmps);

  while (image < bmps.size())
  {
    PixelMatrix pm = bmps[image].toPixelMatrix();

    for (int i = 0; i < pm.size() ; i++)
    {
      for (int j = 0; j < pm[i].size() ; j++)
      {
        Pixel p
          (
           composite_matrix[i][j].red + pm[i][j].red,
           composite_matrix[i][j].green + pm[i][j].green,
           composite_matrix[i][j].blue + pm[i][j].blue
          );
        composite_matrix[i][j] = p;
      }
    }
    cout << "Image " << image + 1 << "/" << bmps.size() << endl; 
    cout << endl;
    image++;
  }

  for (int i = 0; i < composite_matrix.size(); i++)
  {
    for (int j = 0; j < composite_matrix[i].size(); j++)
    {
    
      Pixel p
        (
         composite_matrix[i][j].red /= bmps.size(),
         composite_matrix[i][j].green /= bmps.size(),
         composite_matrix[i][j].blue /= bmps.size()
         );
      composite_matrix[i][j] = p;
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

void adjust_dimensions(PixelMatrix& pm, vector<Bitmap> bmps)
{
  if (bmps.size() > 0)
  {
    int width, height;
    PixelMatrix bmps_pm = bmps[0].toPixelMatrix();
      
    width = bmps_pm.size();
    height = bmps_pm[0].size();
    
    pm.resize(width);

    for (int i = 0; i < width; i++)
      pm[i].resize(height);
  }
}
