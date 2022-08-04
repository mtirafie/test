#include "map.hpp"
#include <iostream>

std::ostream & operator<<(std::ostream & output, const sf::Vector2f & pos)
{
    output << "x: " << pos.x << std::endl;
    output << "y: " << pos.y << std::endl;
    output << "---------------" << std::endl;

    return output;
}

Map::Map()
{
    setUpTiles();
    setUpWalls();
    distinguish_tileWalls();
    setRedPoses();
    distinguish_redTiles();
    setPinkPoses();
    distinguish_pinkTiles();
    setTileWalls();
    setUpNodes();
}

Map::~Map()
{
    for(auto & item: tiles)
    {
        for(auto & i: item)
        {
            delete i;
        }
    }
    for(auto & item: walls)
    {
        delete item;
    }
}

void Map::setUpTiles()
{
    sf::Vector2f vector(0, 0);
    sf::Color gray = sf::Color(97, 119, 122, 50);
    sf::Color blue = sf::Color(57, 171, 191, 50);
    unsigned int length = Tile(sf::Vector2f(0, 0)).getLength();
    for(int index = 0; index < mapLength / length; ++index)
    {
        for(int index2 = 0; index2 < mapWidth / length; ++index2)
        {
            vector.x = index2 * length;
            vector.y = (index + 3) * length;
            if(index % 2 == 0)
            {
                if(index2 % 2 == 0)
                {
                    tiles[index][index2] = new Tile(true, false, false, false, vector, gray);
                }
                else if(index2 % 2 == 1)
                {
                    tiles[index][index2] = new Tile(true, false, false, false, vector, blue);
                }
            }
            else if(index % 2 == 1)
            {
                if(index2 % 2 == 0)
                {
                    tiles[index][index2] = new Tile(true, false, false, false, vector, blue);
                }
                else if(index2 % 2 == 1)
                {
                    tiles[index][index2] = new Tile(true, false, false, false, vector, gray);
                }
            }
        }
    }
}

