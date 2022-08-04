#ifndef _BLINKY
#define _BLINKY

#include "ghost.hpp"

class Blinky : public Ghost
{
    public:
        Blinky();
        virtual void decide_direction(sf::Vector2f) override final;
    private:
        
};

#endif // _BLINKY