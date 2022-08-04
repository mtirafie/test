#include <iostream>
#include "map.hpp"
#include "game.hpp"
#include "ghost.hpp"

int main()
{	
	sf::RenderWindow window(sf::VideoMode(560, 720), "Pacman *_*", sf::Style::Titlebar | sf::Style::Close);

	sf::Clock clock;
	sf::Time dt;
	sf::Vector2f dir {0, 0};
	sf::Vector2f previousDir {0, 0};
	sf::Vector2f keep {0, 0};
	sf::Vector2f newDir {0, 0};
	float speed = 100;
	bool kept = false;
	bool newDir_set = false;//for deciding wether we want to move based on keepDir or newDir
	std::cout << "HEllo" << std::endl;
	
	std::vector<sf::RectangleShape> walls;
	sf::RectangleShape wall;
	wall.setFillColor(sf::Color::Blue);
	wall.setPosition(200, 200);
	wall.setSize(sf::Vector2f(50, 50));

	// game elements
	Game game;
	while (window.isOpen())
	{
		dt = clock.restart();
		// dir.x = 0;
		// dir.y = 0;
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		//handle input

		// if(event.key.code == sf::Keyboard::Left)
		// {
		// 	dir.x -= 1;
		// }
		// else if(event.key.code == sf::Keyboard::Right)
		// {
		// 	dir.x += 1;
		// }
		// else if(event.key.code == sf::Keyboard::Up)
		// {
		// 	dir.y -= 1;
		// }
		// else if(event.key.code == sf::Keyboard::Down)
		// {
		// 	dir.y += 1;
		// }

		// if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		// {
		// 	dir.x -= 1;
		// }
		// else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		// {
		// 	dir.x += 1;
		// }
		// else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		// {
		// 	dir.y -= 1;
		// }
		// else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		// {
		// 	dir.y += 1;
		// }

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			dir.y = 0;
			dir.x = -1;
			newDir_set = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			dir.y = 0;
			dir.x = 1;
			newDir_set = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			dir.x = 0;
			dir.y = -1;
			newDir_set = true;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			dir.x = 0;
			dir.y = 1;
			newDir_set = true;
		}
		//update

		if(newDir_set)
		{
			newDir = dir;
		}

		if((dir.x == 1 || dir.x == -1) && dir.y == 0 && game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).first && kept)
		{
			game.pacman.set_position(game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.x, game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.y);
			game.pacman.move_to_new_set_position();
			if(!game.check_wall_collision(keep, dt.asSeconds()))
			{
				dir = keep;
				std::cout << "HERE!" << std::endl;
			}
			else
			{
				std::cout << "BOOOOM!" << std::endl;
			}
			kept = false;
		}
		else if((dir.y == 1 || dir.y == -1) && dir.x == 0 && game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).first && kept)
		{
			game.pacman.set_position(game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.x, game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.y);
			game.pacman.move_to_new_set_position();
			if(!game.check_wall_collision(keep, dt.asSeconds()))
			{
				dir = keep;
			}
			else
			{
				std::cout << "BOOOOM!" << std::endl;
			}
			kept = false;
		}

		if((previousDir.x == 1 || previousDir.x == -1) && previousDir.y == 0 && dir.x == 0 && (dir.y == 1 || dir.y == -1))
		{
			if(!game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).first)
			{
				keep = dir;
				kept = true;
				dir = previousDir;
			}
			else
			{
				game.pacman.set_position(game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.x, game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.y);
				game.pacman.move_to_new_set_position();
				if(game.check_wall_collision(dir, dt.asSeconds()))
				{
					dir = previousDir;
				}
				std::cout << "Boom!" << std::endl;
				// dir = keep;
			}
		}
		else if((previousDir.y == 1 || previousDir.y == -1) && previousDir.x == 0 && dir.y == 0 && (dir.x == 1 || dir.x == -1))
		{
			if(!game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).first)
			{
				keep = dir;
				kept = true;
				dir = previousDir;
			}
			else
			{
				game.pacman.set_position(game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.x, game.map.is_on_node(game.pacman.get_TileItIsOn_rect()).second.y);
				game.pacman.move_to_new_set_position();
				if(game.check_wall_collision(dir, dt.asSeconds()))
				{
					dir = previousDir;
				}
				// dir = keep;
			}
		}

		if(newDir_set && kept)
		{
			keep = newDir;
		}

		previousDir = dir;
		newDir_set = false;

		game.pacman.set_direction(dir);

		// check collision
		game.check_wall_collision(dir, dt.asSeconds());
		
		game.pacman.move(dt.asSeconds());

		window.clear();

		// for(auto const & item: game.map.getWalls())
		// {
		// 	if(item -> DoesItLookLikeL())
		// 	{
		// 		for(auto const & i: item -> getL())
		// 		{
		// 			window.draw(i);
		// 		}
		// 	}
		// 	else
		// 	{
		// 		window.draw(item -> getWall());
		// 	}
		// }
		game.pacman.draw(window);

		// for(auto const & item : game.map.getTileWalls())
		// {
		// 	window.draw(item -> getShape());
		// }

		for(auto const & item: game.map.getWalls())
		{
			if(item -> DoesItLookLikeL())
			{
				for(auto const & i: item -> getL())
				{
					window.draw(i);
				}
			}
			else
			{
				window.draw(item -> getWall());
			}
		}

		// for(auto const & item : game.map.getTiles())
		// {
		// 	for(auto const & i : item)
		// 	{
		// 		window.draw(i -> getShape());
		// 	}
		// }

		// for(auto const & item: game.map.get_nodes())
		// {
		// 	window.draw(item);
		// }
		window.display();
	}

	return EXIT_SUCCESS;
}