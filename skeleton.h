#ifndef SKELETON_H
#define SKELETON_H

#include <list>
#include <cmath>
#include "bulet.h"

class Skeleton : public Object
{
private:
std::list<Bulet> bullets;

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
    int NUMBER_SLIDE;
    double currentFrame;
    bool ON_GROUND;
    sf::Clock clock_fire;
    const sf::Time COOLDOWN_FIRE;
    float dist_to_Hero;

    virtual void draw(sf::RenderWindow &window);

    int IsHeroNear(const Hero& hero);

    void fire(Hero& hero);

    void motion();

    Skeleton(const std::string name_file,
         const float obj_size_x,
         const float obj_size_y,
         int pos_x, int pos_y);

    Skeleton(const Skeleton &) = delete;

    void update(float time, sf::RenderWindow &window, Hero& hero, Map& map);
};

#endif