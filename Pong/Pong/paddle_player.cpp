#include "paddle_player.h"

paddle_player::paddle_player(int player) {
		this->playerNumber = player;
		switch (playerNumber) {
			//player 1...
		case 0:
			this->Load("player1.png");
			break;

			//player 2...
		default:
			this->Load("player2.png");
			break;
		}
	}

void paddle_player::update() {

		//each player has different player controls
		switch (this->playerNumber)
		{
		case 0:
			//one player uses the arrow keys
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
			break;
		default:
			//the other uses w and s
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
			break;
		}

		//make sure the paddle calls the superclass' update to make things move
		Entity::update();


		//make sure the paddles can't go off screen
		if (this->getPosition().y < 0) {
			this->move(0, 1);

		}
		//bad practise but heck.... 
		if (this->getPosition().y + this->getGlobalBounds().height > 600) {
			this->move(0, -1);

		}
};