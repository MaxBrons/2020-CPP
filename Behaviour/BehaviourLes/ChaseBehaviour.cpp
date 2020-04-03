#include "ChaseBehaviour.h"
#include "Vector2d.h"


ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

Vector2d ChaseBehaviour::Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = {1,1}, Vector2d maxPosition)
{

	if (ownPosition < targetPosition && ownPosition < maxPosition) {
		return ownPosition+1;
	}
	if (ownPosition > targetPosition && ownPosition > minPosition) {
		return ownPosition-1;
	}
	return ownPosition;
}
