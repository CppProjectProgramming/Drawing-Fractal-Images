#pragma once

#include <string>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;
namespace BitmapContainer
{
	class FractalCreator
	{
	private:
		const int m_width = 800;
		const int m_height = 600;
		ZoomList m_zoomList;
		Bitmap m_bitmap;
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
		int m_total = 0;
		
	private:
		void CalculateIteration();
		void CalculateTotalIterations();
		void DrawFractal();
		void WriteBitmap(string filename);

	public:
		FractalCreator(int width, int height);

		void Run(string fileName);
		void AddZoom(const Zoom &zoom);

		virtual ~FractalCreator();
	};

}


