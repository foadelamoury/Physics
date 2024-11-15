#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <cmath>

void Renderer::AddDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
}

void Renderer::Render(RenderWindow* window)
{
	window->clear();

	for (Drawable* drawable : drawables)
	{
		window->draw(*drawable);
	}

	window->display();
}
