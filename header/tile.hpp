#ifndef _TILE
#define _TILE

#include <SFML/Graphics.hpp>

class Tile
{
    public:
        Tile(bool, bool, bool, bool, sf::Vector2f, sf::Color);
        Tile(sf::Vector2f);
        unsigned int getLength();
        sf::RectangleShape & getShape();
        const sf::RectangleShape & getShape() const;
        void considerAsWall();
        void considerAsRed();
        void considerAsPink();
    private:
        bool isPassable;
        bool isWall;
        bool isGhostHouse;
        bool isPinkTile;
        bool isRedTile;
        sf::RectangleShape shape;
        sf::Color color;
        sf::Vector2f pos;
        static const unsigned int TileLength = 20;
};

#endif // _TILE