#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//#include "view.h"

extern sf::View view;
static int a = 0;

class Menu
{
public:
    sf::Texture texture_button1;
    sf::Texture texture_button2;
    sf::Texture texture_button3;
    sf::Texture texture_bckgrund;
    sf::Texture tx_png_game;
    sf::Sprite button1;
    sf::Sprite button2;
    sf::Sprite button3;
    sf::Sprite sp_bckgrund;
    sf::Sprite sp_png_game;
    bool is_menu;
    Menu();

    void menu(sf::RenderWindow &window);
};

#endif