#pragma once
#include "Behaviour.h"

class EvadeBehaviour :
	public Behaviour
{
public:
	EvadeBehaviour();
	~EvadeBehaviour();
	Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = {1,1}, Vector2d maxPosition);
};

