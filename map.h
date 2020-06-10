#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>

class Map
{
public:
	sf::Image map_image;
	sf::Texture map;
	sf::Sprite sprite_map;
	static const int HEIGHT_MAP = 37 + 1;
	const int WIDTH_MAP = 193+2;
	sf::String TileMap[HEIGHT_MAP]={

        "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222220",
        "0                                                                                                                                                                                                0",
        "0                                                                                                                                                     k                                          0",
        "0                                                                                                                                                    G G     GG                                  0",
        "0                                                                                                                          H                    G G G   G G G  G                                 0",
        "0                   GGGG       k                                            H                                                                  42222222222225  G                                 0",
        "0                  G    G G G G G                                          G G                                           GG GG                                 G                                 0",
        "0                 G     4222222225                                        G   G                                          42225                                 G          4225                   0",
        "0             GG  42225                                             G G G G   G                                                                                G                                 0",
        "0            G                                                 G    42222222225                $ $ $ $ $ $         GGGG                                                                          0",
        "0            G                                                425                                                  4225                                  GG   GGG                                0",
        "0            G                                           G                                                                                              G  G G   G                               0",
        "0          4225                                         425                                                                                             G  425    G                              0",
        "0                                                  G                                          42222222222225     GG                           G G G G G G          G                             0",
        "0 $$$                                             425                                                         425  G  GGG                    422222222225           G   GGG                      0",
        "0                G G G G G           G G G G G                                                                     G G   G                 G                         G G   G                     0",
        "0          G    42222222225         42222222225                                                                    425    G               425                        425    G                    0",
        "0         425                                                                 GG      GG                                  G G G G G G                                        G                   0",
        "0                           GG                                               G  G    G  G  G                              422222222225                                        G  GG   $ $ $ $ $  0",
        "0222225                    G  G                                              G  422225  G G G                                                                                 G G  G             0",
        "000000i             GGGG   G  425                                        GG  G          425 G                                          GG                                     425   G            0",
        "0                  G    G  G                                             G G G              G                                         G  G                                          G            0",
        "0             GG  G      G G                                             G 425              G                                         G  4225                                       G            0",
        "0            G  GHG      G G                                             G                  GGG                                       G                                             422222222222 0",
        "0            G  425      425                                             G                  425                                  GG   G                                                          0",
        "0            G                                                        GG G                     45                       GGG     G  G  G                                                          0",
        "0        GG  G                                                       G 425                                      GGG    G   G   G   4225                 H                                        0",
        "0       G  G G                                                       G                                         G   G  G     G  G                       G G                                       0",
        "0       G  425                      G G G G                          G                           GGGG          G   4225     G  G                      G   G                                      0",
        "0       G            GGG           422222225                         G                           4225          G            G  G                     G     G                                     0",
        "0       G            425           r0000000i                      4225                           r00i          G            4225                    422222225                                    0",
        "0       G                          r0000000i      G G G           r00i                           r00i          G                                    r0000000i                                    0",
        "0     425                          r0000000i      42225           r00i                           r00i       4225                                 422600000007225                             d   0",
        "0                               42260000000i      r000i           r007225                     422600i                                            r0000000000000i                             D   0",
        "0                               r0000000000i    4260007225wwwww422600000i                     r00000i                                         422600000000000007225                      k   D   0",
        "0                               r0000000000i    r00000000iwwwwwr00000000i    ~~~~  k  ~~~~    r00000i                                         r0000000000000000000i                          D   0",
        "022222222222222222222222222222226000000000072226000000000i00000r00000000722228888822288888222260000072222222lllllllllllllllllllllllllllll222226000000000000000000072222222222222222222222222222220",
        };

        Map();
        void draw(sf::RenderWindow &window);
};

//g++ main.o objects.o game.o hero.o map.o slime.o skeleton.o bulet.o menu.o -o game -lsfml-graphics -lsfml-window -lsfml-system

//g++ -c main.cpp objects.cpp game.cpp hero.cpp slime.cpp skeleton.cpp map.cpp bulet.cpp menu.cpp

#endif