void Map::setUpWalls()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    //
    walls.push_back(new Wall(sf::Vector2f(0 * length, 13 * length), sf::Vector2f(0 * length, 3 * length), sf::Vector2f(28 * length, 3 * length)));
    setWallPoses(sf::Vector2f(0 * length, 13 * length), sf::Vector2f(0 * length, 3 * length), sf::Vector2f(28 * length, 3 * length));
    //
    walls.push_back(new Wall(sf::Vector2f(28 * length, 3 * length), sf::Vector2f(28 * length, 13 * length + 2), sf::Vector2f(23 * length, 13 * length + 2)));
    setWallPoses(sf::Vector2f(28 * length, 3 * length), sf::Vector2f(28 * length, 13 * length + 2), sf::Vector2f(23 * length, 13 * length + 2));

    walls.push_back(new Wall(sf::Vector2f(23 * length, 13 * length), sf::Vector2f(23 * length, 16 * length), sf::Vector2f(28 * length, 16 * length)));
    setWallPoses(sf::Vector2f(23 * length, 13 * length), sf::Vector2f(23 * length, 16 * length), sf::Vector2f(28 * length, 16 * length));

    walls.push_back(new Wall(sf::Vector2f(23 * length, 22 * length), sf::Vector2f(23 * length, 19 * length), sf::Vector2f(28 * length, 19 * length)));
    setWallPoses(sf::Vector2f(23 * length, 22 * length), sf::Vector2f(23 * length, 19 * length), sf::Vector2f(28 * length, 19 * length));

    walls.push_back(new Wall(sf::Vector2f(28 * length, 34 * length), sf::Vector2f(28 * length, 22 * length - 2), sf::Vector2f(23 * length, 22 * length - 2)));
    setWallPoses(sf::Vector2f(28 * length, 34 * length), sf::Vector2f(28 * length, 22 * length - 2), sf::Vector2f(23 * length, 22 * length - 2));

    walls.push_back(new Wall(sf::Vector2f(0 * length, 22 * length), sf::Vector2f(0 * length, 34 * length), sf::Vector2f(28 * length, 34 * length)));
    setWallPoses(sf::Vector2f(0 * length, 22 * length), sf::Vector2f(0 * length, 34 * length), sf::Vector2f(28 * length, 34 * length));

    walls.push_back(new Wall(sf::Vector2f(5 * length, 19 * length), sf::Vector2f(5 * length, 22 * length), sf::Vector2f(0 * length, 22 * length)));
    setWallPoses(sf::Vector2f(5 * length, 19 * length), sf::Vector2f(5 * length, 22 * length), sf::Vector2f(0 * length, 22 * length));

    walls.push_back(new Wall(sf::Vector2f(0 * length, 19 * length), sf::Vector2f(5 * length, 19 * length)));
    setWallPoses(sf::Vector2f(0 * length, 19 * length), sf::Vector2f(5 * length, 19 * length));

    walls.push_back(new Wall(sf::Vector2f(0 * length, 16 * length - 2), sf::Vector2f(5 * length, 16 * length - 2)));
    setWallPoses(sf::Vector2f(0 * length, 16 * length - 2), sf::Vector2f(5 * length, 16 * length - 2));

    walls.push_back(new Wall(sf::Vector2f(5 * length, 16 * length), sf::Vector2f(5 * length, 13 * length), sf::Vector2f(0 * length, 13 * length)));
    setWallPoses(sf::Vector2f(5 * length, 16 * length), sf::Vector2f(5 * length, 13 * length), sf::Vector2f(0 * length, 13 * length));


    // //
    walls.push_back(new Wall(sf::Vector2f(0 * length + 5, 27 * length + 10), sf::Vector2f(0 * length + 5, 22 * length + 3), sf::Vector2f(5 * length + 5, 22 * length + 3)));
    setWallPoses(sf::Vector2f(0 * length + 5, 27 * length + 10), sf::Vector2f(0 * length + 5, 22 * length + 3), sf::Vector2f(5 * length + 5, 22 * length + 3));

    walls.push_back(new Wall(sf::Vector2f(2 * length + 8, 28 * length + 8), sf::Vector2f(2 * length + 8, 27 * length + 10), sf::Vector2f(0 * length + 5, 27 * length + 10)));
    setWallPoses(sf::Vector2f(2 * length + 8, 28 * length + 8), sf::Vector2f(2 * length + 8, 27 * length + 10), sf::Vector2f(0 * length + 5, 27 * length + 10));

    walls.push_back(new Wall(sf::Vector2f(0 * length + 5, 34 * length - 5), sf::Vector2f(0 * length + 5, 28 * length + 8), sf::Vector2f(2 * length + 8, 28 * length + 8)));
    setWallPoses(sf::Vector2f(0 * length + 5, 34 * length - 5), sf::Vector2f(0 * length + 5, 28 * length + 8), sf::Vector2f(2 * length + 8, 28 * length + 8));

    walls.push_back(new Wall(sf::Vector2f(28 * length - 5, 28 * length + 8), sf::Vector2f(28 * length - 5, 34 * length - 5), sf::Vector2f(0 * length + 5, 34 * length - 5)));
    setWallPoses(sf::Vector2f(28 * length - 5, 28 * length + 8), sf::Vector2f(28 * length - 5, 34 * length - 5), sf::Vector2f(0 * length + 5, 34 * length - 5));

    walls.push_back(new Wall(sf::Vector2f(25 * length + 10, 27 * length + 12), sf::Vector2f(25 * length + 10, 28 * length + 10), sf::Vector2f(28 * length - 7, 28 * length + 10)));
    setWallPoses(sf::Vector2f(25 * length + 10, 27 * length + 12), sf::Vector2f(25 * length + 10, 28 * length + 10), sf::Vector2f(28 * length - 7, 28 * length + 10));

    walls.push_back(new Wall(sf::Vector2f(28 * length - 5, 22 * length + 5), sf::Vector2f(28 * length - 5, 27 * length + 12), sf::Vector2f(25 * length + 10, 27 * length + 12)));
    setWallPoses(sf::Vector2f(28 * length - 5, 22 * length + 5), sf::Vector2f(28 * length - 5, 27 * length + 12), sf::Vector2f(25 * length + 10, 27 * length + 12));

    walls.push_back(new Wall(sf::Vector2f(22 * length + 15, 18 * length + 15), sf::Vector2f(22 * length + 15, 22 * length + 5), sf::Vector2f(28 * length - 5, 22 * length + 5)));
    setWallPoses(sf::Vector2f(22 * length + 15, 18 * length + 15), sf::Vector2f(22 * length + 15, 22 * length + 5), sf::Vector2f(28 * length - 5, 22 * length + 5));

    walls.push_back(new Wall(sf::Vector2f(22 * length + 15, 18 * length + 15), sf::Vector2f(28 * length, 18 * length + 15)));
    setWallPoses(sf::Vector2f(22 * length + 15, 18 * length + 15), sf::Vector2f(28 * length, 18 * length + 15));

    walls.push_back(new Wall(sf::Vector2f(5 * length + 5, 22 * length + 5), sf::Vector2f(5 * length + 5, 18 * length + 15), sf::Vector2f(0 * length, 18 * length + 15)));
    setWallPoses(sf::Vector2f(5 * length + 5, 22 * length + 5), sf::Vector2f(5 * length + 5, 18 * length + 15), sf::Vector2f(0 * length, 18 * length + 15));

    walls.push_back(new Wall(sf::Vector2f(5 * length + 5, 12 * length + 15), sf::Vector2f(5 * length + 5, 16 * length + 5), sf::Vector2f(0 * length, 16 * length + 5)));
    setWallPoses(sf::Vector2f(5 * length + 5, 12 * length + 15), sf::Vector2f(5 * length + 5, 16 * length + 5), sf::Vector2f(0 * length, 16 * length + 5));

    walls.push_back(new Wall(sf::Vector2f(22 * length + 15, 12 * length + 15), sf::Vector2f(22 * length + 15, 16 * length + 5), sf::Vector2f(28 * length, 16 * length + 5)));
    setWallPoses(sf::Vector2f(22 * length + 15, 12 * length + 15), sf::Vector2f(22 * length + 15, 16 * length + 5), sf::Vector2f(28 * length, 16 * length + 5));

    walls.push_back(new Wall(sf::Vector2f(0 * length + 5, 3 * length + 5), sf::Vector2f(0 * length + 5, 12 * length + 17), sf::Vector2f(5 * length + 5, 12 * length + 17)));
    setWallPoses(sf::Vector2f(0 * length + 5, 3 * length + 5), sf::Vector2f(0 * length + 5, 12 * length + 17), sf::Vector2f(5 * length + 5, 12 * length + 17));

    walls.push_back(new Wall(sf::Vector2f(28 * length - 5, 3 * length + 5), sf::Vector2f(28 * length - 5, 12 * length + 17), sf::Vector2f(22 * length + 15, 12 * length + 17)));
    setWallPoses(sf::Vector2f(28 * length - 5, 3 * length + 5), sf::Vector2f(28 * length - 5, 12 * length + 17), sf::Vector2f(22 * length + 15, 12 * length + 17));

    walls.push_back(new Wall(sf::Vector2f(13 * length + 12, 7 * length + 5), sf::Vector2f(13 * length + 12, 3 * length + 5), sf::Vector2f(0 * length + 5, 3 * length + 5)));
    setWallPoses(sf::Vector2f(13 * length + 12, 7 * length + 5), sf::Vector2f(13 * length + 12, 3 * length + 5), sf::Vector2f(0 * length + 5, 3 * length + 5));

    walls.push_back(new Wall(sf::Vector2f(14 * length + 8, 7 * length + 5), sf::Vector2f(14 * length + 8, 3 * length + 5), sf::Vector2f(28 * length - 5, 3 * length + 5)));
    setWallPoses(sf::Vector2f(14 * length + 8, 7 * length + 5), sf::Vector2f(14 * length + 8, 3 * length + 5), sf::Vector2f(28 * length - 5, 3 * length + 5));

    walls.push_back(new Wall(sf::Vector2f(13 * length + 12, 7 * length + 5), sf::Vector2f(14 * length + 8, 7 * length + 5)));
    setWallPoses(sf::Vector2f(13 * length + 12, 7 * length + 5), sf::Vector2f(14 * length + 8, 7 * length + 5));

    // //now let's make the internal walls :(

    walls.push_back(new Wall(sf::Vector2f(2 * length + length / 2, 5 * length + length / 2), sf::Vector2f(2 * length + length / 2, 7 * length + length / 2), sf::Vector2f(5 * length + length / 2, 7 * length + length / 2)));
    setWallPoses(sf::Vector2f(2 * length + length / 2, 5 * length + length / 2), sf::Vector2f(2 * length + length / 2, 7 * length + length / 2), sf::Vector2f(5 * length + length / 2, 7 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(5 * length + length / 2, 7 * length + length / 2), sf::Vector2f(5 * length + length / 2, 5 * length + length / 2), sf::Vector2f(2 * length + length / 2, 5 * length + length / 2)));
    setWallPoses(sf::Vector2f(5 * length + length / 2, 7 * length + length / 2), sf::Vector2f(5 * length + length / 2, 5 * length + length / 2), sf::Vector2f(2 * length + length / 2, 5 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(7 * length + length / 2, 5 * length + length / 2), sf::Vector2f(7 * length + length / 2, 7 * length + length / 2 ), sf::Vector2f(11 * length + length / 2, 7 * length + length / 2)));
    setWallPoses(sf::Vector2f(7 * length + length / 2, 5 * length + length / 2), sf::Vector2f(7 * length + length / 2, 7 * length + length / 2 ), sf::Vector2f(11 * length + length / 2, 7 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length + length / 2, 7 * length + length / 2), sf::Vector2f(11 * length + length / 2, 5 * length + length / 2), sf::Vector2f(7 * length + length / 2, 5 * length + length / 2)));
    setWallPoses(sf::Vector2f(11 * length + length / 2, 7 * length + length / 2), sf::Vector2f(11 * length + length / 2, 5 * length + length / 2), sf::Vector2f(7 * length + length / 2, 5 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(16 * length + length / 2, 5 * length + length / 2), sf::Vector2f(16 * length + length / 2, 7 * length + length / 2), sf::Vector2f(20 * length + length / 2, 7 * length + length / 2)));
    setWallPoses(sf::Vector2f(16 * length + length / 2, 5 * length + length / 2), sf::Vector2f(16 * length + length / 2, 7 * length + length / 2), sf::Vector2f(20 * length + length / 2, 7 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(20 * length + length / 2, 7 * length + length / 2), sf::Vector2f(20 * length + length / 2, 5 * length + length / 2), sf::Vector2f(16 * length + length / 2, 5 * length + length / 2)));
    setWallPoses(sf::Vector2f(20 * length + length / 2, 7 * length + length / 2), sf::Vector2f(20 * length + length / 2, 5 * length + length / 2), sf::Vector2f(16 * length + length / 2, 5 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(22 * length + length / 2, 5 * length + length / 2), sf::Vector2f(22 * length + length / 2, 7 * length + length / 2 ), sf::Vector2f(25 * length + length / 2, 7 * length + length / 2)));
    setWallPoses(sf::Vector2f(22 * length + length / 2, 5 * length + length / 2), sf::Vector2f(22 * length + length / 2, 7 * length + length / 2 ), sf::Vector2f(25 * length + length / 2, 7 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(25 * length + length / 2, 7 * length + length / 2), sf::Vector2f(25 * length + length / 2, 5 * length + length / 2), sf::Vector2f(22 * length + length / 2, 5 * length + length / 2)));
    setWallPoses(sf::Vector2f(25 * length + length / 2, 7 * length + length / 2), sf::Vector2f(25 * length + length / 2, 5 * length + length / 2), sf::Vector2f(22 * length + length / 2, 5 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(2 * length + length / 2, 9 * length + length / 2), sf::Vector2f(2 * length + length / 2, 10 * length + length / 2), sf::Vector2f(5 * length + length / 2, 10 * length + length / 2)));
    setWallPoses(sf::Vector2f(2 * length + length / 2, 9 * length + length / 2), sf::Vector2f(2 * length + length / 2, 10 * length + length / 2), sf::Vector2f(5 * length + length / 2, 10 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(5 * length + length / 2, 10 * length + length / 2), sf::Vector2f(5 * length + length / 2, 9 * length + length / 2), sf::Vector2f(2 * length + length / 2, 9 * length + length / 2)));
    setWallPoses(sf::Vector2f(5 * length + length / 2, 10 * length + length / 2), sf::Vector2f(5 * length + length / 2, 9 * length + length / 2), sf::Vector2f(2 * length + length / 2, 9 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(22 * length + length / 2, 9 * length + length / 2), sf::Vector2f(22 * length + length / 2, 10 * length + length / 2), sf::Vector2f(25 * length + length / 2, 10 * length + length / 2)));
    setWallPoses(sf::Vector2f(22 * length + length / 2, 9 * length + length / 2), sf::Vector2f(22 * length + length / 2, 10 * length + length / 2), sf::Vector2f(25 * length + length / 2, 10 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(25 * length + length / 2, 10 * length + length / 2), sf::Vector2f(25 * length + length / 2, 9 * length + length / 2), sf::Vector2f(22 * length + length / 2, 9 * length + length / 2)));
    setWallPoses(sf::Vector2f(25 * length + length / 2, 10 * length + length / 2), sf::Vector2f(25 * length + length / 2, 9 * length + length / 2), sf::Vector2f(22 * length + length / 2, 9 * length + length / 2));

    walls.push_back(new Wall(sf::Vector2f(10 * length + length / 2, 9 * length + length / 2), sf::Vector2f(10 * length + length / 2, 10 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 10 * length + length / 2)));
    setWallPoses(sf::Vector2f(10 * length + length / 2, 9 * length + length / 2), sf::Vector2f(10 * length + length / 2, 10 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 10 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(13 * length + length / 2, 10 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 13 * length + length / 2), sf::Vector2f(14 * length + length / 2, 13 * length + length / 2)));
    setWallPoses(sf::Vector2f(13 * length + length / 2, 10 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 13 * length + length / 2), sf::Vector2f(14 * length + length / 2, 13 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(14 * length + length / 2 - 2, 13 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 10 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 10 * length + length / 2 - 2)));
    setWallPoses(sf::Vector2f(14 * length + length / 2 - 2, 13 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 10 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 10 * length + length / 2 - 2));
    walls.push_back(new Wall(sf::Vector2f(17 * length + length / 2, 10 * length + length / 2), sf::Vector2f(17 * length + length / 2, 9 * length + length / 2), sf::Vector2f(10 * length + length / 2, 9 * length + length / 2)));
    setWallPoses(sf::Vector2f(17 * length + length / 2, 10 * length + length / 2), sf::Vector2f(17 * length + length / 2, 9 * length + length / 2), sf::Vector2f(10 * length + length / 2, 9 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(10 * length + length / 2, 21 * length + length / 2), sf::Vector2f(10 * length + length / 2, 22 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 22 * length + length / 2)));
    setWallPoses(sf::Vector2f(10 * length + length / 2, 21 * length + length / 2), sf::Vector2f(10 * length + length / 2, 22 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 22 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(13 * length + length / 2, 22 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 25 * length + length / 2), sf::Vector2f(14 * length + length / 2, 25 * length + length / 2)));
    setWallPoses(sf::Vector2f(13 * length + length / 2, 22 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 25 * length + length / 2), sf::Vector2f(14 * length + length / 2, 25 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(14 * length + length / 2 - 2, 25 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 22 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 22 * length + length / 2 - 2)));
    setWallPoses(sf::Vector2f(14 * length + length / 2 - 2, 25 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 22 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 22 * length + length / 2 - 2));
    walls.push_back(new Wall(sf::Vector2f(17 * length + length / 2, 22 * length + length / 2), sf::Vector2f(17 * length + length / 2, 21 * length + length / 2), sf::Vector2f(10 * length + length / 2, 21 * length + length / 2)));
    setWallPoses(sf::Vector2f(17 * length + length / 2, 22 * length + length / 2), sf::Vector2f(17 * length + length / 2, 21 * length + length / 2), sf::Vector2f(10 * length + length / 2, 21 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(10 * length + length / 2, 27 * length + length / 2), sf::Vector2f(10 * length + length / 2, 28 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 28 * length + length / 2)));
    setWallPoses(sf::Vector2f(10 * length + length / 2, 27 * length + length / 2), sf::Vector2f(10 * length + length / 2, 28 * length + length / 2), sf::Vector2f(13 * length+ length / 2, 28 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(13 * length + length / 2, 28 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 31 * length + length / 2), sf::Vector2f(14 * length + length / 2, 31 * length + length / 2)));
    setWallPoses(sf::Vector2f(13 * length + length / 2, 28 * length + length / 2 - 2), sf::Vector2f(13 * length + length / 2, 31 * length + length / 2), sf::Vector2f(14 * length + length / 2, 31 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(14 * length + length / 2 - 2, 31 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 28 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 28 * length + length / 2 - 2)));
    setWallPoses(sf::Vector2f(14 * length + length / 2 - 2, 31 * length + length / 2 - 2), sf::Vector2f(14 * length + length / 2 - 2, 28 * length + length / 2 - 2), sf::Vector2f(17 * length + length / 2, 28 * length + length / 2 - 2));
    walls.push_back(new Wall(sf::Vector2f(17 * length + length / 2, 28 * length + length / 2), sf::Vector2f(17 * length + length / 2, 27 * length + length / 2), sf::Vector2f(10 * length + length / 2, 27 * length + length / 2)));
    setWallPoses(sf::Vector2f(17 * length + length / 2, 28 * length + length / 2), sf::Vector2f(17 * length + length / 2, 27 * length + length / 2), sf::Vector2f(10 * length + length / 2, 27 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(7 * length + length / 2, 9 * length + length / 2), sf::Vector2f(7 * length + length / 2, 16 * length + length / 2), sf::Vector2f(8 * length + length / 2, 16 * length + length / 2)));
    setWallPoses(sf::Vector2f(7 * length + length / 2, 9 * length + length / 2), sf::Vector2f(7 * length + length / 2, 16 * length + length / 2), sf::Vector2f(8 * length + length / 2, 16 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(8 * length + length / 2 - 2, 16 * length + length / 2 - 2), sf::Vector2f(8 * length + length / 2 - 2, 13 * length + length / 2 - 2), sf::Vector2f(11 * length + length / 2 - 2, 13 * length + length / 2 - 2)));
    setWallPoses(sf::Vector2f(8 * length + length / 2 - 2, 16 * length + length / 2 - 2), sf::Vector2f(8 * length + length / 2 - 2, 13 * length + length / 2 - 2), sf::Vector2f(11 * length + length / 2 - 2, 13 * length + length / 2 - 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length + length / 2, 13 * length + length / 2), sf::Vector2f(11 * length + length / 2, 12 * length + length / 2), sf::Vector2f(8 * length + length / 2, 12 * length + length / 2)));
    setWallPoses(sf::Vector2f(11 * length + length / 2, 13 * length + length / 2), sf::Vector2f(11 * length + length / 2, 12 * length + length / 2), sf::Vector2f(8 * length + length / 2, 12 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(8 * length + length / 2, 12 * length + length / 2 + 2), sf::Vector2f(8 * length + length / 2, 9 * length + length / 2), sf::Vector2f(7 * length + length / 2, 9 * length + length / 2)));
    setWallPoses(sf::Vector2f(8 * length + length / 2, 12 * length + length / 2 + 2), sf::Vector2f(8 * length + length / 2, 9 * length + length / 2), sf::Vector2f(7 * length + length / 2, 9 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(20 * length + length / 2, 9 * length + length / 2), sf::Vector2f(20 * length + length / 2, 16 * length + length / 2), sf::Vector2f(19 * length + length / 2, 16 * length + length / 2)));
    setWallPoses(sf::Vector2f(20 * length + length / 2, 9 * length + length / 2), sf::Vector2f(20 * length + length / 2, 16 * length + length / 2), sf::Vector2f(19 * length + length / 2, 16 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(19 * length + length / 2 + 2, 16 * length + length / 2 - 2), sf::Vector2f(19 * length + length / 2 + 2, 13 * length + length / 2 - 2), sf::Vector2f(16 * length + length / 2 + 2, 13 * length + length / 2 - 2)));
    setWallPoses(sf::Vector2f(19 * length + length / 2 + 2, 16 * length + length / 2 - 2), sf::Vector2f(19 * length + length / 2 + 2, 13 * length + length / 2 - 2), sf::Vector2f(16 * length + length / 2 + 2, 13 * length + length / 2 - 2));
    walls.push_back(new Wall(sf::Vector2f(16 * length + length / 2, 13 * length + length / 2), sf::Vector2f(16 * length + length / 2, 12 * length + length / 2), sf::Vector2f(19 * length + length / 2, 12 * length + length / 2)));
    setWallPoses(sf::Vector2f(16 * length + length / 2, 13 * length + length / 2), sf::Vector2f(16 * length + length / 2, 12 * length + length / 2), sf::Vector2f(19 * length + length / 2, 12 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(19 * length + length / 2, 12 * length + length / 2 + 2), sf::Vector2f(19 * length + length / 2, 9 * length + length / 2), sf::Vector2f(20 * length + length / 2, 9 * length + length / 2)));
    setWallPoses(sf::Vector2f(19 * length + length / 2, 12 * length + length / 2 + 2), sf::Vector2f(19 * length + length / 2, 9 * length + length / 2), sf::Vector2f(20 * length + length / 2, 9 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(7 * length + length / 2, 18 * length + length / 2), sf::Vector2f(7 * length + length / 2, 22 * length + length / 2), sf::Vector2f(8 * length + length / 2, 22 * length + length / 2)));
    setWallPoses(sf::Vector2f(7 * length + length / 2, 18 * length + length / 2), sf::Vector2f(7 * length + length / 2, 22 * length + length / 2), sf::Vector2f(8 * length + length / 2, 22 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(8 * length + length / 2, 22 * length + length / 2), sf::Vector2f(8 * length + length / 2, 18 * length + length / 2), sf::Vector2f(7 * length + length / 2, 18 * length + length / 2)));
    setWallPoses(sf::Vector2f(8 * length + length / 2, 22 * length + length / 2), sf::Vector2f(8 * length + length / 2, 18 * length + length / 2), sf::Vector2f(7 * length + length / 2, 18 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(19 * length + length / 2, 18 * length + length / 2), sf::Vector2f(19 * length + length / 2, 22 * length + length / 2), sf::Vector2f(20 * length + length / 2, 22 * length + length / 2)));
    setWallPoses(sf::Vector2f(19 * length + length / 2, 18 * length + length / 2), sf::Vector2f(19 * length + length / 2, 22 * length + length / 2), sf::Vector2f(20 * length + length / 2, 22 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(20 * length + length / 2, 22 * length + length / 2), sf::Vector2f(20 * length + length / 2, 18 * length + length / 2), sf::Vector2f(19 * length + length / 2, 18 * length + length / 2)));
    setWallPoses(sf::Vector2f(20 * length + length / 2, 22 * length + length / 2), sf::Vector2f(20 * length + length / 2, 18 * length + length / 2), sf::Vector2f(19 * length + length / 2, 18 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(7 * length + length / 2, 24 * length + length / 2), sf::Vector2f(7 * length + length / 2, 25 * length + length / 2), sf::Vector2f(11 * length + length / 2, 25 * length + length / 2)));
    setWallPoses(sf::Vector2f(7 * length + length / 2, 24 * length + length / 2), sf::Vector2f(7 * length + length / 2, 25 * length + length / 2), sf::Vector2f(11 * length + length / 2, 25 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length + length / 2, 25 * length + length / 2), sf::Vector2f(11 * length + length / 2, 24 * length + length / 2), sf::Vector2f(7 * length + length / 2, 24 * length + length / 2)));
    setWallPoses(sf::Vector2f(11 * length + length / 2, 25 * length + length / 2), sf::Vector2f(11 * length + length / 2, 24 * length + length / 2), sf::Vector2f(7 * length + length / 2, 24 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(16 * length + length / 2, 24 * length + length / 2), sf::Vector2f(16 * length + length / 2, 25 * length + length / 2), sf::Vector2f(20 * length + length / 2, 25 * length + length / 2)));
    setWallPoses(sf::Vector2f(16 * length + length / 2, 24 * length + length / 2), sf::Vector2f(16 * length + length / 2, 25 * length + length / 2), sf::Vector2f(20 * length + length / 2, 25 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(20 * length + length / 2, 25 * length + length / 2), sf::Vector2f(20 * length + length / 2, 24 * length + length / 2), sf::Vector2f(16 * length + length / 2, 24 * length + length / 2)));
    setWallPoses(sf::Vector2f(20 * length + length / 2, 25 * length + length / 2), sf::Vector2f(20 * length + length / 2, 24 * length + length / 2), sf::Vector2f(16 * length + length / 2, 24 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(2 * length + length / 2, 25 * length + length / 2), sf::Vector2f(2 * length + length / 2, 24 * length + length / 2), sf::Vector2f(5 * length + length / 2, 24 * length + length / 2)));
    setWallPoses(sf::Vector2f(2 * length + length / 2, 25 * length + length / 2), sf::Vector2f(2 * length + length / 2, 24 * length + length / 2), sf::Vector2f(5 * length + length / 2, 24 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(5 * length + length / 2, 24 * length + length / 2), sf::Vector2f(5 * length + length / 2, 28 * length + length / 2), sf::Vector2f(4 * length + length / 2, 28 * length + length / 2)));
    setWallPoses(sf::Vector2f(5 * length + length / 2, 24 * length + length / 2), sf::Vector2f(5 * length + length / 2, 28 * length + length / 2), sf::Vector2f(4 * length + length / 2, 28 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(4 * length + length / 2, 28 * length + length / 2), sf::Vector2f(4 * length + length / 2, 25 * length + length / 2), sf::Vector2f(2 * length + length / 2, 25 * length + length / 2)));
    setWallPoses(sf::Vector2f(4 * length + length / 2, 28 * length + length / 2), sf::Vector2f(4 * length + length / 2, 25 * length + length / 2), sf::Vector2f(2 * length + length / 2, 25 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(25 * length + length / 2, 25 * length + length / 2), sf::Vector2f(25 * length + length / 2, 24 * length + length / 2), sf::Vector2f(22 * length + length / 2, 24 * length + length / 2)));
    setWallPoses(sf::Vector2f(25 * length + length / 2, 25 * length + length / 2), sf::Vector2f(25 * length + length / 2, 24 * length + length / 2), sf::Vector2f(22 * length + length / 2, 24 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(22 * length + length / 2, 24 * length + length / 2), sf::Vector2f(22 * length + length / 2, 28 * length + length / 2), sf::Vector2f(23 * length + length / 2, 28 * length + length / 2)));
    setWallPoses(sf::Vector2f(22 * length + length / 2, 24 * length + length / 2), sf::Vector2f(22 * length + length / 2, 28 * length + length / 2), sf::Vector2f(23 * length + length / 2, 28 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(23 * length + length / 2, 28 * length + length / 2), sf::Vector2f(23 * length + length / 2, 25 * length + length / 2), sf::Vector2f(25 * length + length / 2, 25 * length + length / 2)));
    setWallPoses(sf::Vector2f(23 * length + length / 2, 28 * length + length / 2), sf::Vector2f(23 * length + length / 2, 25 * length + length / 2), sf::Vector2f(25 * length + length / 2, 25 * length + length / 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(8 * length + length / 2, 30 * length + length / 2), sf::Vector2f(8 * length + length / 2, 27 * length + length / 2), sf::Vector2f(7 * length + length / 2, 27 * length + length / 2)));
    setWallPoses(sf::Vector2f(8 * length + length / 2, 30 * length + length / 2), sf::Vector2f(8 * length + length / 2, 27 * length + length / 2), sf::Vector2f(7 * length + length / 2, 27 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length + length / 2, 31 * length + length / 2), sf::Vector2f(11 * length + length / 2, 30 * length + length / 2), sf::Vector2f(8 * length + length / 2 - 2, 30 * length + length / 2)));
    setWallPoses(sf::Vector2f(11 * length + length / 2, 31 * length + length / 2), sf::Vector2f(11 * length + length / 2, 30 * length + length / 2), sf::Vector2f(8 * length + length / 2 - 2, 30 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(2 * length + length / 2, 30 * length + length / 2), sf::Vector2f(2 * length + length / 2, 31 * length + length / 2), sf::Vector2f(11 * length + length / 2, 31 * length + length / 2)));
    setWallPoses(sf::Vector2f(2 * length + length / 2, 30 * length + length / 2), sf::Vector2f(2 * length + length / 2, 31 * length + length / 2), sf::Vector2f(11 * length + length / 2, 31 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(7 * length + length / 2, 27 * length + length / 2), sf::Vector2f(7 * length + length / 2, 30 * length + length / 2 + 2), sf::Vector2f(2 * length + length / 2, 30 * length + length / 2 + 2)));
    setWallPoses(sf::Vector2f(7 * length + length / 2, 27 * length + length / 2), sf::Vector2f(7 * length + length / 2, 30 * length + length / 2 + 2), sf::Vector2f(2 * length + length / 2, 30 * length + length / 2 + 2));
    // //
    walls.push_back(new Wall(sf::Vector2f(19 * length + length / 2, 30 * length + length / 2), sf::Vector2f(19 * length + length / 2, 27 * length + length / 2), sf::Vector2f(20 * length + length / 2, 27 * length + length / 2)));
    setWallPoses(sf::Vector2f(19 * length + length / 2, 30 * length + length / 2), sf::Vector2f(19 * length + length / 2, 27 * length + length / 2), sf::Vector2f(20 * length + length / 2, 27 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(16 * length + length / 2, 31 * length + length / 2), sf::Vector2f(16 * length + length / 2, 30 * length + length / 2), sf::Vector2f(19 * length + length / 2 + 2, 30 * length + length / 2)));
    setWallPoses(sf::Vector2f(16 * length + length / 2, 31 * length + length / 2), sf::Vector2f(16 * length + length / 2, 30 * length + length / 2), sf::Vector2f(19 * length + length / 2 + 2, 30 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(25 * length + length / 2, 30 * length + length / 2), sf::Vector2f(25 * length + length / 2, 31 * length + length / 2), sf::Vector2f(16 * length + length / 2, 31 * length + length / 2)));
    setWallPoses(sf::Vector2f(25 * length + length / 2, 30 * length + length / 2), sf::Vector2f(25 * length + length / 2, 31 * length + length / 2), sf::Vector2f(16 * length + length / 2, 31 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(20 * length + length / 2, 27 * length + length / 2), sf::Vector2f(20 * length + length / 2, 30 * length + length / 2 + 2), sf::Vector2f(25 * length + length / 2, 30 * length + length / 2 + 2)));
    setWallPoses(sf::Vector2f(20 * length + length / 2, 27 * length + length / 2), sf::Vector2f(20 * length + length / 2, 30 * length + length / 2 + 2), sf::Vector2f(25 * length + length / 2, 30 * length + length / 2 + 2));

    // //ghosts' house
    walls.push_back(new Wall(sf::Vector2f(10 * length + length / 2, 15 * length + length / 2), sf::Vector2f(10 * length + length / 2, 19 * length + length / 2), sf::Vector2f(17 * length + length / 2, 19 * length + length / 2)));
    setWallPoses(sf::Vector2f(10 * length + length / 2, 15 * length + length / 2), sf::Vector2f(10 * length + length / 2, 19 * length + length / 2), sf::Vector2f(17 * length + length / 2, 19 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(17 * length + length / 2, 19 * length + length / 2), sf::Vector2f(17 * length + length / 2, 15 * length + length / 2), sf::Vector2f(15 * length, 15 * length + length / 2)));
    setWallPoses(sf::Vector2f(17 * length + length / 2, 19 * length + length / 2), sf::Vector2f(17 * length + length / 2, 15 * length + length / 2), sf::Vector2f(15 * length, 15 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(10 * length + length / 2, 15 * length + length / 2), sf::Vector2f(13 * length, 15 * length + length / 2)));
    setWallPoses(sf::Vector2f(10 * length + length / 2, 15 * length + length / 2), sf::Vector2f(13 * length, 15 * length + length / 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length - 2, 16 * length), sf::Vector2f(11 * length - 2, 19 * length + 2), sf::Vector2f(17 * length, 19 * length + 2)));
    setWallPoses(sf::Vector2f(11 * length - 2, 16 * length), sf::Vector2f(11 * length - 2, 19 * length + 2), sf::Vector2f(17 * length, 19 * length + 2));
    walls.push_back(new Wall(sf::Vector2f(17 * length + 2, 19 * length + 2), sf::Vector2f(17 * length + 2, 16 * length - 2), sf::Vector2f(15 * length, 16 * length - 2)));
    setWallPoses(sf::Vector2f(17 * length + 2, 19 * length + 2), sf::Vector2f(17 * length + 2, 16 * length - 2), sf::Vector2f(15 * length, 16 * length - 2));
    walls.push_back(new Wall(sf::Vector2f(11 * length - 2, 16 * length - 2), sf::Vector2f(13 * length, 16 * length - 2)));
    setWallPoses(sf::Vector2f(11 * length - 2, 16 * length - 2), sf::Vector2f(13 * length, 16 * length - 2));
    walls.push_back(new Wall(sf::Vector2f(13 * length - 2, 15 * length + length / 2), sf::Vector2f(13 * length - 2, 16 * length - 2)));
    setWallPoses(sf::Vector2f(13 * length - 2, 15 * length + length / 2), sf::Vector2f(13 * length - 2, 16 * length - 2));
    walls.push_back(new Wall(sf::Vector2f(15 * length, 15 * length + length / 2), sf::Vector2f(15 * length, 16 * length - 2)));
    setWallPoses(sf::Vector2f(15 * length, 15 * length + length / 2), sf::Vector2f(15 * length, 16 * length - 2));
    walls.push_back(new Wall(sf::Vector2f(13 * length, 16 * length - 6), sf::Vector2f(15 * length, 16 * length - 6), sf::Color::White));
    // ghost should be able to pass the door do we won't consider it as a wall :(
    
    // setWallPoses(sf::Vector2f(13 * length, 16 * length - 6), sf::Vector2f(15 * length, 16 * length - 6));
}

