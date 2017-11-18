#pragma once
#include "Vertex.h"
#include <math.h>
#include <initializer_list>

class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& rhs);
	Matrix(std::initializer_list<float> list);
	~Matrix();

	float GetM(const int row, const int column) const;
	void SetM(const int row, const int column, const float value);

	Matrix& operator= (const Matrix &rhs);
	Matrix operator*(const Matrix &rhs);
	Vertex operator*(const Vertex &rhs);

	static Matrix TranslationMatrix(float x, float y, float z);
	static Matrix ScalingMatrix(float x, float y, float z);
	static Matrix XRotationMatrix(float angle);
	static Matrix YRotationMatrix(float angle);
	static Matrix ZRotationMatrix(float angle);
	static Matrix XYZRotationMatrix(float angleX, float angleY, float angleZ);

private:
	int _mSize = 4;
	float _matrix[4][4];

	Vertex _vTemp;
};

