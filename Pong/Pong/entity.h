#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//be able to render sprites on the screen
class Entity : public sf::Sprite{
public:
	Entity() {
		this->texture = new sf::Texture();
	}

	void Load(std::string filename) {
		this->texture->loadFromFile("Graphics/" + filename);
		this->setTexture(*this->texture);
	}

	~Entity() {
		delete this->texture;
	}

	virtual void update() {
		this->move(this->velocity);
	}

	//Check for collision (Cheating)
	bool checkCollision(Entity* collision) {
		return this->getGlobalBounds().intersects(collision->getGlobalBounds());
	}
private:
	sf::Texture* texture;
protected:
	sf::Vector2f velocity;


};