#include "Particle.h"
#include "PhysicsWorld.h"


Particle::Particle(Vector2d position, float mass, float dragCoeffecient)
{
	this->position = position;
	this->mass = mass;
	this->dragCoeffecient = dragCoeffecient;


	collider.center = position;
	collider.r = 100;

	
	
	aabbCollider.ul = Vector2d(0, 0);
	aabbCollider.lr = Vector2d(collider.r*2, collider.r*2);
	aabbCollider.updatePosition(position);


	vector<Vector2d> points;

	points.push_back(Vector2d(0, 0));
	points.push_back(Vector2d(0, collider.r * 2));
	points.push_back(Vector2d(collider.r * 2, collider.r * 2));
	points.push_back(Vector2d(collider.r * 2, 0));

	satCollider.points = points;
	satCollider.updatePosition(position);
}

void Particle::Update(float dt)
{
	acceleration = forces *(1.f / mass);

	velocity += acceleration * dt;

	this->position += velocity * dt;

	this->forces = Vector2d(0, 0);
	collider.center = position;

	

	if (velocity.getMagnitude() > 0) {
		Vector2d dragF = -0.5 * velocity * velocity.getMagnitude() * dragCoeffecient;
		this->addForce(dragF);

	}
	//this->addForce(PhysicsWorld::gravity);

	aabbCollider.updatePosition(position);

	satCollider.updatePosition(position);
		
		
}

void Particle::addForce(Vector2d force)
{
	
	forces += force;
}
