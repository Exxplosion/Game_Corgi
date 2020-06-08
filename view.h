#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

sf::View view;

void ChangeView(const sf::Vector2f& pos_hero)
{
    float X = pos_hero.x, Y = pos_hero.y;

    if (pos_hero.x < 950 + 70)
        X = 950 + 70;
    if (pos_hero.x > 12500)
        X = 12500;
    if (pos_hero.y < 550 + 70)
        Y = 550 + 70;
    if (pos_hero.y > 2120)
        Y = 2120;
    view.setCenter(X, Y);
}
#endif