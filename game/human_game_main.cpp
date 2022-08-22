
#include "src/Game.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Game game;
    int res = 0;

    game.shuffleDeck();
    game.deal();
    game.getStdoutHits();
    res = game.revealResults();
    std::cout << "Res: " << res << std::endl;
}
