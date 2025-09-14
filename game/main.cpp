#include <iostream>
#include <fstream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Divider.h"
#include "PlayerType.h"
#include "Player.h"
#include "Ball.h"
#include "UI.h"

void draw_ball(sf::RenderWindow&, Ball&);
void draw_divider(sf::RenderWindow&);
void draw_pause_message(sf::RenderWindow&, sf::Text&, Game&);
void draw_player(sf::RenderWindow&, Player&);
void draw_score(sf::RenderWindow&, sf::Text&, Game&, Player&);
void draw_win_screen(sf::RenderWindow&, sf::Text&, Game&, Player&, Player&);

void load_config(
	std::string,
	sf::RenderWindow&,
	sf::Image&,
	sf::Texture&,
	sf::Sprite&,
	sf::Text&,
	sf::Font&,
	Game&,
	Divider&,
	Player&,
	Player&,
	Ball&,
	UI&
);
void load_config_ball(std::ifstream&, Ball&);
void load_config_cursor(
	std::ifstream&,
	sf::RenderWindow&,
	sf::Texture&,
	sf::Sprite&
);
void load_config_divider(std::ifstream&, Divider&);
void load_config_font(std::ifstream&, sf::Text&, sf::Font&);
void load_config_game(std::ifstream&, Game&);
void load_config_player(std::ifstream&, Player&, int);
void load_config_ui(std::ifstream&, UI&);
void load_config_window(
	std::ifstream&,
	sf::RenderWindow&,
	sf::Image&
);

void update_player(sf::RenderWindow&, Player&);
void update_ball(sf::RenderWindow&, Game&, Player&, Player&, Ball&);

