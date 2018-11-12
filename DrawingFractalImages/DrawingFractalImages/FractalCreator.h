#pragma once

#include <string>
#include <vector>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

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

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange = false;
		
	private:
		void CalculateIteration();
		void CalculateTotalIterations();
		void CalculateRangeTotals();
		void DrawFractal();
		void WriteBitmap(string filename);

	public:
		FractalCreator(int width, int height);

		void Run(string fileName);
		void AddRange(double rangeEnd, const RGB &rgb);
		void AddZoom(const Zoom &zoom);

		virtual ~FractalCreator();
	};

}


