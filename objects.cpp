#include "objects.h"

Object::Object(const std::string name_file,
       const float obj_size_x,
       const float obj_size_y,
       int pos_x, int pos_y) :
        velocity_obj(0, 0),
        acceleration_obj(0, 0),
        file_load_name(name_file),
        size_obj(obj_size_x, obj_size_y),
        pos_obj(pos_x, pos_y),
        health_points(0),
        texture(sf::Texture()),
        obj_sprite(sf::Sprite())
        {
            image.loadFromFile(file_load_name);
            image.createMaskFromColor(sf::Color::Black);
            texture.loadFromImage(image);
            obj_sprite.setTexture(texture);
            obj_sprite.setTextureRect(sf::IntRect(0, 0, obj_size_x, obj_size_y));
            obj_sprite.setPosition(pos_obj.x, pos_obj.y);
        }

    sf::FloatRect Object::getRect(){
		return sf::FloatRect(pos_obj.x, pos_obj.y, size_obj.x, size_obj.y);
	}
