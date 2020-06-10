#ifndef SLIME_H
#define SLIME_H
#include "hero.h"


//Этот враг максимально простой. Ходит влево/вправо, при соударении о стенку меняет направление.
class Slime : public Object
{
public:
    enum Direction
    {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT,
        STAY,
    };

    short int current_direction;

    bool ON_GROUND;

    virtual void draw(sf::RenderWindow &window);


    void CheckWall(const Map& map);
    void CheckHero(Hero& hero);

    void motion();

    Slime(const std::string name_file,
         const float obj_size_x,
         const float obj_size_y,
         int pos_x, int pos_y);

    Slime(const Slime &) = delete;

    void update(float time, sf::RenderWindow &window, Hero& hero, Map& map);
};

#endif