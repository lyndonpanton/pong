#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "Player.h"

void draw(sf::RenderWindow&, Player&);
void update(Player&);

int main(int argc, char* argv[])
{
	int* player_one_position = new int[2];
	player_one_position[0] = 100;
	player_one_position[1] = 310;
	int* player_one_dimension = new int[2];
	player_one_dimension[0] = 20;
	player_one_dimension[1] = 100;
	int* player_one_colour = new int[3];
	player_one_colour[0] = 255;
	player_one_colour[1] = 0;
	player_one_colour[2] = 0;

	int* player_two_position = new int[2];
	player_two_position[0] = 980;
	player_two_position[1] = 310;
	int* player_two_dimension = new int[2];
	player_two_dimension[0] = 20;
	player_two_dimension[1] = 100;
	int* player_two_colour = new int[3];
	player_two_colour[0] = 0;
	player_two_colour[1] = 255;
	player_two_colour[2] = 0;

	Player player_one("Player One", player_one_position, player_one_dimension, player_one_colour);
	Player player_two("Player Two", player_two_position, player_two_dimension, player_two_colour);
	sf::RenderWindow render_window(sf::VideoMode(1080, 720), "Pong");
	render_window.setFramerateLimit(60);

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

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player_one.is_moving_up = true;
					std::cout << "Player one up pressed" << std::endl;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player_one.is_moving_down = true;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					player_two.is_moving_up = true;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					player_two.is_moving_down = true;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player_one.is_moving_up = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player_one.is_moving_down = false;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					player_two.is_moving_up = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					player_two.is_moving_down = false;
				}
			}
		}

		ImGui::SFML::Update(render_window, delta_clock.restart());

		render_window.clear(sf::Color(0, 0, 0));

		draw(render_window, player_one);
		draw(render_window, player_two);

		update(player_one);
		update(player_two);

		ImGui::SFML::Render(render_window);
		render_window.display();
	}

	ImGui::SFML::Shutdown(render_window);

	return 0;
}

void draw(sf::RenderWindow& render_window, Player& player)
{
	sf::RectangleShape player_shape(sf::Vector2f(
		player.get_dimensions()[0],
		player.get_dimensions()[1]
	));
	player_shape.setPosition(
		player.get_position()[0],
		player.get_position()[1]
	);
	player_shape.setFillColor(sf::Color(
		player.get_colour()[0],
		player.get_colour()[1],
		player.get_colour()[2]
	));
	render_window.draw(sf::RectangleShape(player_shape));
}

void update(Player& player)
{
	if (player.is_moving_up)
	{
		player.set_position(new int[2] {
			player.get_position()[0],
			player.get_position()[1] - player.speed
		});
	}
	if (player.is_moving_down)
	{
		player.set_position(new int[2] {
			player.get_position()[0],
			player.get_position()[1] + player.speed
		});
	}
}
