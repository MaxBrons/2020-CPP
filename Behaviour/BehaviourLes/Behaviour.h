#pragma once
#include "Vector2d.h"
class Character;

class Behaviour
{
public:
	Behaviour();
	~Behaviour();
	virtual Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = { 0,0 }, Vector2d maxPosition = { 23,23 });
};

