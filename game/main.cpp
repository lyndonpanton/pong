#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Ball.h"

/*
	TODO

	- [ ] Gameplay
		- [x] Draw the divider
		- [x] Draw ball
		- [x] Move ball in the pre-defined direction on start
		- [ ] Handle collisions between ball and horizontal edges
		- [ ] Move ball in random direction (within boundary)
		- [ ] Move ball on keypress (i.e., spacebar)
		- [ ] Handle collisions between ball and vertical edges
			- [ ] Give players a "points" member
			- [ ] The relevant player's "points" member should be updated
		- [ ] Handle collisions between a ball and a paddle
			- [ ] Reverse x velocity of ball on collision
			- [ ] Change velocity of ball based on what edge of paddle was hit
				- [ ] Hitting "front" of paddle should reverse the x velocity
				of the ball
				- [ ] Hitting top or bottom of padding should reverse the y
				velocity of the ball
				- [ ] Prioritise front of paddle over top and bottom of paddle
			- [ ] Change velocity of ball based on what section of "front" edge was
			hit
		- [ ] Game can be won (default: 10 points)
		- [ ] Game can be paused (default: Escape key)
	- [ ] UI
		- [ ] Display the score for each player
		- [ ] Display message with winner name when game finishes
		- [ ] Display message whilst the game is paused
	- [ ] Sound
		- [ ] Game starts
		- [ ] Ball collides with top or bottom edge
		- [ ] Ball collides with player 1
		- [ ] Ball collides with player 2
		- [ ] Player 1 scores a point
		- [ ] Player 2 scores a point
		- [ ] A player wins
	- [ ] Player modifications
		- [ ] Colour of a paddle can be modified
		- [ ] Name of a player can be modified
		- [ ] Height of a paddle can be modified
		- [ ] Speed of a paddle can be modified
		- [ ] Size of a ball can be modified
		- [ ] Colour of a ball can be modified
		- [ ] Speed of a ball can be modified
	- Maintenance
		- [ ] Create an Entity class
		- [ ] Store the players and ball in a collection
		- [ ] Modify the Player and Ball classes
		- [ ] Modify the draw and update methods
		- [ ] Use a configuration file
			- [ ] Window properties
			- [ ] Font properties
			- [ ] Divider properties
			- [ ] Ball properties
			- [ ] Player one properties
			- [ ] Player two properties
*/

void draw_ball(sf::RenderWindow&, Ball&);
void draw_divider(sf::RenderWindow&);
void draw_player(sf::RenderWindow&, Player&);

void update_player(sf::RenderWindow&, Player&);
void update_ball(sf::RenderWindow&, Ball&);

int main(int argc, char* argv[])
{
	int* player_one_position = new int[2];
	player_one_position[0] = 100;
	player_one_position[1] = 310;
	int* player_one_dimension = new int[2];
	player_one_dimension[0] = 20;
	player_one_dimension[1] = 100;
	int* player_one_colour = new int[3];
	/*player_one_colour[0] = 255;
	player_one_colour[1] = 0;
	player_one_colour[2] = 0;*/
	player_one_colour[0] = 255;
	player_one_colour[1] = 255;
	player_one_colour[2] = 255;

	int* player_two_position = new int[2];
	player_two_position[0] = 980;
	player_two_position[1] = 310;
	int* player_two_dimension = new int[2];
	player_two_dimension[0] = 20;
	player_two_dimension[1] = 100;
	int* player_two_colour = new int[3];
	/*player_two_colour[0] = 0;
	player_two_colour[1] = 255;
	player_two_colour[2] = 0;*/
	player_two_colour[0] = 255;
	player_two_colour[1] = 255;
	player_two_colour[2] = 255;

	Player player_one(
		"Player One",
		player_one_position,
		player_one_dimension,
		player_one_colour
	);
	Player player_two(
		"Player Two",
		player_two_position,
		player_two_dimension,
		player_two_colour
	);
	Ball ball(
		new int[2] { 530, 350 },
		10,
		32,
		new float[2] { -2, 2 },
		new int[3] { 255, 255, 255 }
	);
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

		draw_divider(render_window);
		draw_ball(render_window, ball);
		draw_player(render_window, player_one);
		draw_player(render_window, player_two);

		update_player(render_window, player_one);
		update_player(render_window, player_two);
		update_ball(render_window, ball);

		ImGui::SFML::Render(render_window);
		render_window.display();
	}

	ImGui::SFML::Shutdown(render_window);

	return 0;
}

void draw_ball(sf::RenderWindow& render_window, Ball& ball)
{
	sf::CircleShape circle(ball.get_radius(), ball.get_point_count());
	// does not start perfectly in the center
	circle.setPosition(sf::Vector2f(
		ball.get_position()[0], ball.get_position()[1]
	));
	circle.setFillColor(sf::Color(
		ball.get_colour()[0],
		ball.get_colour()[1],
		ball.get_colour()[2]
	));
	render_window.draw(circle);
}

void draw_divider(sf::RenderWindow& render_window)
{
	for (int i = 0; i < render_window.getSize().y + 80; i += 80)
	{
		sf::RectangleShape divider_segment(sf::Vector2f(5, 50));
		divider_segment.setPosition(
			render_window.getSize().x / 2.0f - divider_segment.getSize().x / 2.0f,
			i
		);
		divider_segment.setFillColor(sf::Color(255, 255, 255));

		render_window.draw(divider_segment);
	}
}

void draw_player(sf::RenderWindow& render_window, Player& player)
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

void update_ball(sf::RenderWindow& render_window, Ball& ball)
{
	if (
		ball.get_position()[1] < 0
		|| ball.get_position()[1] + ball.get_radius() * 2 > render_window.getSize().y
		/*ball.get_position()[1] < 0
		|| ball.get_position()[1] > render_window.getSize().y*/
	)
	{
		ball.set_velocity(new float[2] {
			ball.get_velocity()[0],
			ball.get_velocity()[1] * -1
		});
	}

	// Change later

	ball.set_position(new int[2] {
		ball.get_position()[0] + (int) ball.get_velocity()[0],
		ball.get_position()[1] + (int) ball.get_velocity()[1]
	});
}

void update_player(sf::RenderWindow& render_window, Player& player)
{
	if (player.is_moving_up)
	{
		//if (player.get_position()[1] - player.speed > 0)
		if (player.get_position()[1] > 0)
		{
			player.set_position(new int[2] {
				player.get_position()[0],
				player.get_position()[1] - (int) player.speed
			});
		}
	}
	if (player.is_moving_down)
	{
		/*if (
			player.get_position()[1] + player.speed
				< render_window.getSize().y
		)*/
		if (
			player.get_position()[1] + player.get_dimensions()[1]
				< render_window.getSize().y
		)
		{
			player.set_position(new int[2] {
				player.get_position()[0],
				player.get_position()[1] + (int) player.speed
			});
		}
	}
}
