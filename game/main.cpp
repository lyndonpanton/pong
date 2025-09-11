#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "PlayerType.h"
#include "Player.h"
#include "Ball.h"

/*
	TODO

	- [ ] Gameplay
		- [x] Draw the divider
		- [x] Draw ball
		- [x] Move ball in the pre-defined direction on start
		- [x] Handle collisions between ball and horizontal edges
		- [ ] Move ball in random direction (within boundary)
		- [ ] Move ball on keypress (i.e., spacebar)
		- [ ] Handle collisions between ball and vertical edges
			- [ ] Give players a "points" member
			- [ ] The relevant player's "points" member should be updated
		- [ ] Handle collisions between a ball and a paddle
			- [ ] Change velocity of ball based on what edge of paddle was hit
				- [x] Hitting "front" of paddle should reverse the x velocity
				of the ball
				- [ ] Hitting top or bottom of padding should reverse the y
				velocity of the ball
				- [ ] Prioritise front of paddle over top and bottom of paddle
				- [ ] Change velocity of ball based on what section of "front" edge was
			hit
		- [ ] Game can be won (default: 10 points)
		- [x] Game can be paused and unpaused (default: Escape key)
	- [ ] UI
		- [x] Display the score for each player
		- [ ] Display message with winner name when game finishes
		- [x] Display message whilst the game is paused
	- [ ] Sound
		- [ ] Game starts
		- [ ] Ball collides with top or bottom edge
		- [ ] Ball collides with player 1
		- [ ] Ball collides with player 2
		- [ ] Player 1 scores a point
		- [ ] Player 2 scores a point
		- [ ] A player wins
	- [ ] Modifications
		- [ ] Paddle
			- [ ] Colour of a paddle can be modified
			- [ ] Height of a paddle can be modified
			- [ ] Name of a player can be modified
			- [ ] Speed of a paddle can be modified
		- [ ] Ball
			- [ ] Colour of a ball can be modified
			- [ ] Point count of a ball can be modified
			- [ ] Radius of a ball can be modified
			- [ ] Velocity of a ball can be modified
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
void draw_pause_message(sf::RenderWindow&, sf::Text&);
void draw_player(sf::RenderWindow&, Player&);
void draw_score(sf::RenderWindow&, sf::Text&, Player&);

void load_font(sf::RenderWindow&, sf::Text&, sf::Font&);

void update_player(sf::RenderWindow&, Player&);
void update_ball(sf::RenderWindow&, Ball&, Player&, Player&);

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
	player_one_colour[1] = 255;
	player_one_colour[2] = 255;

	int* player_two_position = new int[2];
	player_two_position[0] = 980;
	player_two_position[1] = 310;
	int* player_two_dimension = new int[2];
	player_two_dimension[0] = 20;
	player_two_dimension[1] = 100;
	int* player_two_colour = new int[3];
	player_two_colour[0] = 255;
	player_two_colour[1] = 255;
	player_two_colour[2] = 255;

	Player player_one(
		PlayerType::ONE,
		"Player One",
		player_one_position,
		player_one_dimension,
		player_one_colour
	);
	Player player_two(
		PlayerType::TWO,
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
	bool is_game_playing = true;

	sf::RenderWindow render_window(sf::VideoMode(1080, 720), "Pong");
	render_window.setFramerateLimit(60);

	sf::Text text;
	sf::Font font;
	load_font(render_window, text, font);

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

				if (
					event.key.code == sf::Keyboard::Space
					&& is_game_playing
					&& !ball.get_is_moving()
				)
				{
					ball.set_is_moving(true);
				}

				if (event.key.code == sf::Keyboard::Escape)
				{
					is_game_playing = !is_game_playing;
				}
			}
		}

		ImGui::SFML::Update(render_window, delta_clock.restart());

		render_window.clear(sf::Color(0, 0, 0));

		if (is_game_playing)
		{
			update_player(render_window, player_one);
			update_player(render_window, player_two);

			if (ball.get_is_moving())
				update_ball(render_window, ball, player_one, player_two);
		}
		else
		{
			draw_pause_message(render_window, text);
		}

		draw_divider(render_window);
		draw_ball(render_window, ball);
		draw_player(render_window, player_one);
		draw_player(render_window, player_two);
		draw_score(render_window, text, player_one);
		draw_score(render_window, text, player_two);

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

void draw_pause_message(sf::RenderWindow& render_window, sf::Text& text)
{
	std::string message = "PAUSED";
	text.setString(message);
	text.setPosition(render_window.getSize().x / 2.0f - 190, render_window.getSize().y / 2.0f - 80);

	render_window.draw(text);
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

void draw_score(
	sf::RenderWindow& render_window, sf::Text& text, Player& player
)
{
	text.setString(std::to_string(player.get_score()));

	if (player.get_player_type() == PlayerType::ONE)
		text.setPosition(120, 40);
	else
		text.setPosition(920, 40);

	render_window.draw(text);
}

void load_font(sf::RenderWindow& render_window, sf::Text& text, sf::Font& font)
{
	std::string font_path = "arial.ttf";
	int font_size = 96;
	int font_colour_red = 255;
	int font_colour_green = 255;
	int font_colour_blue = 255;

	/* read in information from file... */

	if (!font.loadFromFile(font_path))
	{
		std::cerr << "Error: Font file could not be loaded" << std::endl;
		exit(1);
	}

	text.setFont(font);
	text.setCharacterSize(font_size);
	text.setFillColor(sf::Color(
		font_colour_red, font_colour_green, font_colour_blue
	));
}

