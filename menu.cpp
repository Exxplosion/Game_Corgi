#include "menu.h"

Menu::Menu() : texture_button1(sf::Texture()),
               texture_button2(sf::Texture()),
               texture_button3(sf::Texture()),
               texture_bckgrund(sf::Texture()),
               tx_png_game(sf::Texture()),
               button1(sf::Sprite()),
               button2(sf::Sprite()),
               button3(sf::Sprite()),
               sp_bckgrund(sf::Sprite()),
               sp_png_game(sf::Sprite())

{
    texture_button1.loadFromFile("images/xstart.png");
    texture_button2.loadFromFile("images/xinfo1.png");
    texture_button3.loadFromFile("images/xexit.png");
    texture_bckgrund.loadFromFile("images/s1200.jpeg");
    tx_png_game.loadFromFile("images/Klass.png");
    sp_png_game.setTexture(tx_png_game);
    button1.setTexture(texture_button1);
    button2.setTexture(texture_button2);
    button3.setTexture(texture_button3);
    sp_bckgrund.setTexture(texture_bckgrund);
    button1.setPosition(560 - 58, 360);
    button1.scale(2.0, 2.0);
    //button1.setTextureRect(sf::IntRect(0, 0, 100, 150));
    button2.setPosition(560 - 58, 460);
    button2.scale(2.0, 2.0);
    //button2.setTextureRect(sf::IntRect(0, 0, 100, 150));
    button3.setPosition(560 - 58, 560);
    button3.scale(2.0, 2.0);
    //button3.setTextureRect(sf::IntRect(0, 0, 100, 200));
    sp_bckgrund.setPosition(0, 0);
    sp_png_game.setPosition(0, 0);
    sp_png_game.setScale(0.57, 0.55);
};

void Menu::menu(sf::RenderWindow& window)
{
    sf::Music music;
    music.openFromFile("images/beach_boys.wav");

    music.play();

    is_menu = true;
    
    while (is_menu)
    {
        window.clear();
        if (sf::IntRect(560 - 58, 360, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {   
            is_menu = false;
            sf::Vector2u vec = {1920, 1080};
            window.setSize(vec);
            return;
        }
        if (sf::IntRect(560 - 58, 460, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                window.draw(sp_png_game);
                window.display();
            }
        }
        if (sf::IntRect(560 - 58, 560, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            printf("bye!\n");
            window.close();
            exit(1);
        }

        window.draw(sp_bckgrund);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);

        window.display();
    }
}
