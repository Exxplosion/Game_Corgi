#ifndef GAME_H
#define GAME_H


#include "hero.h"
//#include "view.h"
#include "slime.h"
#include "skeleton.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    void init_enemy();
    void KillEnemy();
    sf::RenderWindow window;
    sf::Texture Background;
    sf::Sprite sprite_background;
    sf::Texture game_lose_tx;
    sf::Sprite game_lose_sp;
    sf::Texture game_win_tx;
    sf::Sprite game_win_sp;
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
    void game_win(sf::Vector2f pos_camera);
    void game_lose(sf::Vector2f pos_camera);

    std::vector<sf::Vector2f> slimes_pos;
    std::vector<sf::Vector2f> skel_pos;

    std::vector<Slime*> Slimes;
    std::vector<Skeleton*> Skeletons;


    Game(const Game &) = delete;
};

#endif
