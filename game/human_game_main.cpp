
#include "src/Game.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Game game;

    game.shuffleDeck();
    game.deal();
    game.revealResults();
}
