#pragma once

#include "Map.h"
#include "Enemy.h"
#include "Variables.h"
#include "TimeManager.h"
#include <vector>


enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };

class Player
{
public:
	// Constructor del jugador
	Player(int x, int y);

	void HandInput();
	void Update(const Map& map, std::vector<Enemy>& enemies, variablesValue& value);
	void Draw() const;

	// Posicion del player
	int x() const;
	void set_x(int x);
	int y() const;
	void set_y(int y);

private:
	int x_;
	int y_;
	char player_char_ = 'O';
	int player_points_ = 0;
	USER_INPUTS input_ = USER_INPUTS::NONE;

};

