#include "game.h"
#include "main_menu.h"
#include "ball.h"
#include <iostream>


void game::Initialize(sf::RenderWindow* window) {
	//initialise the font
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/gamefont.ttf");

	//initialise the score texts
	this->player1Score = new score(*font, 32U);

	this->player2Score = new score(*font, 32U);
	this->player2Score->setPosition(window->getSize().x - this->player2Score->getGlobalBounds().width, 0);


	this->player1 = new paddle_player(0);
	this->player1->setPosition(30, window->getSize().y / 2);

	this->player2 = new paddle_player(1);
	//move player2 to the right
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width - 30, window->getSize().y / 2);

	this->theBall = new ball(this->player1, this->player2, player1Score, player2Score);
	
	this->theBall->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	
}


void game::Render(sf::RenderWindow* window) {
	window->draw(*this->player1Score);
	window->draw(*this->player2Score);
	window->draw(*this->theBall);
	window->draw(*this->player1);
	window->draw(*this->player2);
}


void game::Update(sf::RenderWindow* window) {
	this->player1->update();
	this->player2->update();
	this->theBall->update(window);
	this->player1Score->update();
	this->player2Score->update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
		core_state.SetState(new main_menu());
	}
}

void game::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
	delete this->theBall;
	delete this->player1Score;
	delete this->player2Score;

}