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
void PhysicsWorld::Check2CircleCol(bool* collision)
{
    for (list<Particle*>::iterator iterator1 = particles.begin(); iterator1 != particles.end(); iterator1++)
    {
        list<Particle*>::iterator iterator2 = iterator1;
       
        for (iterator2++; iterator2 != particles.end(); iterator2++)
        {
            if ((*iterator1)->collider.checkCollision((*iterator2)->collider))
            {
                cout << "Circles are colliding" << std::endl;
                Vector2d v1 = (*iterator1)->velocity;
                float m1 = (*iterator1)->mass;
                Vector2d x1 = (*iterator1)->position;

                Vector2d v2 = (*iterator2)->velocity;
                float m2 = (*iterator2)->mass;
                Vector2d x2 = (*iterator2)->position;

                Vector2d normal1 = x1 - x2;

                float dot1 = (v1 - v2).Dot(normal1);

                float normalMag = normal1.getMagnitude();

                dot1 /= normalMag;
                dot1 /= normalMag;

                Vector2d normal2 = x2 - x1;

                float dot2 = (v2 - v1).Dot(normal2);

                normalMag = normal2.getMagnitude();

                dot2 /= normalMag;
                dot2 /= normalMag;
                *collision = true;


                v1 = v1 - (dot1 * ((2 * m2) / (m1 + m2))) * normal1;
                v2 = v2 - (dot2 * ((2 * m1) / (m1 + m2))) * normal2;





                (*iterator1)->velocity = v1;
                (*iterator2)->velocity = v2;
            }

           
        }
    }
}


#pragma endregion


#pragma region Axis Aligned Bounding Box
void PhysicsWorld::CheckAABBCol(bool* collision)
{
    for (list<Particle*>::iterator iterator1 = particles.begin(); iterator1 != particles.end(); iterator1++)
    {
        list<Particle*>::iterator iterator2 = iterator1;

        for (iterator2++; iterator2 != particles.end(); iterator2++)
        {
           

            if ((*iterator1)->aabbCollider.checkCollision((*iterator2)->aabbCollider))
            {
                cout << " colliding because of AABB " << std::endl;
                Vector2d v1 = (*iterator1)->velocity;
                float m1 = (*iterator1)->mass;
                Vector2d x1 = (*iterator1)->position;

                Vector2d v2 = (*iterator2)->velocity;
                float m2 = (*iterator2)->mass;
                Vector2d x2 = (*iterator2)->position;

                Vector2d normal1 = x1 - x2;

                float dot1 = (v1 - v2).Dot(normal1);

                float normalMag = normal1.getMagnitude();

                dot1 /= normalMag;
                dot1 /= normalMag;

                Vector2d normal2 = x2 - x1;

                float dot2 = (v2 - v1).Dot(normal2);

                normalMag = normal2.getMagnitude();

                dot2 /= normalMag;
                dot2 /= normalMag;
                *collision = true;


                v1 = v1 - (dot1 * ((2 * m2) / (m1 + m2))) * normal1;
                v2 = v2 - (dot2 * ((2 * m1) / (m1 + m2))) * normal2;





                (*iterator1)->velocity = v1;
                (*iterator2)->velocity = v2;
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
                Vector2d v1 = (*iterator1)->velocity;
                float m1 = (*iterator1)->mass;
                Vector2d x1 = (*iterator1)->position;

                Vector2d v2 = (*iterator2)->velocity;
                float m2 = (*iterator2)->mass;
                Vector2d x2 = (*iterator2)->position;

                Vector2d normal1 = x1 - x2;

                float dot1 = (v1 - v2).Dot(normal1);

                float normalMag = normal1.getMagnitude();

                dot1 /= normalMag;
                dot1 /= normalMag;

                Vector2d normal2 = x2 - x1;

                float dot2 = (v2 - v1).Dot(normal2);

                normalMag = normal2.getMagnitude();

                dot2 /= normalMag;
                dot2 /= normalMag;
                *collision = true;

              
                v1 = v1 - (dot1 * ((2 * m2) / (m1 + m2))) * normal1;
                v2 = v2 - (dot2 * ((2 * m1) / (m1 + m2))) * normal2;

               

                

                (*iterator1)->velocity = v1;
                (*iterator2)->velocity = v2;
            }
        }
    }
}
#pragma endregion
