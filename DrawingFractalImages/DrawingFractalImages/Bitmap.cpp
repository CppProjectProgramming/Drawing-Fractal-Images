#include "stdafx.h"
#include "Bitmap.h"
#include <fstream>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace BitmapContainer;
using namespace std;

namespace BitmapContainer
{

	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {}

	bool Bitmap::write(string filename) 
	{

		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		ofstream file;
		file.open(filename, ios::out | ios::binary);

		if (!file) {
			return false;
		}

		file.write((char *)&fileHeader, sizeof(fileHeader));
		file.write((char *)&infoHeader, sizeof(infoHeader));
		file.write((char *)m_pPixels.get(), m_width*m_height * 3);

		file.close();

		if (!file) {
			return false;
		}

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) 
	{
		uint8_t *pPixle = m_pPixels.get();
		pPixle += (3 * y) *m_width + (x * 3);
		pPixle[0] = blue;
		pPixle[1] = green;
		pPixle[2] = red;
	}

	Bitmap::~Bitmap() 
	{
		// TODO Auto-generated destructor stub
	}

}
