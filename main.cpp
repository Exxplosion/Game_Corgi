#include "game.h"
#include "menu.h"

int main()
{
    Game game;
    Menu MENU;
    MENU.menu(game.window);

    game.run();
}