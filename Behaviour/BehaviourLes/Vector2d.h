#pragma once
#include <vector>

class Vector2d
{
public:
	Vector2d(int _x, int _y);
	Vector2d(std::vector<int> someCoords);
	Vector2d(Vector2d* aVector2d);
	~Vector2d();

	int GetX();
	int GetY();
	float GetMagnitude();
	bool operator== (Vector2d v1);
	Vector2d operator-(Vector2d v1);
	
	/*bool operator>(Vector2d v1);
	bool operator<(Vector2d v1);*/

private:
	int x;
	int y;
};

