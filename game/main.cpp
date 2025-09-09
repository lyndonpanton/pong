#include <iostream>
#include "SFML/Graphics.hpp"

int main(int argc, char* argv[])
{
	sf::RenderWindow render_window(sf::VideoMode(1080, 720), "Pong");

	while (render_window.isOpen())
	{
		sf::Event event;

		while (render_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) render_window.close();
		}

		render_window.clear(sf::Color(0, 0, 0));

		render_window.display();
	}

	return 0;
}
