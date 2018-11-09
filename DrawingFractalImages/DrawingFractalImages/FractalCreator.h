#pragma once

#include <string>
#include "Zoom.h"
using namespace std;
namespace BitmapContainer
{
	class FractalCreator
	{
	public:
		FractalCreator(int width, int height);

		void CalculateIteration();
		void DrawFractal();
		void AddZoom(const Zoom &zoom);
		void WriteBitmap(string filename);



		virtual ~FractalCreator();
	};

}


