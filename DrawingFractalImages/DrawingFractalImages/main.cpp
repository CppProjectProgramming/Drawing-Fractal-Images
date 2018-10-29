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


	double min = 999999999;
	double max = -99999999;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x< WIDTH; x++)
		{
			double xFractal = (x - WIDTH/2) * 2.0/WIDTH; // Scaling betwen 0 and 1
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			if (xFractal < min) min = xFractal;
			if (xFractal > max) max = xFractal;
		}
	}

	cout << min << ", " << max << endl;

	bitmap.write("IHopeItWorks.bmp");
	cout << "Finished." << endl;
	return 0;
}

