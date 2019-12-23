#pragma once
#include "paddle_player.h"
#include "score.h"

class ball : public Entity {
public:
	ball(paddle_player* player1, paddle_player* player2, score* scorePlayer1, score* scorePlayer2);
	void update(sf::RenderWindow* window);
private:
	void resetposition(sf::RenderWindow* window);
	score* score1;
	score* score2;

	//needs reference to both paddles....
	paddle_player* player1;
	paddle_player* player2;
};