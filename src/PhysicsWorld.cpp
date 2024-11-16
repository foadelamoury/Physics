#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity = Vector2d(0.0, 980);

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (Particle* particle : particles)
		particle->Update(deltaTime);
}

#pragma region Basic Collision between two circles
void PhysicsWorld::Check2CircleCol()
{
    for (list<Particle*>::iterator iterator1 = particles.begin(); iterator1 != particles.end(); iterator1++)
    {
        list<Particle*>::iterator iterator2 = iterator1;
       
        for (iterator2++; iterator2 != particles.end(); iterator2++)
        {
            if ((*iterator1)->collider.checkCollision((*iterator2)->collider))
            {
                cout << "Circles are colliding" << std::endl;
            }

            /*if ((*iterator1)->aabbCollider.checkCollision((*iterator2)->aabbCollider))
            {
                cout << "AABB are colliding" << std::endl;

                
            }*/
        }
    }
}


#pragma endregion


#pragma region Axis Aligned Bounding Box
void PhysicsWorld::CheckAABBCol()
{
    for (list<Particle*>::iterator iterator1 = particles.begin(); iterator1 != particles.end(); iterator1++)
    {
        list<Particle*>::iterator iterator2 = iterator1;

        for (iterator2++; iterator2 != particles.end(); iterator2++)
        {
           

            if ((*iterator1)->aabbCollider.checkCollision((*iterator2)->aabbCollider))
            {
                cout << " colliding because of AABB " << std::endl;
            }
        }
    }
}
#pragma endregion


#pragma region Seperation Axis Theorem

void PhysicsWorld::CheckSATCol(bool *collision)
{
    for (list<Particle*>::iterator iterator1 = particles.begin(); iterator1 != particles.end(); iterator1++)
    {
        list<Particle*>::iterator iterator2 = iterator1;

        for (iterator2++; iterator2 != particles.end(); iterator2++)
        {


            if ((*iterator1)->satCollider.checkCollision((*iterator2)->satCollider))
            {
                cout << " colliding because of SAT " << std::endl;
                *collision = true;
            }
        }
    }
}
#pragma endregion
