#pragma once
#include "BaseLight.h"
class AmbientLight : public BaseLight
{
public:
	AmbientLight();
	AmbientLight(int valR, int valG, int valB);
	AmbientLight(AmbientLight& other);
	~AmbientLight();
};

