#include "Player.h"
#include "ConsoleUtils.h"
#include "Main.cpp"

Player::Player(int x, int y) : x_(x), y_(y) {}

void Player::Input()
{
    input = USER_INPUTS::NONE;
    if (ConsoleUtils::KeyPressed(VK_UP) || ConsoleUtils::KeyPressed('W'))
    {
        input = USER_INPUTS::UP;
    }
    if (ConsoleUtils::KeyPressed(VK_DOWN) || ConsoleUtils::KeyPressed('S'))
    {
        input = USER_INPUTS::DOWN;
    }
    if (ConsoleUtils::KeyPressed(VK_RIGHT) || ConsoleUtils::KeyPressed('D'))
    {
        input = USER_INPUTS::RIGHT;
    }
    if (ConsoleUtils::KeyPressed(VK_LEFT) || ConsoleUtils::KeyPressed('A'))
    {
        input = USER_INPUTS::LEFT;
    }
    if (ConsoleUtils::KeyPressed(VK_ESCAPE) || ConsoleUtils::KeyPressed('Q'))
    {
        input = USER_INPUTS::QUIT;
    }
}

void Player::Update(const Map& map, std::vector<Enemy>& enemies, variablesValue& value)
{
    if (value.win)
    {
        switch (input_)
        {
        case UP:
            break;
        case DOWN:
            break;
        case RIGHT:
            break;
        case LEFT:
            break;
        case QUIT:
            value.run = false;
            break;
        }
    }
    else
    {
        COORD player_pos;
        player_pos;
    }
}
