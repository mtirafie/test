#include "game.hpp"
#include <iostream>


Game::Game()
{
    wall.setFillColor(sf::Color::Black);
    wall.setSize(sf::Vector2f(50, 50));
    wall.setPosition(200, 200);
}

bool Game::check_wall_collision(sf::Vector2f dir, float dt)
{
    sf::FloatRect wallBounds;
    sf::FloatRect playerBounds = pacman.get_TileItIsOn_rect();
    sf::FloatRect nextPos = playerBounds;
    sf::Vector2f velocity = dir * pacman.get_speed();
    bool intersects = false;

    nextPos.left += velocity.x * dt;
    nextPos.top += velocity.y * dt;

    for(auto & item: map.getTileWalls())
    {
        wallBounds = (item -> getShape()).getGlobalBounds();
        if(wallBounds.intersects(nextPos))
        {
            std::cout << "damn son where da find this!" << std::endl;
            //bottom collistion
            if(playerBounds.top < wallBounds.top
            && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity.y = 0.f;
                pacman.set_position(playerBounds.left, wallBounds.top - playerBounds.height);
                pacman.move_to_new_set_position();
            }
            //top collistion
            else if(playerBounds.top > wallBounds.top
            && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity.y = 0.f;
                pacman.set_position(playerBounds.left, wallBounds.top + wallBounds.height);
                pacman.move_to_new_set_position();
            }
            //right collistion
            else if(playerBounds.left < wallBounds.left
            && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity.x = 0.f;
                pacman.set_position(wallBounds.left - playerBounds.width, playerBounds.top);
                pacman.move_to_new_set_position();
            }
            //left collistion
            else if(playerBounds.left > wallBounds.left
            && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity.x = 0.f;
                pacman.set_position(wallBounds.left + wallBounds.width, playerBounds.top);
                pacman.move_to_new_set_position();
            }
            intersects = true;
        }
        pacman.set_velocity(velocity);
    }

    return intersects;
}

bool Game::going_to_have_collision(sf::Vector2f dir, float dt)
{
    sf::FloatRect wallBounds;
    sf::FloatRect playerBounds = pacman.get_TileItIsOn_rect();
    sf::FloatRect nextPos = playerBounds;
    sf::Vector2f velocity = dir * pacman.get_speed();

    nextPos.left += velocity.x * dt;
    nextPos.top += velocity.y * dt;

    if(wallBounds.intersects(nextPos))
    {
        return true;
    }
    return false;
}