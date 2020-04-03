#include "EvadeBehaviour.h"

EvadeBehaviour::EvadeBehaviour()
{
}

EvadeBehaviour::~EvadeBehaviour()
{
}

Vector2d EvadeBehaviour::Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition, Vector2d maxPosition , float gap)
{
	if ((ownPosition - targetPosition).GetMagnitude() < gap)
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
	}
	return ownPosition;
}

	

