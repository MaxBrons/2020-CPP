#include "ChaseBehaviour.h"


ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

Vector2d ChaseBehaviour::Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition, Vector2d maxPosition)
{
	if (ownPosition.GetX() < targetPosition.GetX() && ownPosition.GetX() > minPosition.GetX()) {
		ownPosition = Vector2d(ownPosition.GetX() - 1, ownPosition.GetY());
	}
	else if (ownPosition.GetX() < targetPosition.GetX() && ownPosition.GetX() > maxPosition.GetX()) {
		ownPosition = Vector2d(ownPosition.GetX() + 1, ownPosition.GetY());
	}
	else if (ownPosition.GetY() < targetPosition.GetY() && ownPosition.GetY() > minPosition.GetY()) {
		ownPosition = Vector2d(ownPosition.GetX(), ownPosition.GetY() - 1);
	}
	else if (ownPosition.GetY() < targetPosition.GetY() && ownPosition.GetY() > maxPosition.GetY()) {
		ownPosition = Vector2d(ownPosition.GetX(), ownPosition.GetY() + 1);
	}
	return ownPosition;
}
