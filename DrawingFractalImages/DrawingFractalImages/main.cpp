#include "stdafx.h"

#include <iostream>
#include <cstdint>
#include <memory>
#include <array>
#include <math.h>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace BitmapContainer;

int main() 
{
	const string BITMAP_IMAGE_NAME = "FractalImage.bmp";


	FractalCreator fractalCreator(800, 600);
	fractalCreator.Run(BITMAP_IMAGE_NAME);
	

	cout << "Finished." << endl;
	return 0;
}

