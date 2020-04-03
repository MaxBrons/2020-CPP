#pragma once
#include "Behaviour.h"

class ChaseBehaviour :
	public Behaviour
{
public:
	ChaseBehaviour();
	~ChaseBehaviour();
	Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition, Vector2d maxPosition);
};

