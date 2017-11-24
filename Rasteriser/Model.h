#pragma once

#include <vector>
#include "Polygon3D.h"
#include "Vector3D.h"
#include "Vertex.h"
#include "Matrix.h"
#include "DirectionalLight.h"
#include "AmbientLight.h"

class Model
{
public:
	Model();
	~Model();
	// Accessors
	std::vector<Polygon3D>& GetPolygons();
	std::vector<Vertex>& GetVertices();
	size_t GetPolygonCount() const;
	size_t GetVertexCount() const;
	void AddVertex(float x, float y, float z);
	void AddPolygon(int i0, int i1, int i2);
	void ApplyTransformToLocalVertices(/*const*/ Matrix &transform); 
	void ApplyTransformToTransformedVertices(/*const*/ Matrix &transform);
	void DehomogeniseTransformedVertices();

	void CalculateBackfaces(const Vertex& cam);
	void Sort();

	void CalculateLighting(std::vector<DirectionalLight>& dList, AmbientLight & aLight);

	//0 = R, 1 = G, 2 = B
	void SetKAValues(int index, float value);
	void SetKDValues(int index, float value);
	void SetKSValues(int index, float value);
	float GetKAValues(int index);
	float GetKDValues(int index);
	float GetKSValues(int index);
private:
	std::vector<Polygon3D> _polygons;
	std::vector<Vertex> _verticesLocal, _verticesTransformed;
	float refKA[3], refKD[3], refKS[3];

	void CalculateAmbientLighting(AmbientLight & aLight);
	void CalculateLightingDirectional(std::vector<DirectionalLight>& dList);
};