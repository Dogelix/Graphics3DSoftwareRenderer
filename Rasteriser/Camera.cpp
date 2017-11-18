#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(float xRot, float yRot, float zRot, Vertex& position)
{
	_pos = position;
	_localRot.x = xRot;
	_localRot.y = yRot;
	_localRot.z = zRot;
	_mCam = RotToMatrix(_localRot.x, _localRot.y, _localRot.z) * PosToMatrix(_pos);
}

Camera::~Camera()
{

}

Matrix Camera::GetCameraMatrix()
{
	return _mCam;
}

Vertex Camera::GetCameraPos()
{
	return _pos;
}

void Camera::SetRotation(float xRot, float yRot, float zRot)
{
	_localRot.x = xRot;
	_localRot.y = yRot;
	_localRot.z = zRot;
	_mCam = RotToMatrix(_localRot.x, _localRot.y, _localRot.z) * PosToMatrix(_pos);
}

void Camera::SetPosition(const Vertex & position)
{
	_pos = position;
	_mCam = RotToMatrix(_localRot.x, _localRot.y, _localRot.z) * PosToMatrix(_pos);
}

Matrix Camera::PosToMatrix(const Vertex & pos)
{
	return {1, 0, 0, -pos.GetX(), 
			0, 1, 0, -pos.GetY(), 
			0, 0, 1, -pos.GetZ(), 
			0, 0, 0, -pos.GetW()};
}

Matrix Camera::RotToMatrix(float xRot, float yRot, float zRot)
{
	Matrix rotMatrix;
	return rotMatrix.XYZRotationMatrix(xRot, yRot, zRot);;
}
