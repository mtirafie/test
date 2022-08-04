#ifndef _GHOST
#define _GHOST


#include <SFML/Graphics.hpp>
class Ghost // abstract class
{
    public:
        virtual void decide_direction(sf::Vector2f) = 0;
        void draw(sf::RenderTarget &);
        void set_speed(float);
        void change_speed(unsigned int);
        void set_direction(sf::Vector2f);
        sf::Vector2f get_position();
        void set_position(sf::Vector2f);
    protected:
        float speed;
        sf::Vector2f pos;
        sf::Vector2f dir;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape tile_itIs_on;
};

#endif // _GHOST