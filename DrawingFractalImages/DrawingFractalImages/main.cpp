// DrawingFractalImages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#pragma pack(pop)
using namespace std;

using namespace BitmapContainer;

int main()
{
	Bitmap bitmap(2560, 1440);
	bitmap.write("fractal.bmp");

	cout << "Finished" << endl;
    return 0;
}

