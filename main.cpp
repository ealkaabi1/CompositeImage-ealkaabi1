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

int main()
{
  vector<Bitmap> bmps;
  Bitmap composite;
  
  fill_bitmap_vector(bmps);
  bmps = make_composite(bmps);

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
    cout << "Filename #" << count+1 <<": ";
    getline(cin, filename);

    if (filename != "DONE")
    {

      Bitmap temp;
      temp.open(filename);

      if (!temp.isImage());
      else if (bmps.size() > 0)
      {
        PixelMatrix first_matrix = bmps[0].toPixelMatrix();
        PixelMatrix temp_matrix = temp.toPixelMatrix();

        if (temp_matrix.size() != first_matrix.size()
            || temp_matrix[0].size() != first_matrix[0].size())
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
