#include "Vector2d.h"
#include <cmath>

Vector2d::Vector2d(int _x, int _y)
	:x(_x),y(_y)
{
}

Vector2d::Vector2d(std::vector<int> someCoords)
	:x(someCoords.at(0)),y(someCoords.at(1))
{
}

Vector2d::Vector2d(Vector2d* aVector2d)
	:x(aVector2d->GetX()),y(aVector2d->GetY())
{
}

Vector2d::~Vector2d()
{
}

int Vector2d::GetX()
{
	return x;
}

int Vector2d::GetY()
{
	return y;
}

float Vector2d::GetMagnitude()
{
	return sqrtf(x^2 + y^2);
}

bool Vector2d::operator==(Vector2d v1)
{
	return (x == v1.GetX(), y == v1.GetY());
}

Vector2d Vector2d::operator-(Vector2d v1) {
	return Vector2d(x - v1.GetX(), y - v1.GetY());
}

