#pragma once
class Mandelbrot
{
public:
	static const int MAX_ITERATIONS = 1000; // The more iterations we put the more quality we get.

public:
	Mandelbrot();
	~Mandelbrot();

	static int getIterations(double x, double y);
};