int main(int argc, char* argv[])
{
	sf::RenderWindow render_window;
	sf::Image render_window_icon;
	//sf::Cursor cursor;
	sf::Texture cursor_texture;
	sf::Sprite cursor_sprite;
	sf::Text text;
	sf::Font font;
	Game game;
	Divider divider;
	Player player_one;
	Player player_two;
	Ball ball;
	UI ui;

	load_config(
		"config.txt",
		render_window,
		render_window_icon,
		cursor_texture,
		cursor_sprite,
		text,
		font,
		game,
		divider,
		player_one,
		player_two,
		ball,
		ui
	);

	ImGui::SFML::Init(render_window);
	ImGui::GetStyle().ScaleAllSizes(1.5f);
	ImGui::GetIO().FontGlobalScale = 1.5f;
	sf::Clock delta_clock;

	std::cout << render_window.isOpen() << std::endl;

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
					player_one.m_is_moving_up = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player_one.m_is_moving_down = true;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					player_two.m_is_moving_up = true;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					player_two.m_is_moving_down = true;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					player_one.m_is_moving_up = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player_one.m_is_moving_down = false;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					player_two.m_is_moving_up = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					player_two.m_is_moving_down = false;
				}

				if (
					event.key.code == sf::Keyboard::Space
					&& !game.get_is_complete()
					&& !game.get_is_paused()
					&& !ball.get_is_moving()
					)
				{
					ball.set_is_moving(true);
				}

				if (
					event.key.code == sf::Keyboard::Escape
					&& !game.get_is_complete())
				{
					game.set_is_paused(!game.get_is_paused());
				}

				if (
					event.key.code == sf::Keyboard::R
					&& game.get_is_complete()
					)
				{
					game.reset();
					ball.reset();
					player_one.reset();
					player_two.reset();
				}
			}
		}

		cursor_sprite.setPosition(sf::Mouse::getPosition(render_window).x, sf::Mouse::getPosition(render_window).y);

		ImGui::SFML::Update(render_window, delta_clock.restart());

		ImGui::Begin("ImGui");

		if (ImGui::BeginTabBar("Modifications"))
		{
			if (ImGui::BeginTabItem("Game"))
			{
				ImGui::InputInt("Target Score", &game.m_target_score, 1);
				ImGui::Checkbox("Is Paused", &game.m_is_paused);

				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Player"))
			{
				ImGui::Text("Player 1");
				ImGui::SliderInt("Height##player_one", &player_one.m_dimension[1], 20, 200);
				ImGui::SliderInt("Speed##player_one", &player_one.m_speed, 1, 20);
				float* player_one_colour = new float[3] {
					player_one.get_colour()[0] / 255.0f,
					player_one.get_colour()[1] / 255.0f,
					player_one.get_colour()[2] / 255.0f
				};
				ImGui::ColorEdit3("Colour##player_one", player_one_colour);
				player_one.set_colour(new int[3] {
					(int) (player_one_colour[0] * 255),
					(int) (player_one_colour[1] * 255),
					(int) (player_one_colour[2] * 255)
				});

				ImGui::Text("Player 2");
				ImGui::SliderInt("Height##player_two", &player_two.m_dimension[1], 20, 200);
				ImGui::SliderInt("Speed##player_two", &player_two.m_speed, 1, 20);
				float* player_two_colour = new float[3] {
					player_two.get_colour()[0] / 255.0f,
						player_two.get_colour()[1] / 255.0f,
						player_two.get_colour()[2] / 255.0f
					};
				ImGui::ColorEdit3("Colour##player_two", player_two_colour);
				player_two.set_colour(new int[3] {
					(int) (player_two_colour[0] * 255),
					(int) (player_two_colour[1] * 255),
					(int) (player_two_colour[2] * 255)
				});

				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Ball"))
			{

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}

		ImGui::End();

		render_window.clear(sf::Color(0, 0, 0));

		if (game.get_is_complete())
		{
			draw_win_screen(render_window, text, game, player_one, player_two);
		}
		else
		{
			if (!game.get_is_paused())
			{
				player_one.update(render_window.getView().getSize().y);
				player_two.update(render_window.getView().getSize().y);

				if (ball.get_is_moving())
					update_ball(render_window, game, player_one, player_two, ball);
			}
			else
			{
				draw_pause_message(render_window, text, game);
			}
		}

		draw_divider(render_window);
		draw_ball(render_window, ball);
		draw_player(render_window, player_one);
		draw_player(render_window, player_two);
		draw_score(render_window, text, game, player_one);
		draw_score(render_window, text, game, player_two);

		render_window.draw(cursor_sprite);
		render_window.setMouseCursorVisible(false);

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

void draw_pause_message(sf::RenderWindow& render_window, sf::Text& text, Game& game)
{
	text.setCharacterSize(game.get_font_ui_size());
	text.setString(game.get_pause_message());
	text.setPosition(render_window.getSize().x / 2.0f - 190, render_window.getSize().y / 2.0f - 80);

	render_window.draw(text);
}

void draw_player(sf::RenderWindow& render_window, Player& player)
{
	sf::RectangleShape player_shape(sf::Vector2f(
		player.get_dimension()[0],
		player.get_dimension()[1]
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
	sf::RenderWindow& render_window, sf::Text& text, Game& game, Player& player
)
{
	text.setCharacterSize(game.get_font_ui_size());
	text.setString(std::to_string(player.get_score()));

	if (player.get_player_type() == PlayerType::ONE)
		text.setPosition(120, 40);
	else
		text.setPosition(920, 40);

	render_window.draw(text);
}

void draw_win_screen(
	sf::RenderWindow& render_window,
	sf::Text& text,
	Game& game,
	Player& player_one,
	Player& player_two
)
{
	std::string win_message;

	if (game.get_winner() == PlayerType::ONE)
	{
		win_message = player_one.get_name();
		//win_message += " (P1)";
	}
	else
	{
		win_message = player_two.get_name();
		//win_message += " (P2)";
	}
	
	win_message += " wins!";

	text.setCharacterSize(80);
	text.setString(win_message);
	text.setPosition(render_window.getSize().x / 2.0f - 160, render_window.getSize().y / 2.0f - 80);

	render_window.draw(text);
}

void load_config(
	std::string file_path,
	sf::RenderWindow& render_window,
	sf::Image& render_window_icon,
	sf::Texture& cursor_texture,
	sf::Sprite& cursor_sprite,
	sf::Text& text,
	sf::Font& font,
	Game& game,
	Divider& divider,
	Player& player_one,
	Player& player_two,
	Ball& ball,
	UI& ui
)
{
	int player_index = 1;

	std::string current_token;
	std::ifstream file_stream(file_path);

	while (file_stream >> current_token)
	{
		if (current_token == "WINDOW")
		{
			load_config_window(file_stream, render_window, render_window_icon);
		}
		else if (current_token == "CURSOR")
		{
			load_config_cursor(
				file_stream,
				render_window,
				cursor_texture,
				cursor_sprite
			);
		}
		else if (current_token == "FONT")
		{
			load_config_font(file_stream, text, font);
		}
		else if (current_token == "GAME")
		{
			load_config_game(file_stream, game);
		}
		else if (current_token == "DIVIDER")
		{
			load_config_divider(file_stream, divider);
		}
		else if (current_token == "PLAYER")
		{
			if (player_index == 1)
			{
				std::cout << "Player 1 loaded" << std::endl;
				load_config_player(file_stream, player_one, player_index++);
			}
			else {
				std::cout << "Player 2 loaded" << std::endl;
				load_config_player(file_stream, player_two, player_index++);
			}
		}
		else if (current_token == "BALL")
		{
			load_config_ball(file_stream, ball);
		}
		else if (current_token == "UI")
		{
			load_config_ui(file_stream, ui);
		}
	}
}

void load_config_ball(std::ifstream& file_stream, Ball& ball)
{
	int position_x;
	int position_y;
	int radius;
	int point_count;
	float velocity_x;
	float velocity_y;
	int colour_red;
	int colour_green;
	int colour_blue;

	file_stream >> position_x >> position_y >> radius >> point_count
		>> velocity_x >> velocity_y >> colour_red >> colour_green
		>> colour_blue;

	ball.set_position(new int[2] { position_x, position_y });
	ball.set_position_initial(new int[2] { position_x, position_y });
	ball.set_radius(radius);
	ball.set_point_count(point_count);
	ball.set_velocity(new float[2] { velocity_x, velocity_y });
	ball.set_velocity_initial(new float[2] { velocity_x, velocity_y });
	ball.set_colour(new int[3] { colour_red, colour_green, colour_blue });
}

void load_config_cursor(
	std::ifstream& file_stream,
	sf::RenderWindow& render_window,
	sf::Texture& cursor_texture,
	sf::Sprite& cursor_sprite
)
{

	if (!cursor_texture.loadFromFile("image/cursor.png"))
	{
		std::cerr << "Error: Cursor file could not be loaded" << std::endl;
		std::cout << "System default cursor icon will be used" << std::endl;
	}

	cursor_sprite.setTexture(cursor_texture);
}

void load_config_divider(std::ifstream& file_stream, Divider& divider)
{
	int width;
	int height;
	int gap;
	int colour_red;
	int colour_green;
	int colour_blue;

	file_stream >> width >> height >> gap >> colour_red >> colour_green
		>> colour_blue;

	divider.set_colour(colour_red, colour_green, colour_blue);
	divider.set_dimension(width, height);
	divider.set_gap(gap);
}

void load_config_font(std::ifstream& file_stream, sf::Text& text, sf::Font& font)
{
	std::string font_file_path;
	int font_size;
	int font_colour_red;
	int font_colour_green;
	int font_colour_blue;

	file_stream >> font_file_path >> font_size >> font_colour_red
		>> font_colour_green >> font_colour_blue;

	if (!font.loadFromFile(font_file_path))
	{
		std::cerr << "Error: Font file could not be loaded" << std::endl;
		std::cout << "System default font will be used" << std::endl;
	}
	else
	{
		text.setFont(font);
		text.setCharacterSize(font_size);
		text.setFillColor(sf::Color(
			font_colour_red,
			font_colour_green,
			font_colour_blue
		));
	}
}

void load_config_game(std::ifstream& file_stream, Game& game)
{
	int target_score;
	int pause_message_offset_x;
	int pause_message_offset_y;
	std::string pause_message;

	file_stream >> target_score >> pause_message_offset_x >> pause_message_offset_y
		>> pause_message;

	game.set_target_score(target_score);
	game.set_pause_message(pause_message);
	game.set_pause_message_offset(
		pause_message_offset_x, pause_message_offset_y
	);
}

void load_config_player(std::ifstream& file_stream, Player& player, int player_index)
{
	std::string name;
	int position_x;
	int position_y;
	int width;
	int height;
	int speed;
	int colour_red;
	int colour_green;
	int colour_blue;

	file_stream >> name >> position_x >> position_y >> width >> height >> speed
		>> colour_red >> colour_green >> colour_blue;

	if (player_index == 1)
		player.set_player_type(PlayerType::ONE);
	else
		player.set_player_type(PlayerType::TWO);
	player.set_name(name);
	player.set_position(new int[2] { position_x, position_y });
	player.set_position_initial(new int[2] { position_x, position_y });
	player.set_dimension(new int[3] { width, height });
	player.set_speed(speed);
	player.set_colour(new int[3] { colour_red, colour_green, colour_blue });
}

void load_config_ui(std::ifstream& file_stream, UI& ui)
{
	int player_one_score_position_x;
	int player_one_score_position_y;
	int player_two_score_position_x;
	int player_two_score_position_y;
	int pause_message_position_x;
	int pause_message_position_y;

	file_stream >> player_one_score_position_x >> player_one_score_position_y
		>> player_two_score_position_x >> player_two_score_position_y
		>> pause_message_position_x >> pause_message_position_y;

	ui.set_player_one_score_position(
		player_one_score_position_x, player_one_score_position_y
	);
	ui.set_player_two_score_position(
		player_two_score_position_x, player_two_score_position_y
	);
	ui.set_pause_message_position(
		pause_message_position_x, pause_message_position_y
	);
}

void load_config_window(
	std::ifstream& file_stream,
	sf::RenderWindow& render_window,
	sf::Image& icon
)
{
	std::string title;
	int width;
	int height;
	int framerate_limit;
	int is_visible;
	int is_cursor_visible;
	std::string icon_file_path;

	file_stream >> title >> width >> height >> framerate_limit >> is_visible
		>> is_cursor_visible >> icon_file_path;

	render_window.create(sf::VideoMode(width, height), title);
	render_window.setFramerateLimit(framerate_limit);
	render_window.setVisible(is_visible);
	std::cout << "Visible: " << is_visible << std::endl;
	render_window.setMouseCursorVisible(is_cursor_visible);
	
	if (!icon.loadFromFile(icon_file_path))
	{
		std::cerr << "Error: Window icon file could not be loaded" << std::endl;
		std::cout << "System default window icon will be used" << std::endl;
		exit(1);
	}
	else
	{
		render_window.setIcon(
			icon.getSize().x,
			icon.getSize().y,
			icon.getPixelsPtr()
		);
	}
}

void update_ball(
	sf::RenderWindow& render_window,
	Game& game,
	Player& player_one,
	Player& player_two,
	Ball& ball
)
{
	if (
		ball.get_position()[0] + (ball.get_radius() * 2)
			<= 0
	)
	{
		ball.reset(player_two);
	}
	else if (
		// render_window.getSize().x was not working?
		ball.get_position()[0] >= render_window.getView().getSize().x
	)
	{	
		ball.reset(player_one);
	}

	if (player_one.get_score() == game.get_target_score())
	{
		game.finish(player_one);
	}
	else if (player_two.get_score() == game.get_target_score())
	{
		game.finish(player_two);
	}

	// Ball / environment (horizontal edge) collision
	if (
		ball.get_position()[1] < 0
		|| ball.get_position()[1] + ball.get_radius() * 2 > render_window.getSize().y
	)
	{
		ball.reflect();
	}

	// Ball / player one (front edge) collision
	if (
		(
			ball.get_position()[0] <= player_one.get_position()[0]
				+ player_one.get_dimension()[0]
			&& ball.get_position()[0] >= player_one.get_position()[0]
				+ player_one.get_dimension()[0]
		)
		&& ball.get_velocity()[0] < 0
	)
	{
		if (
			ball.get_position()[1] + (ball.get_radius() * 2)
				>= player_one.get_position()[1]
			&& ball.get_position()[1]
				<= player_one.get_position()[1]
				+ player_one.get_dimension()[1]
		)
		{
			ball.collide(player_one);
		}
	}
	else if (
		ball.get_position()[0] + (ball.get_radius() * 2)
			>= player_one.get_position()[0]
		&& ball.get_position()[0]
			<= player_one.get_position()[0] + player_one.get_dimension()[0]
	)
	{
		if (
			ball.get_position()[1] + (ball.get_radius() * 2)
				>= player_one.get_position()[1]
			&& ball.get_position()[1]
				<= player_one.get_position()[1] + player_one.get_dimension()[1]
		)
		{
			ball.reflect();
		}
	}

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
				+ player_two.get_dimension()[1]
			)
		{
			ball.collide(player_two);
		}
	}
	else if (
		ball.get_position()[0] + (ball.get_radius() * 2)
			>= player_two.get_position()[0]
		&& ball.get_position()[0]
			<= player_two.get_position()[0] + player_two.get_dimension()[0]
	)
	{
		if (
			ball.get_position()[1] + (ball.get_radius() * 2)
				>= player_two.get_position()[1]
			&& ball.get_position()[1] 
				<= player_two.get_position()[1] + player_two.get_dimension()[1]
			)
		{
			ball.reflect();
		}
	}

	ball.update();
}