void update_ball(
	sf::RenderWindow& render_window,
	Ball& ball,
	Player& player_one,
	Player& player_two
)
{
	// Ball / horizontal edge collision
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

	// Ball / vertical edge collision

	if (
		ball.get_position()[0] + (ball.get_radius() * 2)
			<= 0
	)
	{
		player_two.set_score(player_two.get_score() + 1);
		ball.reset();
	}
	
	if (
		// render_window.getSize().x was not working?
		ball.get_position()[0] >= render_window.getView().getSize().x
	)
	{	
		player_one.set_score(player_one.get_score() + 1);
		ball.reset();
	}

	// Ball / player one (front edge) collision
	if (
		(
			ball.get_position()[0] <= player_one.get_position()[0]
				+ player_one.get_dimensions()[0]
			&& ball.get_position()[0] >= player_one.get_position()[0]
				+ player_one.get_dimensions()[0]
		)
		&& ball.get_velocity()[0] < 0
	)
	{
		if (
			ball.get_position()[1] + (ball.get_radius() * 2)
				>= player_one.get_position()[1]
			&& ball.get_position()[1]
				<= player_one.get_position()[1]
				+ player_one.get_dimensions()[1]
		)
		{
			ball.set_velocity(new float[2] {
				ball.get_velocity()[0] * -1,
				ball.get_velocity()[1]
			});
		}
	}

	// Ball / player one (top edge) collision...
	
	// Ball / player one (bottom edge) collision...

	// Ball / player two (front edge) collision
	if (
		(
			ball.get_position()[0] + (ball.get_radius() * 2)
				<= player_two.get_position()[0]
			&& ball.get_position()[0] + (ball.get_radius() * 2)
				>= player_two.get_position()[0] 
		)
		&& ball.get_velocity()[0] > 0
	)
	{
		if (
			ball.get_position()[1] + (ball.get_radius() * 2)
				>= player_two.get_position()[1]
			&& ball.get_position()[1]
				<= player_two.get_position()[1]
				+ player_two.get_dimensions()[1]
			)
		{
			ball.set_velocity(new float[2] {
				ball.get_velocity()[0] * -1,
				ball.get_velocity()[1]
			});
		}
	}

	// Ball / player one (top edge) collision...

	// Ball / player two (bottom edge) collision...

	// update ball position
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
