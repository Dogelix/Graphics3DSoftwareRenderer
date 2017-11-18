#pragma once
#include <windows.h>

class BaseLight
{
public:
	BaseLight();
	BaseLight(BaseLight& rhs);
	~BaseLight();

	void SetRVal(int valIn);
	void SetGVal(int valIn);
	void SetBVal(int valIn);
	int GetRVal();
	int GetGVal();
	int GetBVal();
	COLORREF GetColor();

	BaseLight& Copy(BaseLight& rhs);

private:
	int _valR, _valG, _valB;
};
	

