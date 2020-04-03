#pragma once
#include <string>
#include <cmath>
#include <typeinfo>
#include "Vector2d.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

class Character
{
public:
	enum class AvailableBehaviours {
		IDLE,
		CHASE,
		EVADE
	};
public:
	Character(AvailableBehaviours aStartBehaviour,
		Vector2d aStartPosition = { 0, 0 },
		std::string anIcon = "x",
		Character* aTarget = nullptr
	);
	~Character();
	void SetTarget(Character* aTarget);
	void Setbehaviour(AvailableBehaviours aBehaviour);
	Vector2d Update();
	Vector2d GetPosition();
	std::string GetIcon();
private:
	Behaviour* currentBehaviour;
	Character* target;
	Vector2d position;
	std::string icon;
};

