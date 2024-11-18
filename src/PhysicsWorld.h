#pragma once

#include "Particle.h"

#include <list>



using namespace std;



class PhysicsWorld

{

private:

	list<Particle*> particles;

public:

	void addParticle(Particle* particle);

	void Update(float deltaTime);

	/// <summary>
	/// checks collision between two circles
	/// </summary>
	void Check2CircleCol(bool* collision);
	void CheckAABBCol(bool* collision);

	void CheckSATCol(bool* collision);




	static const Vector2d gravity ;

};
