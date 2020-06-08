#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <list>
#include "map.h"


#define GROUND$ 2335 + 70

#define SIZE_PICT$ 0.4


class Object
{
public:
    const std::string file_load_name;

    const sf::Vector2f size_obj;

    sf::Image image;
    sf::Texture texture; //stdmap ; texture manager use??
    sf::Sprite obj_sprite;

    sf::Vector2f pos_obj;
    sf::Vector2f velocity_obj;
    sf::Vector2f acceleration_obj;

    short int health_points;

    Object(const std::string name_file,
           const float obj_size_x,
           const float obj_size_y,
           int pos_x, int pos_y);

    virtual void draw(sf::RenderWindow &window) = 0;
    //virtual void update(float time, sf::RenderWindow &window, Hero& hero, Map& map);
    sf::FloatRect getRect();
};

#endif
