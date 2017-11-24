#pragma once
#include "Vector3D.h"

Vector3D::Vector3D()
{
	_x = 0.0f;
	_y = 0.0f;
	_z = 0.0f;
	_length = 0.0f;
}

Vector3D::~Vector3D()
{
	
}

Vector3D::Vector3D(Vector3D & v)
{
	this->Copy(v);
}

Vector3D::Vector3D(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3D & Vector3D::operator+(Vector3D & rhs)
{
	return Vector3D(this->_x + rhs.GetX(), this->_y + rhs.GetY(), this->_z + rhs.GetZ());
}

Vector3D & Vector3D::operator=(Vector3D & rhs)
{
	return Copy(rhs);
}

float Vector3D::DotProduct(Vector3D & v1, Vector3D & v2)
{
	return  v1.GetX() * v2.GetX() + v1.GetY() * v2.GetY() + v1.GetZ() * v2.GetZ();
}

Vector3D Vector3D::CrossProduct(Vector3D & v1, Vector3D & v2)
{
	return Vector3D(v1.GetY() * v2.GetZ() - v1.GetZ() * v2.GetY(),
					v1.GetZ() * v2.GetX() - v1.GetX() * v2.GetZ(),
					v1.GetX() * v2.GetY() - v1.GetY() * v2.GetX());
}

void Vector3D::Normalise()
{
	if (_length == NAN) 
	{
		_x /= CalculateLength();
		_y /= CalculateLength();
		_z /= CalculateLength();
	}
	else 
	{
		_x /= CalculateLength();
		_y /= CalculateLength();
		_z /= CalculateLength();;
	}
	
}

//Copy method
Vector3D & Vector3D::Copy(Vector3D & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;//GetX();
		_y = rhs._y;//GetY();
		_z = rhs._z;//GetZ();
		_length = rhs._length;//GetLength();
	}
	return *this;
}

float Vector3D::CalculateLength()
{
	return (float) sqrt( (_x * _x) + (_y * _y) + (_z * _z) );
}

float Vector3D::GetX()
{
	return _x;
}

float Vector3D::GetY()
{
	return _y;
}

float Vector3D::GetZ()
{
	return _z;
}

float Vector3D::GetLength()
{
	if (_length == NAN)
	{
		_length = CalculateLength();
	}
	return _length;
}
