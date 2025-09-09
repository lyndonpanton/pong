#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "Player.h"

void draw();
void update();

int main(int argc, char* argv[])
{
	sf::RenderWindow render_window(sf::VideoMode(1080, 720), "Pong");

	ImGui::SFML::Init(render_window);
	ImGui::GetStyle().ScaleAllSizes(1.5f);
	ImGui::GetIO().FontGlobalScale = 1.5f;
	sf::Clock delta_clock;

	while (render_window.isOpen())
	{
		sf::Event event;

		while (render_window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) render_window.close();
		}

		ImGui::SFML::Update(render_window, delta_clock.restart());

		render_window.clear(sf::Color(0, 0, 0));

		ImGui::SFML::Render(render_window);
		render_window.display();
	}

	ImGui::SFML::Shutdown(render_window);

	return 0;
}

void draw()
{

}

void update()
{

}
