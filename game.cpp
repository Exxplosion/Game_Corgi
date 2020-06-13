#include "game.h"
#include "slime.h"
#include "skeleton.h"
#include "bulet.h"

Game::Game() : window(sf::VideoMode(1200, 870), "GO"),
			   time_game(0.0),
			   Background(sf::Texture()),
			   sprite_background(sf::Sprite()),
			   event_game(sf::Event()),
			   clock_game(sf::Clock()),
			   LOOSE_PAUSE(sf::seconds(3.0)),
			   FIRST_RESTART(true),
			   game_lose_tx(sf::Texture()),
			   game_lose_sp(sf::Sprite()),
			   game_win_tx(sf::Texture()),
			   game_win_sp(sf::Sprite())
//MENU(Menu())
{	
	Background.loadFromFile("images/imgonline-com-ua-Resize-PYauMusAo9I.png");
	sprite_background.setTexture(Background);
	game_lose_tx.loadFromFile("images/lose.jpg");
	game_lose_sp.setTexture(game_lose_tx);
	game_lose_sp.setScale(0.7, 0.7);
	game_win_tx.loadFromFile("images/WIN.jpg");
	game_win_sp.setTexture(game_win_tx);
	game_win_sp.setScale(1.0, 0.73);
	slimes_pos = {{2600, 2030 - 65}, {1800, 420}, {8820, 1260 - 65}, {7070, 910 - 65}};
	skel_pos = {{700, GROUND$}, {11970, 420 - 140}, {3150, 560 - 140}, {13230, 1610 - 140}};
}




void Game::pause()
{
	while (1)
	{
		window.pollEvent(event_game);
		if((event_game.type == sf::Event::KeyPressed))
			return;
	};
}

void Game::background_motion(sf::Vector2f pos_camera)
{
	this->sprite_background.setPosition(pos_camera.x - 960, pos_camera.y - 550);
}



void Game::init_enemy()
{
	for(int i = 0; i < 4; i++)
	{
		Slime *slime_supp = new Slime("images/117687.png", 83, 80, slimes_pos[i].x, slimes_pos[i].y);
		Slimes.push_back(slime_supp);
	}

	for (int i = 0; i < 3; i++)
	{
		Skeleton *skeleton_supp = new Skeleton("images/idle.png", 125, 200, skel_pos[i].x, skel_pos[i].y);
		Skeletons.push_back(skeleton_supp);
	}
}


void Game::KillEnemy()
{
	delete [] &Slimes;

	delete [] &Skeletons;
}


void Game::run()
{
	//menu_run();

	init_enemy();

	Hero hero("images/Corgi.png", SIZE_PICT$ * 551.0, SIZE_PICT$ * 509.0, 150, GROUND$);
	
	//window.setFramerateLimit(30);
		window.setVerticalSyncEnabled(true);


	Map map;
	sf::Music music;
	music.openFromFile("images/beach_boys.wav");
	music.setLoop(true);

	music.play();

	while (window.isOpen())
	{
		this->time_game = clock_game.getElapsedTime().asMicroseconds();
		this->clock_game.restart();

		this->time_game = this->time_game / 1000; //определяется скорость игры


		window.clear();
		window.draw(sprite_background);
		window.pollEvent(event_game);

		if (event_game.type == sf::Event::Closed)
			window.close();
		if ((event_game.type == sf::Event::KeyPressed) && (event_game.key.code == sf::Keyboard::Escape))
			pause();


		hero.motion();


		hero.update(time_game, map);

		for(auto i : Slimes)
			i->update(time_game, window, hero, map);

		for(auto i : Skeletons)
			i->update(time_game, window, hero, map);

		if (((hero.current_direction == hero.GAME_OVER) || (hero.game_win)) && this->FIRST_RESTART)
		{
			this->FIRST_RESTART = false;
			this->clock_game_loose.restart();
		}

		if ((this->clock_game_loose.getElapsedTime().asSeconds() > this->LOOSE_PAUSE.asSeconds()) && !(this->FIRST_RESTART))
		{
			music.stop();
			if(hero.game_win)
			{
				printf("HI!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
				this->game_win(hero.get_pos_camera());
				return;
			}
			else
			{
				this->game_lose(hero.get_pos_camera());
				return;
			}
		}

		map.draw(window);

		hero.draw(window);
		background_motion(hero.get_pos_camera());
		window.display();
	}
}

void Game::game_lose(sf::Vector2f pos_camera)
{
	window.clear();
	sf::Music music;
	music.openFromFile("images/lose.wav");
	music.setLoop(true);
	music.play();
	game_lose_sp.setPosition(pos_camera.x - 450, pos_camera.y - 450);
	this->window.draw(this->game_lose_sp);
	window.display();
	sf::sleep(sf::seconds(5));
}

void Game::game_win(sf::Vector2f pos_camera)
{
	game_win_sp.setPosition(pos_camera.x - 960, pos_camera.y - 550);
	window.clear();
	sf::Music music;
	music.openFromFile("images/win.wav");
	music.play();
	this->window.draw(this->game_win_sp);
	window.display();
	sf::sleep(sf::seconds(7));
}