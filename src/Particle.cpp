#include "Particle.h"
#include "PhysicsWorld.h"


Particle::Particle(Vector2d position, float mass, float dragCoeffecient)
{
	this->position = position;
	this->mass = mass;
	this->dragCoeffecient = dragCoeffecient;
}

void Particle::Update(float dt)
{
	acceleration = forces *(1.f / mass);

	velocity += acceleration * dt;

	this->position += velocity * dt;

	this->forces = Vector2d(0, 0);
	

	if (velocity.getMagnitude() > 0) {
		Vector2d dragF = -0.5 * velocity * velocity.getMagnitude() * dragCoeffecient;
		this->addForce(dragF);

	}
	this->addForce(PhysicsWorld::gravity);

	
		
		
}

void Particle::addForce(Vector2d force)
{
	
	forces += force;
}
