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
	int height = 600;

	FractalCreator fractalCreator(800, 600);

	// Order Matters...
	fractalCreator.CalculateIteration();
	fractalCreator.CalculateTotalIterations();
	fractalCreator.DrawFractal();
	fractalCreator.WriteBitmap(BITMAP_IMAGE_NAME);
	
	cout << "Finished." << endl;
	return 0;
}

