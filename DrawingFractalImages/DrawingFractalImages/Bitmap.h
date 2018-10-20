#pragma once

#include <cstdint>
#include <string>
using namespace std;

namespace BitmapContainer
{
	class Bitmap
	{
	private:
		int m_width{ 0 };
		int m_height{ 0 };
	public:
		Bitmap(int width, int height);

		bool write(string filename);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
		~Bitmap();
	};
}

