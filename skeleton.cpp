#include "skeleton.h"


Skeleton::Skeleton(const std::string name_file,
            const float obj_size_x,
            const float obj_size_y,
            int pos_x, int pos_y) :

        Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
        currentFrame(0.0),
        ON_GROUND(true),
        COOLDOWN_FIRE(sf::seconds(0.5))
        {
            current_direction = RIGHT;
            acceleration_obj.y = 0.0005;
            velocity_obj.y = 0.1;
        }

void Skeleton::draw(sf::RenderWindow &window)
{
    if (this->current_direction == RIGHT)
        this->obj_sprite.setTextureRect(sf::IntRect(125, 0, -125, 200));
    
    if (this->current_direction == LEFT)
        this->obj_sprite.setTextureRect(sf::IntRect(0, 0, 125, 200));

    window.draw(this->obj_sprite);
}

void Skeleton::motion(){}

void Skeleton::update(float time, sf::RenderWindow &window, Hero& hero, Map& map)
{
    current_direction = IsHeroNear(hero);
    draw(window);

    if ((this->clock_fire.getElapsedTime().asSeconds() > this->COOLDOWN_FIRE.asSeconds()))
    {
        fire(hero);
        this->clock_fire.restart();
    }


    if(bullets.size() != 0)
        bullets.front().update(time, window, hero, map);

    if (bullets.size() != 0)
    {
        if (!bullets.front().life)
            bullets.erase(bullets.begin());
    }
}

int Skeleton::IsHeroNear(const Hero& hero)
{
    float distx = hero.pos_obj.x - pos_obj.x;
    float disty = hero.pos_obj.y - pos_obj.y;

    this->dist_to_Hero = sqrt(pow(distx, 2.0) + pow(disty, 2.0));
    if (this->dist_to_Hero < 1400)
    {
        if (distx > 0)
            return RIGHT;
        else
            return LEFT;
    }

    return 0;
}

void Skeleton::fire(Hero& hero)
{
    Bulet *my_bulet = new Bulet("images/bullet.png", 95, 87, pos_obj.x, pos_obj.y);

    if (bullets.size() == 0 && this->dist_to_Hero < 1400)
    {
        float y_0, x_0;
        x_0 = hero.pos_obj.x + hero.size_obj.x / 2 - (this->pos_obj.x + this->size_obj.x/2); //расстояние  по х между героем и скелетом
        y_0 = -(hero.pos_obj.y + hero.size_obj.y / 2 - (this->pos_obj.y + this->size_obj.y/2));

        my_bulet->current_direction = this->current_direction;

        float a = (x_0 / y_0);
        float b = my_bulet->speed_module;
        float c = (my_bulet->acceleration_obj.y / 2) * a * x_0;
        if (x_0 > 0.0)
        {
            if(y_0 > 0.0)
            {
                my_bulet->velocity_obj.y = -sqrt((-a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / ((a * a + 1)) + (a * a * b) / ((a * a + 1)) + b / (a * a + 1) + c / (a * a + 1)) / sqrt(2);

                my_bulet->velocity_obj.x = sqrt(b * b - my_bulet->velocity_obj.y * my_bulet->velocity_obj.y);
                if(errno == EDOM)
                {
                    delete my_bulet;
                }
                else
                {
                    bullets.emplace_back(*my_bulet);
                }
            }
            else
            {
                if (y_0 < (-my_bulet->acceleration_obj.y * x_0 * x_0 / (2 * my_bulet->speed_module * my_bulet->speed_module)))
                {
                    my_bulet->velocity_obj.y = sqrt((a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / (2 * (a * a + 1)) + (a * a * b) / (2 * (a * a + 1)) + b / (a * a + 1) + c / (a * a + 1));
                }
                else
                {
                    my_bulet->velocity_obj.y = -sqrt((a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / (2 * (a * a + 1)) + (a * a * b) / (2 * (a * a + 1)) + b / (a * a + 1) + c / (a * a + 1));
                }

                my_bulet->velocity_obj.x = sqrt(b * b - my_bulet->velocity_obj.y * my_bulet->velocity_obj.y);
                if (errno == EDOM)
                {
                    delete my_bulet;
                }
                else
                {
                    bullets.emplace_back(*my_bulet);
                }
            }
        }
        else
        {
            if (y_0 > 0.0)
            {
                my_bulet->velocity_obj.y = -sqrt((a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / ((a * a + 1)) + (a * a * b) / ((a * a + 1)) + b / (a * a + 1) + c / (a * a + 1)) / sqrt(2);

                my_bulet->velocity_obj.x = -sqrt(b * b - my_bulet->velocity_obj.y * my_bulet->velocity_obj.y);
                if (errno == EDOM)
                {
                    delete my_bulet;
                }
                else
                {
                    bullets.emplace_back(*my_bulet);
                }
            }
            else
            {
                if (y_0 < (-my_bulet->acceleration_obj.y * x_0 * x_0 / (2 * my_bulet->speed_module * my_bulet->speed_module)))
                {
                    my_bulet->velocity_obj.y = sqrt((-a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / (2 * (a * a + 1)) + (a * a * b) / (2 * (a * a + 1)) + b / (a * a + 1) + c / (a * a + 1));
                }
                else
                {
                    my_bulet->velocity_obj.y = -sqrt((-a * sqrt(a * a * b * b - 4 * b * c - 4 * c * c)) / (2 * (a * a + 1)) + (a * a * b) / (2 * (a * a + 1)) + b / (a * a + 1) + c / (a * a + 1));
                }

                my_bulet->velocity_obj.x = -sqrt(b * b - my_bulet->velocity_obj.y * my_bulet->velocity_obj.y);
                if (errno == EDOM)
                {
                    delete my_bulet;
                }
                else
                {
                    bullets.emplace_back(*my_bulet);
                }
            }
        }
        //printf(" X Y : %f %f\n", my_bulet->velocity_obj.x, my_bulet->velocity_obj.y);
    }
}