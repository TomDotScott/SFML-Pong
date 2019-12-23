#pragma once

#include "game_state.h"
#include "main_menu.h"
#include "entity.h"
#include "paddle_player.h"
#include "ball.h"
#include "score.h"

class game : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	~game();
private:
	paddle_player* player1;
	paddle_player* player2;
	ball* theBall;
	score* player1Score;
	score* player2Score;

	sf::Font* font;
};