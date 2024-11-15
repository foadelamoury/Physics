#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Particle.h"
#include "PhysicsWorld.h"
#include "Vector2d.h"

using namespace sf;

void DrawCircle(sf::CircleShape& circle, sf::RenderWindow& window)
{
    circle.setRadius(100);
    circle.setOrigin({ circle.getRadius(), circle.getRadius() });
    circle.setPosition({ window.getSize().x / 4.0f, window.getSize().y - 400.0f });
    circle.setFillColor(sf::Color::Red);
}
int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "Circle Velocity and Acceleration");
    window.setFramerateLimit(144);
    CircleShape circle;
    DrawCircle(circle, window);
    PhysicsWorld world;
    
    Particle particle = Particle(Vector2d({circle.getPosition().x,circle.getPosition().y}));
  
    particle.position.x= circle.getPosition().x;
    particle.position.y = circle.getPosition().y;

    world.addParticle(&particle);

    Clock clock;

    float time = 0;
    float dt=0;

    Renderer renderer;
     renderer.AddDrawable(&circle);
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
        particle.addForce(Vector2d({ 1000,0 }));
        world.Update(dt);

        circle.setPosition(particle.position.x, particle.position.y);
        renderer.Render(&window);
    }
}
