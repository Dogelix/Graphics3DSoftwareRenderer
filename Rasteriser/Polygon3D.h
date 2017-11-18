#pragma once
#include <vector>
#include <windows.h>
#include <algorithm>
#include "DirectionalLight.h"
#include "Vertex.h"
#include "Vector3D.h"

class Polygon3D
{
public:
	Polygon3D();
	Polygon3D(int index0, int index1, int index2);
	~Polygon3D();
	Polygon3D(Polygon3D& p);
	
	// Accessor to return index of specified vertex
	int GetIndex(int _index) const;
	
	Polygon3D& operator= (Polygon3D &rhs);

	void Copy(Polygon3D	&rhs);

	void SetPolygonCull(bool _set);
	bool GetCull();

	void SetNormal(Vector3D normal);
	Vector3D GetNormal();

	void SetAverageZ(std::vector<Vertex>& verts);
	float GetAverageZ();

	void IsBackface(std::vector<Vertex> verts, Vertex camPos);
	void CalculateNormal(std::vector<Vertex> verts);

	void SetColor(int r, int g, int b);
	COLORREF GetColor();
	void ApplyDirectionalLight(std::vector<DirectionalLight>& dLights, float refKA[], float refKD[], float refKS[]);
	float MultiplyReflection(float ka, float kd, float ks, float result);

private:
	int _indices[3];
	float _averageZ;
	bool _cull = false;
	Vector3D _normal;
	COLORREF _color;
};