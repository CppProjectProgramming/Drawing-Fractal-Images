#include "stdafx.h"

#include <iostream>
#include <cstdint>
#include <memory>
#include <array>

#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace BitmapContainer;

int main() 
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);


	double min = 999999999;
	double max = -99999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{});

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x< WIDTH; x++)
		{
			double xFractal = (x - WIDTH/2 - 200) * 2.0/ HEIGHT; // Scaling betwen 0 and 1
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
			histogram[iterations]++;

			color = color * color * color;

			bitmap.setPixel(x, y, 0, color, 0);

			if (color < min) min = color;
			if (color > max) max = color;
		}
	}

	int count = 0;
	for (int i = 0; i <= 1000; i++)
	{
		cout << histogram[i] << endl;
		count += histogram[i];
	}

	cout << count << " : " << WIDTH * HEIGHT << endl;

	cout << min << ", " << max << endl;

	bitmap.write("IHopeItWorks.bmp");
	cout << "Finished." << endl;
	return 0;
}

