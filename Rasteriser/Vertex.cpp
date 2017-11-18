#include "Vertex.h"

Vertex::Vertex()
{
	_x = 0.0f;
	_y = 0.0f;
	_z = 0.0f;
	_w = 0.0f;
}

Vertex::Vertex::Vertex(float x, float y, float z, float w)
{
	_x = x;
	_y = y;
	_z = z;
	_w = w;
}

Vertex::Vertex(const Vertex& v)
{
	_x = v.GetX();
	_y = v.GetY();
	_z = v.GetZ();
	_w = v.GetW();
}

Vertex::~Vertex()
{
}

float Vertex::GetX() const
{
	return _x;
}

int Vertex::GetIntX() const
{
	return (int)_x;
}

void Vertex::SetX(const float x)
{
	_x = x;
}

float Vertex::GetY() const
{
	return _y;
}

int Vertex::GetIntY() const
{
	return (int)_y;
}

void Vertex::SetY(const float y)
{
	_y = y;
}

float Vertex::GetZ() const
{
	return _z;
}

int Vertex::GetIntZ() const
{
	return (int)_z;
}

void Vertex::SetZ(const float z)
{
	_z = z;
}

float Vertex::GetW() const
{
	return _w;
}

void Vertex::SetW(const float w)
{
	_w = w;
}

void Vertex::Dehomogenize()
{
	_x = _x / _w;
	_y = _y / _w;
	_z = _z / _w;
	_w = _w / _w;
}

Vertex& Vertex::operator=(const Vertex& rhs)
{
	if (this != &rhs)
	{
		_x = rhs.GetX();
		_y = rhs.GetY();
		_z = rhs.GetZ();
		_w = rhs.GetW();
	}
	return *this;
}

Vector3D  Vertex::operator-(const Vertex & rhs)
{
	return Vector3D(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY(), this->GetZ() - rhs.GetZ());
}

bool Vertex::operator==(const Vertex& rhs) const
{
	return (_x == rhs.GetX() && _y == rhs.GetY() && _z == rhs.GetZ() && _w == rhs.GetW());
}

const Vertex Vertex::operator+(const Vertex& rhs) const
{
	return Vertex(_x + rhs.GetX(), _y + rhs.GetY(), _z + rhs.GetZ(), _w + rhs.GetW());
}
