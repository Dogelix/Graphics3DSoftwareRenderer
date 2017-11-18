#pragma once
#include "BaseLight.h"
#include "Vector3D.h"

class DirectionalLight : public BaseLight
{
public:
	DirectionalLight();
	DirectionalLight(int valR, int valG, int valB, Vector3D vector);
	DirectionalLight(DirectionalLight& rhs);
	~DirectionalLight();

	Vector3D GetVector();
	void SetVector(Vector3D newVector);
private:
	Vector3D _vector;
};

