#include "ghost.hpp"

void Ghost::draw(sf::RenderTarget & window)
{
    window.draw(sprite);
    window.draw(tile_itIs_on);
}
void Ghost::set_speed(float newSpeed)
{
    speed = newSpeed;
}
void Ghost::change_speed(unsigned int percentage)
{
    float number = percentage % 100;
    speed *= number;
}
void Ghost::set_direction(sf::Vector2f direction)
{
    dir = direction;
}
sf::Vector2f Ghost::get_position()
{
    return pos;
}
void Ghost::set_position(sf::Vector2f position)
{
    pos = position;
}
