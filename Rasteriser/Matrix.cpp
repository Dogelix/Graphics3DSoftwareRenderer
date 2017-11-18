#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < _mSize; i++)
	{
		for (int j = 0; j < _mSize; j++)
		{
			_matrix[i][j] = 0.0f;
		}
	}
}

Matrix::Matrix(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < _mSize; i++)
		{
			for(int j = 0; j < _mSize; j++)
			{
				_matrix[i][j] = rhs.GetM(i, j);
			}
		}
	}
}

Matrix::Matrix(std::initializer_list<float> list)
{
	if (list.size() !=  16)
	{
		throw "Insufficient values supplied";
	}
	auto iterator = list.begin();
	for (int i = 0; i < _mSize; i++)
	{
		for(int j = 0; j < _mSize; j++)
		{
			_matrix[i][j] = *iterator++;
		}
	}
}

Matrix::~Matrix()
{
}

float Matrix::GetM(const int row, const int column) const
{
	return _matrix[row][column];;
}

void Matrix::SetM(const int row, const int column, const float value)
{
	_matrix[row][column] = value;
}

//Copy operator
Matrix & Matrix::operator=(const Matrix & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < _mSize; i++)
		{
			for (int j = 0; j < _mSize; j++)
			{
				_matrix[i][j] = rhs.GetM(i, j);
			}
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix & rhs) 
{	
	Matrix newMatrix;
	float _value = 0.0f;
	
	for(int i = 0; i < _mSize; i++)
	{
		for (int j = 0; j < _mSize; j++)
		{
			for (int k = 0; k < _mSize; k++) 
			{
				_value += _matrix[i][k] * rhs.GetM(k, j);
			}
			newMatrix.SetM(i, j, _value);
			_value = 0.0f;
		}
	}
	return newMatrix;
}

Vertex Matrix::operator*(const Vertex &rhs) 
{
	_vTemp.SetX(0);
	_vTemp.SetY(0);
	_vTemp.SetZ(0);
	_vTemp.SetW(1);
	Vertex _rhs = rhs;

	_vTemp.SetX(GetM(0, 0) * _rhs.GetX() + GetM(0, 1) * _rhs.GetY() + GetM(0, 2) * _rhs.GetZ() + GetM(0, 3) * _rhs.GetW());
	_vTemp.SetY(GetM(1, 0) * _rhs.GetX() + GetM(1, 1) * _rhs.GetY() + GetM(1, 2) * _rhs.GetZ() + GetM(1, 3) * _rhs.GetW());
	_vTemp.SetZ(GetM(2, 0) * _rhs.GetX() + GetM(2, 1) * _rhs.GetY() + GetM(2, 2) * _rhs.GetZ() + GetM(2, 3) * _rhs.GetW());
	_vTemp.SetW(GetM(3, 0) * _rhs.GetX() + GetM(3, 1) * _rhs.GetY() + GetM(3, 2) * _rhs.GetZ() + GetM(3, 3) * _rhs.GetW());
	return _vTemp;
}


Matrix Matrix::TranslationMatrix(float x, float y, float z)
{
	return {1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1};
}

Matrix Matrix::ScalingMatrix(float x, float y, float z)
{
	return{ x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1 };
}

Matrix Matrix::XRotationMatrix(float angle)
{
	return{ 1, 0, 0, 0, 0, (float)cos(angle), (float)-sin(angle), 0, 0, (float)sin(angle), (float)cos(angle), 0, 0, 0, 0, 1 };
}

Matrix Matrix::YRotationMatrix(float angle)
{
	return{ (float)cos(angle), 0, (float)sin(angle), 0, 0, 1, 0, 0, (float)-sin(angle), 0, (float)cos(angle), 0, 0, 0, 0, 1 };
}

Matrix Matrix::ZRotationMatrix(float angle)
{
	return{ (float)cos(angle), (float)-sin(angle), 0, 0, (float)sin(angle), (float)cos(angle), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
}

Matrix Matrix::XYZRotationMatrix(float angleX, float angleY, float angleZ)
{
	return XRotationMatrix(angleX) * YRotationMatrix(angleY) * ZRotationMatrix(angleZ);
}