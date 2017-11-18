#include "BaseLight.h"



BaseLight::BaseLight()
{

}

BaseLight::BaseLight(BaseLight & rhs)
{
	Copy(rhs);
}


BaseLight::~BaseLight()
{
}

void BaseLight::SetRVal(int valIn)
{
	if (valIn < 0) 
	{
		_valR = 0;
	}
	else if(valIn > 255)
	{
		_valR = 255;
	}
	else 
	{
		_valR = valIn;
	}
}

void BaseLight::SetGVal(int valIn)
{
	if (valIn < 0)
	{
		_valG = 0;
	}
	else if (valIn > 255)
	{
		_valG = 255;
	}
	else
	{
		_valG = valIn;
	}
}

void BaseLight::SetBVal(int valIn)
{
	if (valIn < 0)
	{
		_valB = 0;
	}
	else if (valIn > 255)
	{
		_valB = 255;
	}
	else
	{
		_valB = valIn;
	}
}

int BaseLight::GetRVal()
{
	return _valR;
}

int BaseLight::GetGVal()
{
	return _valG;
}

int BaseLight::GetBVal()
{
	return _valB;
}

COLORREF BaseLight::GetColor()
{
	return RGB(_valR, _valG, _valB);
}

BaseLight& BaseLight::Copy(BaseLight& rhs)
{
	if (this != &rhs) 
	{
		_valR = rhs.GetRVal();
		_valG = rhs.GetGVal();
		_valB = rhs.GetBVal();
	}

	return *this;
}
