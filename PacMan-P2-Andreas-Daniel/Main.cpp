#include "Player.h"
#include "Enemy.h"
#include "TimeManager.h"
#include "Variables.h"
#include <vector>

Player player(Map::spawn_player);

/// <summary>
/// Sets the needed variables
/// </summary>
void Setup();
/// <summary>
/// Handles the inputs
/// </summary>
void Input();
/// <summary>
/// Handles the logic of the game
/// </summary>
void Logic();
/// <summary>
/// Draws the screen
/// </summary>
void Draw();

variablesValue value;

Map pacman_map = Map();
std::vector<Enemy> enemigos = std::vector<Enemy>();

int main()
{

    Setup();
    while (value.run)
    {
        Logic();
        Draw();
    }
}

void Setup()
{
    std::cout.sync_with_stdio(false);

    pacman_map.Setup();
    enemigos = pacman_map.Enemies();

    player = Player(5, 5);

    srand(time(NULL));

    int enemy_count = 0;

    std::cout << "How many enemies do you want?" << std::endl;
    std::cin >> enemy_count;

    for (size_t i = 0; i < enemy_count; i++)
    {
        enemigos.push_back(Enemy(pacman_map.spawn_enemy));
    }
}


void Logic()
{
    player.Input();
    player.Update(pacman_map, enemigos, value);
}

void Draw()
{
    ConsoleUtils::Console_SetPos(0, 0);
    pacman_map.Draw();
    for (size_t i = 0; i < enemigos.size(); i++)
    {
        enemigos[i].Draw();
    }

    ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::DARK_YELLOW);
    pacman_map.Draw();
    player.Draw();
    ConsoleUtils::Console_ClearCharacter({ 0,(short)pacman_map.Height });
    ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::CYAN);
    ConsoleUtils::GotoXY(1, 1);
    std::cout << "Puntuacion actual: " << player_points << " Puntuacion pendiente: " << pacman_map.points << " Vidas: " << value.lifes << std::endl;
    std::cout << "Fotogramas: " << TimeManager::getInstance().frameCount << std::endl;
    std::cout << "DeltaTime: " << TimeManager::getInstance().deltaTime << std::endl;
    std::cout << "Time: " << TimeManager::getInstance().time << std::endl;

    if (value.win)
    {
        ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::GREEN);
        std::cout << "Has ganado!" << std::endl;
    }
    if (value.lifes <= 0) 
    {
        ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::GREEN);
        std::cout << "HAS PERDIDO!" << std::endl;
        value.run = false;
    }

    TimeManager::getInstance().NextFrame();
}