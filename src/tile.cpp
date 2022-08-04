#include "tile.hpp"

Tile::Tile(bool passable, bool node, bool wall, bool ghostHouse, sf::Vector2f pos, sf::Color color)
{
    isPassable = passable;
    isWall = wall;
    isGhostHouse = ghostHouse;
    this -> pos = pos;
    this -> color = color;
    shape.setFillColor(color);
    shape.setSize(sf::Vector2f(TileLength, TileLength));
    shape.setPosition(pos);
}

Tile::Tile(sf::Vector2f pos)
{
    isPassable = true;
    isWall = false;
    isGhostHouse = false;
    this -> pos = pos;
    this -> color = sf::Color::Cyan;
    shape.setPosition(pos);
}

unsigned int Tile::getLength()
{
    return TileLength;
}

sf::RectangleShape & Tile::getShape()
{
    return shape;
}

const sf::RectangleShape & Tile::getShape() const
{
    return shape;
}

void Tile::considerAsWall()
{
    bool isPassable = false;
    bool isWall = true;
    bool isGhostHouse = false;
    bool isPinkTile = false;
    bool isRedTile = false;
}

void Tile::considerAsRed()
{
    bool isPassable = true;
    bool isWall = false;
    bool isGhostHouse = false;
    bool isPinkTile = false;
    bool isRedTile = true; 
}

void Tile::considerAsPink()
{
    bool isPassable = true;
    bool isWall = false;
    bool isGhostHouse = false;
    bool isPinkTile = true;
    bool isRedTile = false; 
}