void Map::setWallPoses(sf::Vector2f first, sf::Vector2f second, sf::Vector2f third)
{
    if(first.x == second.x && second.y == third.y && first.y < second.y && second.x < third.x)
    {
        // then it is going to look like this: |_
        std::cout << "I am here" << std::endl;
        std::cout << "_________________" << std::endl;
        std::cout << first;
        std::cout << second;
        std::cout << third;
        std::cout << "_________________" << std::endl;
        setWallPoses(first, second);
        second.x += 2;
        second.y -= 2;
        third.y -= 2;
        setWallPoses(second, third);
    }
    else if(first.x == second.x && second.y == third.y && first.y > second.y && second.x < third.x)
    {
        // then it is going to look like this: _
        //                                    |
        setWallPoses(second, third);
        second.y += 2;
        setWallPoses(second, first);
    }
    else if(first.x == second.x && second.y == third.y && first.y < second.y && second.x > third.x)
    {
        //then it is going to look like this: _|
        first.x -= 2;
        second.x -= 2;
        setWallPoses(first, second);
        third.y -= 2;
        second.y -= 2;
        setWallPoses(third, second);
    }
    else if(first.x == second.x && second.y == third.y && first.y > second.y && second.x > third.x)
    {
        //then it is going to look like this: _
        //                                    |
        first.x -= 2;
        second.x -= 2;
        setWallPoses(second, first);
        setWallPoses(third, second);
    }
}

