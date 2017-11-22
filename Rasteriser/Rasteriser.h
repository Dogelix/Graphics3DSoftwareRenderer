#pragma once
#include <vector>
#include <math.h>
#include "Camera.h"
#include "MD2Loader.h"
#include "Model.h"
#include "Vertex.h"
#include "Matrix.h"
#include "Framework.h"
#include "DirectionalLight.h"
#include "AmbientLight.h"

#define POLY_SIZE 3
#define WHITE RGB(255, 255, 255)
#define BLUE RGB(0, 0, 255)
#define GREY RGB(100, 100, 100)

class Rasteriser : public Framework
{
public:
	//Vars

	//Methods
	virtual bool Initialise();
	void Update(Bitmap &bitmap);
	void Render(Bitmap &bitmap);
private:
	//Vars
	Camera _cam;
	Model _model;
	Matrix _perspMatrix, _viewMatrix, _transform;
	std::vector<Polygon3D> _lPolys;
	std::vector<Vertex> _lVerts;
	std::vector<DirectionalLight> _dLights;
	std::vector<AmbientLight> _aLights;
	const char* _modelDir = "cube.md2";
	float _rot = 0.01f;

	//Methods
	void GeneratePerspectiveMatrix(float d, float aspectRatio);
	void GenerateViewMatrix(float d, int width, int height);

	//Drawing Methods
	void DrawModel(Bitmap &bMap);
	void DrawPolygon(HDC hdc, Polygon3D poly);
	void DrawSolidPolygonFlat(HDC hdc, Polygon3D poly);
	void Rasteriser::DrawLitPolygon(HDC hdc, Polygon3D poly);
};

