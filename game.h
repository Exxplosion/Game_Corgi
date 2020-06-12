#ifndef GAME_H
#define GAME_H


#include "hero.h"
//#include "view.h"
#include "slime.h"
#include "skeleton.h"
#include <SFML/Audio.hpp>

class Game
{
public:
    void init_enemy();
    void KillEnemy();
    sf::RenderWindow window;
    sf::Texture Background;
    sf::Sprite sprite_background;
    sf::Event event_game;
    sf::Clock clock_game;
    sf::Clock clock_game_loose;
    const sf::Time LOOSE_PAUSE;
    float time_game;
    bool FIRST_RESTART;
    //Menu MENU;
    //void menu_run();

    Game();
    void background_motion(sf::Vector2f pos_camera);
    void run();
    void pause();

    std::vector<sf::Vector2f> slimes_pos;
    std::vector<sf::Vector2f> skel_pos;

    std::vector<Slime*> Slimes;
    std::vector<Skeleton*> Skeletons;


    Game(const Game &) = delete;
};

#endif
