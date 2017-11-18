#include "Model.h"
#include <algorithm>

Model::Model()
{
	for (int i = 0; i < 3; i++) 
	{
		SetKAValues(i, 0.5f);
		SetKDValues(i, 0.5f);
		SetKSValues(i, 0.5f);
	}
}

Model::~Model()
{
}

std::vector<Polygon3D>& Model::GetPolygons()
{
	return _polygons;
}

std::vector<Vertex>& Model::GetVertices()
{
	return _verticesTransformed;
}

size_t Model::GetPolygonCount() const
{
	return size_t(_polygons.size());
}

size_t Model::GetVertexCount() const
{
	return size_t(_verticesLocal.size());
}

void Model::AddVertex(float x, float y, float z)
{
	_verticesLocal.push_back(Vertex(x, y, z, 1));
}

void Model::AddPolygon(int i0, int i1, int i2)
{
	_polygons.push_back(Polygon3D(i0, i1, i2));
}

void Model::ApplyTransformToLocalVertices(Matrix & transform)
{
	_verticesTransformed.clear();
	for (int i = 0; i < GetVertexCount(); i++)
	{
		_verticesTransformed.push_back(transform * _verticesLocal[i]);
	}
}

void Model::ApplyTransformToTransformedVertices(Matrix & transform)
{
	for (int i = 0; i < GetVertexCount(); i++)
	{
		_verticesTransformed[i] = transform * _verticesTransformed[i];
	}
}

void Model::DehomogeniseTransformedVertices()
{
	for (int i = 0; i < GetVertexCount(); i++)
	{
		_verticesTransformed[i].Dehomogenize();
	}
}

void Model::CalculateBackfaces(const Vertex& cam)
{
	for (int i = 0; i < GetPolygonCount(); i++)
	{
		_polygons[i].IsBackface(_verticesTransformed, cam);
	}
}

void Model::Sort()
{
	for (int i = 0; i < GetPolygonCount(); i++) 
	{
		_polygons[i].SetAverageZ(_verticesTransformed);
	}

	std::sort(_polygons.begin(), _polygons.end(), [](Polygon3D p1, Polygon3D p2) {return p1.GetAverageZ() > p2.GetAverageZ(); });
}

void Model::CalculateLightingDirectional(std::vector<DirectionalLight> & dList)
{
	for (int i = 0; i < GetPolygonCount(); i++)
	{
		_polygons[i].ApplyDirectionalLight(dList, refKA, refKD, refKS);
	}
}

void Model::SetKAValues(int index, float value)
{
	refKA[index] = value;
}

void Model::SetKDValues(int index, float value)
{
	refKD[index] = value;
}

void Model::SetKSValues(int index, float value)
{
	refKS[index] = value;
}

float Model::GetKAValues(int index)
{
	return refKA[index];
}

float Model::GetKDValues(int index)
{
	return refKD[index];
}

float Model::GetKSValues(int index)
{
	return refKS[index];
}

