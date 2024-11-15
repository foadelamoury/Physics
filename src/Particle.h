#pragma once

#include "Vector2d.h"





class Particle

{

public:

	Vector2d position;

	Vector2d velocity;

	Vector2d acceleration;

	Vector2d forces;



	float mass;

	float dragCoeffecient;







	Particle(Vector2d position, float mass = 1, float dragCoeffecient = 0.3f);

	void Update(float dt);

	void addForce(Vector2d force);

};