#include "DirectionalLight.h"

DirectionalLight::DirectionalLight()
{
	SetRVal(255);
	SetGVal(255);
	SetBVal(255);
	_vector = Vector3D(1, 1, 1);
}

DirectionalLight::DirectionalLight(int valR, int valG, int valB, Vector3D vector)
{
	SetRVal(valR);
	SetGVal(valG);
	SetBVal(valB);
	_vector = vector;
}

DirectionalLight::DirectionalLight(DirectionalLight & rhs)
{
	Copy(rhs);
	_vector = rhs.GetVector();
}


DirectionalLight::~DirectionalLight()
{
}

Vector3D DirectionalLight::GetVector()
{
	return _vector;
}

void DirectionalLight::SetVector(Vector3D newVector)
{
	_vector = newVector;
}
