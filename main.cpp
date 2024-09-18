#include ".\src\Cell.cpp"
#include ".\src\board.cpp"
#include ".\src\game.cpp"
#include ".\src\tiles.cpp"
#include ".\src\entity.cpp"

int main()
{
    srand(time(0));
    Game new_game;

    new_game.start_game();

    return 0;
}
