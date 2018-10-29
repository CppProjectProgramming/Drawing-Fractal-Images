#include "stdafx.h"
#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace BitmapContainer;

int main() 
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);
	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 100, 12, 255);


	bitmap.write("IHopeItWorks.bmp");

	cout << "Finished." << endl;
	return 0;
}

