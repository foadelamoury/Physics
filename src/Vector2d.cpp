#include "Vector2d.h"

Vector2d::Vector2d()
{
	this->x = 0;
	this->y = 0;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d other)
{
	return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other)
{
	return Vector2d(x-other.x, y- other.y);
}

Vector2d Vector2d::operator+=(Vector2d other)
{
	return Vector2d(x += other.x, y += other.y);
}

Vector2d Vector2d::operator-=(Vector2d other)
{
	return Vector2d(x-other.x, y-other.y);
}

Vector2d Vector2d::operator=(Vector2d other)
{
	return Vector2d({ x = other.x, this->y = other.y });
}



bool Vector2d::operator==(Vector2d other)
{
	return (x == other.x && y == other.y);
}

Vector2d Vector2d::operator*(float a)
{
	return Vector2d(x*a , y*a);
}

Vector2d Vector2d::operator*=(float a)
{
	return Vector2d(x*=a , y*=a);
}

float Vector2d::Dot(Vector2d other)
{
	return x*other.x + y*other.y;
}

float Vector2d::getMagnitude()
{
	return sqrt(x * x + y * y);
}

Vector2d Vector2d::getNormalized()
{
	int mag = getMagnitude();
	return Vector2d(x / mag, y / mag);
}

void Vector2d::normalize()
{
	int mag = getMagnitude();
	x /= mag;
	y /= mag;
}

Vector2d::operator Vector2f()
{
	return Vector2d(x, y);
}

Vector2d Vector2d::getNormal()
{
	return Vector2d(x/getMagnitude(), y/getMagnitude());
}

void Vector2d::print()
{
}

Vector2d operator*(float a, Vector2d vector)
{
	return Vector2d(a*vector.x, a*vector.y);
}

Vector2d operator*=(float a, Vector2d vector)
{
	return Vector2d(a*vector.x, a*vector.y);
}
