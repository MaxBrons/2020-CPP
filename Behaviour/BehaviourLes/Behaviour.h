#pragma once
class Character;

class Behaviour
{
public:
	Behaviour();
	~Behaviour();
	virtual Vector2d Update(Vector2d ownPosition, Vector2d targetPosition, Vector2d minPosition = nullptr, Vector2d maxPosition = nullptr);
};

