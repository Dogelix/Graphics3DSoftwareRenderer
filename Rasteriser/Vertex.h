#pragma once

#include "Vector3D.h"

class Vertex
{
public:
	Vertex();
	Vertex(float x, float y, float z, float w);

	// Copy constructor.  
	Vertex(const Vertex& v);

	// Destructer
	~Vertex();
	
	// Accessors
	float GetX() const;
	int GetIntX() const;
	void SetX(const float x);
	float GetY() const;
	int GetIntY() const;
	void SetY(const float y);
	float GetZ() const;
	int GetIntZ() const;
	void SetZ(const float z);
	float GetW() const;
	void SetW(const float w);

	void Dehomogenize();

	// Assignment operator
	Vertex& operator= (const Vertex& rhs);

	Vector3D operator-(const Vertex& rhs);

	bool operator== (const Vertex& rhs) const;

	const Vertex operator+ (const Vertex& rhs) const;

private:
	float _x, _y, _z, _w;
};

