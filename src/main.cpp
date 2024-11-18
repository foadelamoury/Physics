#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Particle.h"
#include "PhysicsWorld.h"
#include "Vector2d.h"

using namespace sf;

void DrawCircle(sf::CircleShape& circle, sf::RenderWindow& window , float x , float y, sf::Color color)
{
    circle.setRadius(100);
    circle.setOrigin({ circle.getRadius(), circle.getRadius() });
    circle.setPosition({ window.getSize().x / x, window.getSize().y - y});
    circle.setFillColor(color);
}
int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "Circle Velocity and Acceleration");
    window.setFramerateLimit(144);
    CircleShape circle1;
    CircleShape circle2;

    DrawCircle(circle1, window, 4.f,400.f,sf::Color::Red);
    DrawCircle(circle2, window, 2.f, 290.f, sf::Color::Yellow);

    PhysicsWorld world;
    
    Particle particle1 = Particle(Vector2d({circle1.getPosition().x,circle1.getPosition().y}));

    Particle particle2 = Particle(Vector2d({ circle2.getPosition().x,circle2.getPosition().y }));

  
    particle1.position.x= circle1.getPosition().x;
    particle1.position.y = circle1.getPosition().y;


    particle2.position.x = circle2.getPosition().x;
    particle2.position.y = circle2.getPosition().y;

    world.addParticle(&particle1);
    world.addParticle(&particle2);

    bool collision = false;
    Clock clock;

    float time = 0;
    float dt=0;

    Renderer renderer;
     renderer.AddDrawable(&circle1);
     renderer.AddDrawable(&circle2);

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        dt= clock.getElapsedTime().asSeconds()-time;
		time += dt;
        if (!collision)
        {
            particle1.addForce(Vector2d({ 1000,0 }));
            particle2.addForce(Vector2d({ -1000,0 }));
        }
        world.Update(dt);
  
        //world.Check2CircleCol(&collision);

        //world.CheckAABBCol(&collision);

        world.CheckSATCol(&collision);

   
        circle1.setPosition(particle1.position.x, particle1.position.y);
        circle2.setPosition(particle2.position.x, particle2.position.y);

        renderer.Render(&window);
    }
}
