#include "score.h"

score::score(sf::Font& font, unsigned int size) : sf::Text("0pts", font, size) {
	this->currentScore = 0;
}

void score::addScore() {
	this->currentScore += 1;
}

void score::update() {
	this->setString(std::to_string(this->currentScore) + "pts");
}