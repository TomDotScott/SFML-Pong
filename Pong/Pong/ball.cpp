#include "ball.h"
#include <iostream>

ball::ball(paddle_player* player1, paddle_player* player2, score* scorePlayer1, score* scorePlayer2){
	//find the players
	this->player1 = player1;
	this->player2 = player2;
	//find their scores
	this->score1 = scorePlayer1;
	this->score2 = scorePlayer2;
	this->Load("ball.png");
	this->velocity.x = 1;
	this->velocity.y = 1;
}

void ball::update(sf::RenderWindow* window) {
	//check whether the ball has hit a paddle or not...
	if (this->checkCollision(this->player1) || this->checkCollision(this->player2)) {
		this->velocity.x *= -1;
	}
	//if it hits the ceiling
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y) {
		this->velocity.y *= -1;
	}

	//see whether the players have scored a point
	//player 2 scores
	if (this->getPosition().x < 5) {
		this->score2->addScore();
		this->resetposition(window);
	}
	//player 1 scores
	if (this->getPosition().x > window->getSize().x - 5) {
		this->score1->addScore();
		this->resetposition(window);
	}
	Entity::update();
}

void ball::resetposition(sf::RenderWindow* window) {
	//seed the random number generator
	srand(time(NULL));
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	velocity.x = 1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2 - 1)));
	if (rand() % 2 == 0) {
		velocity.x *= -1;
	}
	velocity.y = 1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2 - 1)));
	if (rand() % 2 == 0) {
		velocity.y *= -1;
	}
	std::cout << velocity.x << " "<< velocity.y << std::endl;

}