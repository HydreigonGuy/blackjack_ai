
#include "GameInfo.hpp"

GameInfo::GameInfo()
{
}

GameInfo::~GameInfo()
{
}

int GameInfo::getHighLowValue()
{
    int ret = 0;

    if (this->_dealer_card->getValue() == 1 || this->_dealer_card->getValue() == 10) {
        ret--;
    } else if (this->_dealer_card->getValue() < 7)
        ret++;
    for (size_t i = 0; i < this->_player_hands.size(); i++) {
        for (size_t j = 0; j < this->_player_hands[i].size(); j++) {
            if (this->_player_hands[i][j]->getValue() == 1 || this->_player_hands[i][j]->getValue() == 10) {
                ret--;
            } else if (this->_player_hands[i][j]->getValue() < 7)
                ret++;
        }
    }
    return (ret);
}
