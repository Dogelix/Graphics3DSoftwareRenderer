#include "AmbientLight.h"

AmbientLight::AmbientLight()
{
	SetRVal(255);
	SetGVal(255);
	SetBVal(255);
}

AmbientLight::AmbientLight(int valR, int valG, int valB)
{
	SetRVal(valR);
	SetGVal(valG);
	SetBVal(valB);
}

AmbientLight::AmbientLight(AmbientLight & other)
{
	Copy(other);
}

AmbientLight::~AmbientLight()
{
}
