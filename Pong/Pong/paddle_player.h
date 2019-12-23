#pragma once
#include "entity.h"

class paddle_player : public Entity {
public:
	paddle_player(int player);
	void update();
private:
	int playerNumber;
};