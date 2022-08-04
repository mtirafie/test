#ifndef _GAME
#define _GAME

#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "pacman.hpp"

class Game
{
    public:
        Game();
        bool check_wall_collision(sf::Vector2f, float);
        bool going_to_have_collision(sf::Vector2f, float);
        Map map;
        Pacman pacman;
        sf::RectangleShape wall;
};

#endif // _GAME