void Map::setWallPoses(sf::Vector2f first, sf::Vector2f second)
{
    if(first.x == 560)
    {
        first.x -= 2;
    }
    if(second.x == 560)
    {
        second.x -= 2;
    }
    if(first.y == 680)
    {
        first.y -= 2;
    }
    if(second.y == 680)
    {
        second.y -= 2;
    }

    int length = Tile(sf::Vector2f(0, 0)).getLength();
    sf::Vector2f temp(0, 0);
    int reachPoint;
    if(second.x - first.x == 0)
    {
        if(second.y - first.y > 0)
        {
            temp.x = (int)first.x / length * length;
            temp.y = (int)first.y / length * length;
            if((int)second.y % length > 0)
            {
                reachPoint = (int)second.y / length * length;
            }
            else if((int)second.y % length == 0)
            {
                reachPoint = (int)second.y / length * length - 1 * length;
            }
            while(reachPoint + length != temp.y)
            {
                if(!wallPosExists(temp))
                {
                    wallsPoses.push_back(temp);
                }
                temp.y += length;
            }
        }
        else if(second.y - first.y < 0)
        {
            temp.x = (int)second.x / length * length;
            temp.y = (int)second.y / length * length;
            if((int)first.y % length > 0)
            {
                reachPoint = (int)first.y / length * length;
            }
            else if((int)first.y % length == 0)
            {
                reachPoint = (int)first.y / length * length - 1 * length;
            }
            while(reachPoint + length != temp.y)
            {
                if(!wallPosExists(temp))
                {
                    wallsPoses.push_back(temp);
                }
                temp.y += length;
            }
        }
    }
    else if(second.y - first.y == 0)
    {
        if(second.x - first.x > 0)
        {
            temp.x = (int)first.x / length * length;
            temp.y = (int)first.y / length * length;
            if((int)second.x % length > 0)
            {
                reachPoint = (int)second.x / length * length;
            }
            else if((int)second.x % length == 0)
            {
                reachPoint = (int)second.x / length * length - 1 * length;
            }
            while(reachPoint + length != temp.x)
            {
                if(!wallPosExists(temp))
                {
                    wallsPoses.push_back(temp);
                }
                temp.x += length;
            }
        }
        else if(second.x - first.x < 0)
        {
            temp.x = (int)second.x / length * length;
            temp.y = (int)second.y / length * length;
            if((int)first.x % length > 0)
            {
                reachPoint = (int)first.x / length * length;
            }
            else if((int)first.x % length == 0)
            {
                reachPoint = (int)first.x / length * length - 1 * length;
            }
            while(reachPoint + length != temp.x)
            {
                if(!wallPosExists(temp))
                {
                    wallsPoses.push_back(temp);
                }
                temp.x += length;
            }
        }
    }
    else
    {
        throw std::invalid_argument("Invalid Input for setting wall positions!\n");
    }
}

