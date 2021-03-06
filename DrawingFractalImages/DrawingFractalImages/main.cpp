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
#include "RGB.h"
using namespace std;
using namespace BitmapContainer;

int main() 
{
	const string BITMAP_IMAGE_NAME = "FractalImage.bmp";


	FractalCreator fractalCreator(800, 600);

	fractalCreator.AddRange(0, RGB(0, 0, 0));
	fractalCreator.AddRange(0.3, RGB(80, 0, 0));
	fractalCreator.AddRange(0.5, RGB(180, 210, 30));
	fractalCreator.AddRange(1, RGB(15, 80, 150));

	fractalCreator.AddZoom(Zoom(295, 202, 0.1));
	fractalCreator.AddZoom(Zoom(312, 304, 0.1));

	fractalCreator.Run(BITMAP_IMAGE_NAME);
	

	cout << "Finished." << endl;
	return 0;
}

