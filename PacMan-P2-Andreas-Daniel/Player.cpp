#include "Player.h"

Player::Player(COORD _spawn)
{
	position = _spawn;
}

void Player::Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies)
{

    COORD position_new = position;
    switch (input)
    {
    case UP:
        position_new.Y--;
        break;
    case DOWN:
        position_new.Y++;
        break;
    case RIGHT:
        position_new.X++;
        break;
    case LEFT:
        position_new.X--;
        break;
    }

    for (size_t i = 0; i < enemigos.size(); i++)
    {
        if (enemigos[i].Logic(&pacman_map, position)) {
            playerDie = true;
            value.lifes--;
        }
    }

    if (playerDie) {
        position_new.X = _map->spawn_player.X;
        position_new.Y = _map->spawn_player.Y;
    }

    if (position_new.X < 0)
    {
        position_new.X = _map->Width - 1;
    }
    position_new.X %= _map->Width;
    if (position_new.Y < 0)
    {
        position_new.Y = _map->Height - 1;
    }
    position_new.Y %= _map->Height;

    switch (_map->GetTile(position_new.X, position_new.Y))
    {
    case Map::MAP_TILES::MAP_WALL:
        position_new.Y = position.Y;
        position_new.X = position.X;
        break;
    case Map::MAP_TILES::MAP_POINT:
        _map->points--;
        points++;
        _map->SetTile(position_new.X, position_new.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    case Map::MAP_TILES::MAP_POWERUP:
        _map->points--;
        points += value.pwup_points;
        _map->SetTile(position_new.X, position_new.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    }
    position = position_new;
}

void Player::Draw()
{
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << player_char;
}
