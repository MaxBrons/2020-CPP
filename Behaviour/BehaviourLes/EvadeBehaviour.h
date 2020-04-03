#pragma once
#include "Behaviour.h"
#include "Vector2d.h"

class EvadeBehaviour :
	public Behaviour
{
public:
	EvadeBehaviour();
	~EvadeBehaviour();
	Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = { 0,0 }, Vector2d maxPosition = {23,23}, float gap = 1);
};

