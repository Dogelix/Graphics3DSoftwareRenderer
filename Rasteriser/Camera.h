#pragma once

#include "Matrix.h"

struct Rotation {
	float x, y, z;
};

class Camera
{
public:
	Camera();
	Camera(float xRot, float yRot, float zRot, Vertex& position);
	~Camera();

	Matrix GetCameraMatrix();
	Vertex GetCameraPos();

	void SetRotation(float xRot, float yRot, float zRot);
	void SetPosition(const Vertex& position);

private:
	Matrix _mCam;
	Vertex _pos;
	Rotation _localRot;

	Matrix PosToMatrix(const Vertex& pos);
	Matrix RotToMatrix(float xRot, float yRot, float zRot);
};

