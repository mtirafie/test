#ifndef _MAP
#define _MAP

#include <vector>
#include <array>
#include "tile.hpp"
#include "wall.hpp"

class Map
{
    public:
        Map();
        ~Map();
        void setUpTiles();
        void setUpWalls();
        void setWallPoses(sf::Vector2f, sf::Vector2f);
        void setWallPoses(sf::Vector2f, sf::Vector2f, sf::Vector2f);
        void setRedPoses();
        void setPinkPoses();
        void setUpNodes();
        void setTileWalls();
        bool wallPosExists(sf::Vector2f);
        void distinguish_tileWalls();
        void distinguish_redTiles();
        void distinguish_pinkTiles();
        std::pair<bool, sf::Vector2f> is_on_node(sf::FloatRect);
        Tile & get_nth_tile(sf::Vector2f);
        std::array<std::array<Tile *, 28>, 31> & getTiles();
        std::vector<Wall *> & getWalls();
        std::vector<Tile *> & getTileWalls();
        std::vector<sf::RectangleShape> & get_nodes();
        const std::vector<sf::Vector2f> & getWallPoses();
    private:
        std::array<std::array<Tile *, 28>, 31> tiles;//got each tile in it.
        std::vector<Wall *> walls;// got the walls which makes the appearance of the map in it.
        std::vector<sf::Vector2f> wallsPoses;//consists of positions of tiles in which there is a wall
        std::vector<Tile *> tileWalls;//got the Tiles which contains a wall in it.
        std::vector<sf::Vector2f> redPoses;
        std::vector<sf::Vector2f> pinkPoses;
        std::vector<sf::RectangleShape> nodes;//tiles in which an object can turn
        std::vector<sf::Vector2f> nodePoses;
        unsigned int mapLength = 620;// dimension in which we 
        unsigned int mapWidth = 560;// actually play the game
};

std::ostream & operator<<(std::ostream &, const sf::Vector2f &);

#endif // _MAP