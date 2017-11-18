#pragma once
#include <math.h>

class Vector3D
{
	public:
		Vector3D();
		~Vector3D();
		Vector3D(Vector3D& v);
		Vector3D(float x, float y, float z);

		Vector3D& operator+(Vector3D& rhs);
		Vector3D& operator=(Vector3D& rhs);

		static float DotProduct(Vector3D& v1, Vector3D& v2);
		static Vector3D CrossProduct(Vector3D& v1, Vector3D& v2);

		void Normalise();

		Vector3D& Copy(Vector3D& rhs);

		float CalculateLength();

		float GetX();
		float GetY();
		float GetZ();
		float GetLength();
		
	private:
		float _x, _y, _z, _length;
};