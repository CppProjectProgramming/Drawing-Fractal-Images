#include "stdafx.h"
#include "FractalCreator.h"
#include "RGB.h"
using namespace BitmapContainer;

FractalCreator::FractalCreator(int width, int height)
	: m_width(width), m_height(height), m_zoomList(m_width, m_height),
	m_bitmap(m_width, m_height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{}),
	m_fractal(new int[m_width * m_height]{})
{
	AddZoom(Zoom(m_width / 2, m_height / 2, 2.0 / m_width));
}


void BitmapContainer::FractalCreator::Run(string fileName)
{
	// Do not change the execution order coz it will miss up everything 
	CalculateIteration();
	CalculateTotalIterations();
	DrawFractal();
	WriteBitmap(fileName);
}


void BitmapContainer::FractalCreator::AddRange(double rangeEnd, const RGB &rgb)
{
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);
}


void BitmapContainer::FractalCreator::AddZoom(const Zoom &zoom)
{
	m_zoomList.add(zoom);
}


void BitmapContainer::FractalCreator::CalculateIteration()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				m_histogram[iterations]++;
			}
		}
	}
}

void BitmapContainer::FractalCreator::CalculateTotalIterations()
{

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total += m_histogram[i];
	}
}

void BitmapContainer::FractalCreator::DrawFractal()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			RGB startColor(35, 18, 100);
			RGB endColor(220, 140, 160);
			RGB colorDiff = endColor - startColor;

			int iterations = m_fractal[y * m_width + x];

			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++)
				{
					hue += ((double)m_histogram[i]) / m_total;
				}
				red = startColor.r + colorDiff.r * hue;
				green = startColor.g + colorDiff.g * hue;
				blue = startColor.b + colorDiff.b * hue;
			}
			// changing the color  by the amout proportional by how many pixels ! 
			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}


void BitmapContainer::FractalCreator::WriteBitmap(const string filename)
{
	m_bitmap.write(filename);
}


FractalCreator::~FractalCreator()
{
}
