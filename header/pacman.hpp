#ifndef _PACMAN
#define _PACMAN

#include <SFML/Graphics.hpp>
#include <array>

class Pacman
{
    public:
        Pacman();
        void draw(sf::RenderTarget &);
        void set_direction(const sf::Vector2f &);
        sf::Vector2f get_direction();
        float get_speed();
        void set_position(float, float);
        sf::Vector2f get_position();
        void move(float);
        void move(sf::Vector2f);
        sf::FloatRect get_TileItIsOn_rect();
        void move_to_new_set_position();
        void set_velocity(sf::Vector2f);
        sf::Sprite sprite;
    private:
        sf::Vector2f pos;//position of tile the pacman is on
        sf::Vector2f dir;
        sf::Vector2f velocity;
        float speed = 100;
        sf::Texture texture;
        sf::RectangleShape tile_itIs_on;
        sf::RectangleShape center;
};

#endif // _PACMAN