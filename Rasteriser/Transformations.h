#pragma once
#include "Matrix.h"
#include <initializer_list>

class Transformations
{
public:
	Transformations();
	~Transformations();

	/*

	Translation Matrix
	1 0 tx
	0 1 ty
	0 0 1

	Scaling Matrix
	sx 0 0
	0 sy 0
	0 0 sw

	*/

	Matrix Translate(float tx, float ty);
	Matrix Scale(float sx, float sy);
};

