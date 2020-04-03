#include "Character.h"

Character::Character(AvailableBehaviours aStartBehaviour, Vector2d* aStartPosition, std::string anIcon, Character* aTarget)
	:position(aStartPosition), icon(anIcon), currentBehaviour(new Behaviour()), target(aTarget)
{
	if (aTarget) {
		switch (aStartBehaviour)
		{
		case Character::AvailableBehaviours::CHASE:
			currentBehaviour = new ChaseBehaviour();
			break;
		case Character::AvailableBehaviours::EVADE:
			currentBehaviour = new EvadeBehaviour();
			break;
		default:
			break;
		}
		target = aTarget;
	}
}

Character::~Character()
{
}

void Character::SetTarget(Character* aTarget)
{
	target = aTarget;
}

void Character::Setbehaviour(AvailableBehaviours aBehaviour)
{

	switch (aBehaviour)
	{
	case Character::AvailableBehaviours::IDLE:
		currentBehaviour = nullptr;
		break;
	case Character::AvailableBehaviours::CHASE:
		currentBehaviour = new ChaseBehaviour();
		break;
	case Character::AvailableBehaviours::EVADE:
		currentBehaviour = new EvadeBehaviour();
		break;
	default:
		break;
	}
}

Vector2d Character::Update()
{
	if (target && currentBehaviour) {
		position = currentBehaviour->Update(&position, &target->GetPosition());
	}
	return position;
}

Vector2d Character::GetPosition()
{
	return position;
}

std::string Character::GetIcon()
{
	return icon;
}
