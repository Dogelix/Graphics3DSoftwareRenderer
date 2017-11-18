#include "Polygon3D.h"



Polygon3D::Polygon3D()
{
}

Polygon3D::~Polygon3D()
{
}

Polygon3D::Polygon3D(int index0, int index1, int index2)
{
	_indices[0] = index0;
	_indices[1] = index1;
	_indices[2] = index2;
	_averageZ = 0.0f;
}

Polygon3D::Polygon3D(Polygon3D & p)
{
	Copy(p);
}

int Polygon3D::GetIndex(int _index) const
{
	return _indices[_index];
}

Polygon3D & Polygon3D::operator=(Polygon3D & rhs)
{
	Copy(rhs);
	return *this;
}

void Polygon3D::Copy(Polygon3D & rhs)
{
	if (this != &rhs)
	{
		_indices[0] = rhs.GetIndex(0);
		_indices[1] = rhs.GetIndex(1);
		_indices[2] = rhs.GetIndex(2);
		_cull = rhs._cull;
		_averageZ = rhs._averageZ;
		_normal = rhs._normal;
		_color = rhs.GetColor();
	}
}

void Polygon3D::SetPolygonCull(bool _set)
{
	_cull = _set;
}

bool Polygon3D::GetCull() 
{
	return _cull;
}

void Polygon3D::SetNormal(Vector3D normal)
{
	_normal = normal;
}

Vector3D Polygon3D::GetNormal()
{
	return _normal;
}

void Polygon3D::SetAverageZ(std::vector<Vertex> & verts)
{
	_averageZ = (verts[_indices[0]].GetZ() + verts[_indices[1]].GetZ() + verts[_indices[2]].GetZ()) / 3;
}

float Polygon3D::GetAverageZ()
{
	return _averageZ;
}

void Polygon3D::IsBackface(std::vector<Vertex> verts, Vertex camPos)
{
	CalculateNormal(verts);

	Vector3D eyeVector = verts[_indices[0]] - camPos;

	float result = Vector3D::DotProduct(eyeVector, _normal);

	_cull = result < 0;
}

void Polygon3D::CalculateNormal(std::vector<Vertex> verts)
{
	Vector3D a = verts[_indices[1]] - verts[_indices[0]];
	Vector3D b = verts[_indices[2]] - verts[_indices[0]];
	_normal = Vector3D::CrossProduct(b, a);
	_normal.Normalise();
}

void Polygon3D::SetColor(int r, int g, int b)
{
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}

	_color = RGB(r, g, b);
}

COLORREF Polygon3D::GetColor()
{
	return _color;
}

void Polygon3D::ApplyDirectionalLight(std::vector<DirectionalLight> & dLights, float refKA[], float refKD[], float refKS[])
{
	float totalR = 0, totalG = 0, totalB = 0, tempR, tempG, tempB;
	float dotVectors;
	SetColor(0, 0, 0); //Reset to Black
	
	for(int i = 0; i < dLights.size(); i++)
	{
		tempR = dLights[i].GetRVal();
		tempG = dLights[i].GetGVal();
		tempB = dLights[i].GetBVal();
		tempR = MultiplyReflection(refKA[0], refKD[0], refKS[0], tempR);
		tempG = MultiplyReflection(refKA[1], refKD[1], refKS[1], tempG);
		tempB = MultiplyReflection(refKA[2], refKD[2], refKS[2], tempB);

		dotVectors = Vector3D::DotProduct(_normal, dLights[i].GetVector());

		tempR *= dotVectors;
		tempG *= dotVectors;
		tempB *= dotVectors;
		totalR += tempR;
		totalG += tempG;
		totalB += tempB;
	}
	SetColor(totalR, totalG, totalB);
}

float Polygon3D::MultiplyReflection(float ka, float kd, float ks, float result)
{
	result *= ka;
	result *= kd;
	result *= ks;
	return result;
}
