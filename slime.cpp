#include "slime.h"


Slime::Slime(const std::string name_file,
            const float obj_size_x,
            const float obj_size_y,
            int pos_x, int pos_y) :

        Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
        currentFrame(0.0),
        previous_direction(RIGHT),
        ON_GROUND(true)
        {
            current_direction = RIGHT;
            velocity_obj.x = 0.2;
            acceleration_obj.y = 0.0005;
        }

void Slime::draw(sf::RenderWindow &window)
{
    this->obj_sprite.setScale(2.0, 2.0);
    if (this->current_direction == RIGHT)
        this->obj_sprite.setTextureRect(sf::IntRect(17, 23, 83, 80));
    if (this->current_direction == LEFT)
        this->obj_sprite.setTextureRect(sf::IntRect(100, 23, -83, 80));
    window.draw(this->obj_sprite);
}


void Slime::motion()
{
    switch (current_direction)
    {
    case LEFT:
        //current_direction = LEFT;
        velocity_obj.x = -0.2;
        break;
    case RIGHT:
        //current_direction = RIGHT;
        velocity_obj.x = 0.2;
        break;
    }
}

void Slime::update(float time, sf::RenderWindow& window, Hero& hero, Map& map)
{
    this->pos_obj.x += this->velocity_obj.x * time;
    CheckWall(map, this->velocity_obj.x, 0);

    motion();
    CheckHero(hero);

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y - 65);
    draw(window);
}


int Slime::CheckWall(Map& map, float Dx, float Dy){

    for (int i = this->pos_obj.y / 70; i < (this->pos_obj.y + this->size_obj.y) / 70; i++)
        for (int j = this->pos_obj.x / 70; j < (this->pos_obj.x + this->size_obj.x) / 70; j++)
        {
            if (map.TileMap[i][j] == '1' || map.TileMap[i][j] == '2' || map.TileMap[i][j] == '3' || map.TileMap[i][j] == '4' || map.TileMap[i][j] == '5')
            { /*
				if (Dy > 0){
                    this->pos_obj.y = i * 70 - h;  
                    velocity_obj.y = 0; 
                    ON_GROUND = true; 
                    if(map.TileMap[i][j] == '4'){
                        return RIGHT;
                    }
                    if(map.TileMap[i][j] == '5'){
                        return LEFT;
                    }
                }
                if (Dy < 0)
                {
                    this->pos_obj.y = i * 70 + 70;
                    velocity_obj.y = 0;
                    if(map.TileMap[i][j] == '4'){
                        return RIGHT;
                    }
                    if(map.TileMap[i][j] == '5'){
                        return LEFT;
                    }
                } */

                if (map.TileMap[i][j] == '4')
                {
                    //this->pos_obj.x = j * 70 - w;
                    current_direction = RIGHT;
                    return RIGHT;
                } //с правым краем карты
                if (map.TileMap[i][j] == '5')
                {
                    //this->pos_obj.x = j * 70 + 70;
                    current_direction = LEFT;
                    return RIGHT;
                } // с левым краем карты
            }     //else {ON_GROUND = false;}
		}
 

	return 0;
        
	
}


void Slime::CheckHero(Hero& hero)
{
    if(this->getRect().intersects(hero.getRect()))
    {
        hero.hit_points--;
        hero.velocity_obj.y = -0.35;
    }
}
