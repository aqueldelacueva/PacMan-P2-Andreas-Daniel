#pragma once

#include "ConsoleUtils.h"
#include "Map.h"
#include "Enemy.h"
#include "Main.cpp"
#include <vector>

enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };

class Player
{
	char player_char = 'O';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::YELLOW;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;

public:
	// Constructor del jugador
	COORD position;
	int points = 0;
	bool playerDie;
	Player(COORD _spawn);
	void Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies);
	void Draw();
};

