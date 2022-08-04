#include "pacman.hpp"

Pacman::Pacman()
{
    if(!texture.loadFromFile("../images/pacman.png"))
    {
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(265, 515);

    tile_itIs_on.setFillColor(sf::Color::Red);
    tile_itIs_on.setSize(sf::Vector2f(20, 20));
    tile_itIs_on.setPosition(sprite.getPosition().x + 5, sprite.getPosition().y + 5);

    center.setFillColor(sf::Color::Blue);
    center.setSize(sf::Vector2f(4, 4));
    center.setPosition(sprite.getPosition().x + 13, sprite.getPosition().y + 13);
}

void Pacman::draw(sf::RenderTarget & window)
{
    // window.draw(sprite);
    window.draw(tile_itIs_on);
    // window.draw(center);
}

void Pacman::set_direction(const sf::Vector2f & dir)
{
    this -> dir = dir;
}

void Pacman::move(float dt)
{
    sprite.move(velocity * dt);
    tile_itIs_on.move(velocity * dt);
    center.move(velocity * dt);
}

sf::FloatRect Pacman::get_TileItIsOn_rect()
{
    return tile_itIs_on.getGlobalBounds();
}

void Pacman::set_velocity(sf::Vector2f vel)
{
    velocity = vel;
}

void Pacman::set_position(float x, float y)
{
    pos = sf::Vector2f(x, y);
}

void Pacman::move_to_new_set_position()
{
    tile_itIs_on.setPosition(pos);
    // center.setPosition(pos.x + 3, pos.y + 3);
    sprite.setPosition(pos.x - 5, pos.y - 5);
}

void Pacman::move(sf::Vector2f pos)
{
    sprite.move(pos);
    tile_itIs_on.move(pos);
    center.move(pos);
}

sf::Vector2f Pacman::get_direction()
{
    return dir;
}

float Pacman::get_speed()
{
    return speed;
}

sf::Vector2f Pacman::get_position()
{
    return pos;
}