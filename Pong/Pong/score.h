#pragma once

#include <SFML/Graphics.hpp>

//deal with keeping track of and displaying the score of the game
class score : public sf::Text {
public:
	score(sf::Font& font, unsigned int size);
	void addScore();
	void update();
private:
	int currentScore;
};