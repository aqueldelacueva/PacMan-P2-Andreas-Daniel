#pragma once
#include "Map.h"
#include "Enemy.h"
#include "TimeManager.h"
#include <Map>
#include <vector>
struct variablesValue {
	bool run = true;
	bool win = false;
	int lifes = 10;
	int pwup_points = 10;
	int enemy_points = 50;
	bool kill = false;
	const float powerUp_time = 15;
	int powerUp_countdown = 0;
}; 