void Map::setRedPoses()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    redPoses.push_back(sf::Vector2f(11 * length, 14 * length));
    redPoses.push_back(sf::Vector2f(12 * length, 14 * length));
    redPoses.push_back(sf::Vector2f(13 * length, 14 * length));
    redPoses.push_back(sf::Vector2f(14 * length, 14 * length));
    redPoses.push_back(sf::Vector2f(15 * length, 14 * length));
    redPoses.push_back(sf::Vector2f(16 * length, 14 * length));

    redPoses.push_back(sf::Vector2f(11 * length, 26 * length));
    redPoses.push_back(sf::Vector2f(12 * length, 26 * length));
    redPoses.push_back(sf::Vector2f(13 * length, 26 * length));
    redPoses.push_back(sf::Vector2f(14 * length, 26 * length));
    redPoses.push_back(sf::Vector2f(15 * length, 26 * length));
    redPoses.push_back(sf::Vector2f(16 * length, 26 * length));
}

void Map::setPinkPoses()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();

    pinkPoses.push_back(sf::Vector2f(0 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(1 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(2 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(3 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(4 * length, 17 * length));

    pinkPoses.push_back(sf::Vector2f(23 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(24 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(25 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(26 * length, 17 * length));
    pinkPoses.push_back(sf::Vector2f(27 * length, 17 * length));
}

std::array<std::array<Tile *, 28>, 31> & Map::getTiles()
{
    return tiles;
}

std::vector<Wall *> & Map::getWalls()
{
    return walls;
}

bool Map::wallPosExists(sf::Vector2f curWall)
{
    for(auto const & item: wallsPoses)
    {
        if(item == curWall)
        {
            return true;
        }
    }

    return false;
}

const std::vector<sf::Vector2f> & Map::getWallPoses()
{
    return wallsPoses;
}

void Map::distinguish_tileWalls()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    for(auto item: wallsPoses)
    {
        item.x /= length;
        item.y /= length;
        item.y -= 3;

        tiles.at(item.y).at(item.x) -> getShape().setFillColor(sf::Color(245, 0, 237, 50));
        tiles.at(item.y).at(item.x) -> considerAsWall();
    }
}

void Map::distinguish_redTiles()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    for(auto item: redPoses)
    {
        item.x /= length;
        item.y /= length;
        item.y -= 3;

        tiles.at(item.y).at(item.x) -> getShape().setFillColor(sf::Color(252, 3, 3, 75));
        tiles.at(item.y).at(item.x) -> considerAsRed();
    }
}

void Map::distinguish_pinkTiles()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    for(auto item: pinkPoses)
    {
        item.x /= length;
        item.y /= length;
        item.y -= 3;//because there are three free tiles in above of
                    //the map for write text
        tiles.at(item.y).at(item.x) -> getShape().setFillColor(sf::Color(230, 16, 208, 100));
        tiles.at(item.y).at(item.x) -> considerAsPink();
    }
}

Tile & Map::get_nth_tile(sf::Vector2f pos)
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();

    pos.x /= length;
    pos.y /= length;
    pos.y -= 3;

    return *(tiles.at(pos.y).at(pos.x));
}

void Map::setTileWalls()
{
    for(auto const & item : wallsPoses)
    {
        tileWalls.push_back(&get_nth_tile(item));
    }
}

std::vector<Tile *> & Map::getTileWalls()
{
    return tileWalls;
}

void Map::setUpNodes()
{
    int length = Tile(sf::Vector2f(0, 0)).getLength();
    sf::RectangleShape node;
    node.setFillColor(sf::Color::White);
    node.setSize(sf::Vector2f(20, 20));

    node.setPosition(1 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 4 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 4 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 4 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 4 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 4 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 4 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 4 * length));
    nodes.push_back(node);

    //----

    node.setPosition(1 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 8 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 8 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 8 * length));
    nodes.push_back(node);

    //----

    node.setPosition(1 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 11 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 11 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 14 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 14 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 14 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 14 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 14 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 14 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 14 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 14 * length));
    nodes.push_back(node);

    //----

    node.setPosition(6 * length, 17 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 17 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 17 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 17 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 17 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 17 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 17 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 17 * length));
    nodes.push_back(node);

    //----

    node.setPosition(9 * length, 20 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 20 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 20 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 20 * length));
    nodes.push_back(node);

    //----

    node.setPosition(1 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 23 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 23 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 23 * length));
    nodes.push_back(node);

    //----

    node.setPosition(1 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(3 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(3 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 26 * length));
    nodes.push_back(node);    

    node.setPosition(18 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(24 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(24 * length, 26 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 26 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 26 * length));
    nodes.push_back(node);

    //----
    node.setPosition(1 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(3 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(3 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(6 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(6 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(9 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(9 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 29 * length));
    nodes.push_back(node);    

    node.setPosition(18 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(18 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(18 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(21 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(21 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(24 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(24 * length, 29 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 29 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 29 * length));
    nodes.push_back(node);

    //----

    node.setPosition(1 * length, 32 * length);
    nodePoses.push_back(sf::Vector2f(1 * length, 32 * length));
    nodes.push_back(node);

    node.setPosition(12 * length, 32 * length);
    nodePoses.push_back(sf::Vector2f(12 * length, 32 * length));
    nodes.push_back(node);

    node.setPosition(15 * length, 32 * length);
    nodePoses.push_back(sf::Vector2f(15 * length, 32 * length));
    nodes.push_back(node);

    node.setPosition(26 * length, 32 * length);
    nodePoses.push_back(sf::Vector2f(26 * length, 32 * length));
    nodes.push_back(node);
}


std::vector<sf::RectangleShape> & Map::get_nodes()
{
    return nodes;
}

std::pair<bool, sf::Vector2f> Map::is_on_node(sf::FloatRect bounds)
{
    sf::FloatRect nodeBounds;
    for(auto const & item: nodes)
    {
        nodeBounds = item.getGlobalBounds();
        if(bounds.intersects(nodeBounds))
        {
            // std::cout << "hell yeah!" << std::endl;
            if(nodeBounds.left - bounds.left < 1.68 && nodeBounds.left - bounds.left >= 0 && nodeBounds.top == bounds.top
            || nodeBounds.top - bounds.top < 1.68 && nodeBounds.top - bounds.top >= 0 && nodeBounds.left == bounds.left)
            {
                return {true, sf::Vector2f(item.getPosition())};
            }
        }
    }
    return {false, {0, 0}};
}