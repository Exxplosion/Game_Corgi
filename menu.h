#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
//#include "view.h"

extern sf::View view;

class Menu
{
public:
    sf::Texture texture_button1;
    sf::Texture texture_button2;
    sf::Texture texture_button3;
    sf::Texture texture_bckgrund;
    sf::Sprite button1;
    sf::Sprite button2;
    sf::Sprite button3;
    sf::Sprite sp_bckgrund;

    bool is_menu;
    Menu();

    void menu(sf::RenderWindow &window);
};

#endif