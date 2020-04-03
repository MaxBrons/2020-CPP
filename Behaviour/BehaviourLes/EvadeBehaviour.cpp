#include "EvadeBehaviour.h"
#include "Vector2d.h"

EvadeBehaviour::EvadeBehaviour()
{
}

EvadeBehaviour::~EvadeBehaviour()
{
}

Vector2d EvadeBehaviour::Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = {1,1}, Vector2d maxPosition)
{
	if (abs(ownPosition - targetPosition) < 5) {

		if (ownPosition < targetPosition && ownPosition > minPosition) {
			return ownPosition -1;
		}
		else if (ownPosition > targetPosition&& ownPosition < maxPosition) {
			return ownPosition +1;
		}
	}
	return ownPosition;
}

	

