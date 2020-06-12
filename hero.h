#ifndef HERO_H
#define HERO_H

#include "objects.h"

#define CHECK_X 156
#define CHECK_Y 357


class Hero : public Object
{
public:
    enum Direction
    {
        LEFT = 1,
        JUMP_UP_LEFT,
        JUMP_DOWN_LEFT,
        GOT_HIT_LEFT,
        DIZZY_LEFT,
        INVINCIBLE_LEFT,
        STAY_LEFT,
        RIGHT,
        JUMP_UP_RIGHT,
        JUMP_DOWN_RIGHT,
        GOT_HIT_RIGHT,
        DIZZY_RIGHT,
        INVINCIBLE_RIGHT,
        STAY_RIGHT,
        GAME_OVER
    };

    short int previous_direction;
    short int previous_direction_2;
    short int current_direction;


    short int hit_points;
    short int hit_points_previous;
    short int keys;
    int gold;


    int NUMBER_SLIDE;
    double currentFrame;

    bool ON_GROUND;
    bool ON_INVINCIBLE;
    bool FIRST_GOTHIT;

    sf::Texture texture_hearts; //stdmap ; texture manager use?
    sf::Sprite hearts_sprite;
    sf::Texture texture_high_score;
    sf::Sprite high_score_sprite;
    sf::Texture gold_texture;
    sf::Sprite gold_sprite;


    const sf::Time COOLDOWN_INVINCIBLE;
    const sf::Time COOLDOWN_GOTHIT;
    sf::Time recent_click;
    sf::Time first_click;
    sf::Time current_summary_time;
    const sf::Time permissible_summary_time;
    sf::Clock clock;

    virtual void draw(sf::RenderWindow &window);

    void motion();

    Hero(const std::string name_file,
         const float obj_size_x,
         const float obj_size_y,
         int pos_x, int pos_y);

    void CheckMap(Map &map, const int current_check);
    Hero(const Hero&) = delete;
    sf::Vector2f get_pos_camera();

    void update(float time, Map &map);
};


#endif
