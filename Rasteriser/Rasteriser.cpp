#include "Rasteriser.h"

Rasteriser app;



bool Rasteriser::Initialise()
{
	bool success = MD2Loader::LoadModel(_modelDir, _model, &Model::AddPolygon, &Model::AddVertex);
	if (!success)
	{
		return false;
	}
	_cam = Camera(0, 0, 0, Vertex(0.0f, 0.0f, -50.0f, 1.0f));
	_lights.push_back(DirectionalLight(255, 0, 0, Vector3D(1, 0, 1)));
	_lights.push_back(DirectionalLight(0, 255, 0, Vector3D(-1, 0, 1)));
	
	
	return true;
}

void Rasteriser::Update(Bitmap &bitmap)
{
	_rot += 0.1f;
	_transform = Matrix::XYZRotationMatrix(_rot, _rot, _rot);
	GeneratePerspectiveMatrix(1, (float)bitmap.GetWidth() / (float)bitmap.GetHeight());
	GenerateViewMatrix(1, bitmap.GetWidth(), bitmap.GetHeight());
}

void Rasteriser::Render(Bitmap &bitmap)
{
	
	// Clear the window to black
	bitmap.Clear(RGB(0, 0, 0));

	_model.ApplyTransformToLocalVertices(_transform);

	_model.CalculateBackfaces(_cam.GetCameraPos());
	_model.CalculateLightingDirectional(_lights);

	_model.ApplyTransformToTransformedVertices(_cam.GetCameraMatrix());

	_model.Sort();
	_model.ApplyTransformToTransformedVertices(_perspMatrix);
	_model.DehomogeniseTransformedVertices();
	_model.ApplyTransformToTransformedVertices(_viewMatrix);
	DrawModel(bitmap);
}

void Rasteriser::GeneratePerspectiveMatrix(float d, float aspectRatio)
{
	_perspMatrix = { (d / aspectRatio), 0.0f, 0.0f, 0.0f, 0.0f, d, 0.0f, 0.0f, 0.0f, 0.0f, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f };
}

void Rasteriser::GenerateViewMatrix(float d, int width, int height)
{
	_viewMatrix = {(float)(width/2), 0, 0, (float)(width/2), 0, (float)(-height/2), 0, (float)(height/2), 0, 0, (d/2), (d/2), 0, 0, 0, 1};
}

void Rasteriser::DrawModel(Bitmap & bMap)
{
	_lPolys = _model.GetPolygons();
	_lVerts = _model.GetVertices();
	for (int i = 0; i < _model.GetPolygonCount(); i++)
	{
		if (!_lPolys[i].GetCull())
		{
			//DrawSolidPolygonFlat(bMap.GetDC(), _lPolys[i
			DrawLitPolygon(bMap.GetDC(), _lPolys[i]);
			//DrawPolygon(bMap.GetDC(), _lPolys[i]);
		}
	}
}

void Rasteriser::DrawPolygon(HDC hdc, Polygon3D poly)
{
	int _lIndex = 0;
	HPEN hPen = CreatePen(PS_SOLID, 1, WHITE);
	HGDIOBJ oldPen = SelectObject(hdc, hPen);

	for (int i = 0; i < POLY_SIZE; i++)
	{
		_lIndex = poly.GetIndex(i);
		if (i == 0)
		{
			MoveToEx(hdc, _lVerts[_lIndex].GetIntX(), _lVerts[_lIndex].GetIntY(), NULL);
		}
		else
		{	
			LineTo(hdc, _lVerts[_lIndex].GetIntX(), _lVerts[_lIndex].GetIntY());
		}
		if (i == 2)
		{
			LineTo(hdc, _lVerts[poly.GetIndex(0)].GetIntX(), _lVerts[poly.GetIndex(0)].GetIntY());
		}
	}
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void Rasteriser::DrawSolidPolygonFlat(HDC hdc, Polygon3D poly)
{
	POINT pArray[3];
	for (int i = 0; i < POLY_SIZE; i++) 
	{
		pArray[i].x = _lVerts[poly.GetIndex(i)].GetX();
		pArray[i].y = _lVerts[poly.GetIndex(i)].GetY();
	}

	HBRUSH hBrush = CreateSolidBrush(WHITE);
	HGDIOBJ oldBrush = SelectObject(hdc, hBrush);

	Polygon(hdc, pArray, POLY_SIZE);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void Rasteriser::DrawLitPolygon(HDC hdc, Polygon3D poly)
{
	POINT pArray[3];
	for (int i = 0; i < POLY_SIZE; i++)
	{
		pArray[i].x = _lVerts[poly.GetIndex(i)].GetX();
		pArray[i].y = _lVerts[poly.GetIndex(i)].GetY();
	}

	HBRUSH hBrush = CreateSolidBrush(poly.GetColor());
	HGDIOBJ oldBrush = SelectObject(hdc, hBrush);
	HPEN hPen = CreatePen(PS_SOLID, 1, poly.GetColor());
	HGDIOBJ oldPen = SelectObject(hdc, hPen);

	Polygon(hdc, pArray, POLY_SIZE);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}
