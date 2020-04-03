#pragma once
#include "Behaviour.h"
#include "Vector2d.h"

class ChaseBehaviour :
	public Behaviour
{
public:
	ChaseBehaviour();
	~ChaseBehaviour();
	Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = { 0,0 }, Vector2d maxPosition = {23,23});
};

