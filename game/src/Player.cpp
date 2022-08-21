
#include "Player.hpp"

Player::Player(size_t id)
{
    this->_id = id;
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        std::cout << "Player " << this->_id << " has joined the game." << std::endl;
}

Player::~Player()
{
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        std::cout << "Player " << this->_id << " has left the game." << std::endl;
}

void Player::draw(std::shared_ptr<Card> card)
{
    if (card->getValue() == -1)
        return;
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        std::cout << "Player " << this->_id << " has been delt : " << card->getName() << std::endl;
    this->_hand.push_back(card);
}

void Player::returnHand()
{
    this->_hand.clear();
}

size_t Player::getScore()
{
    size_t score = 0;
    size_t aces = 0;

    for (size_t i = 0; i < this->_hand.size(); i++) {
        score += this->_hand[i]->getValue();
        if (this->_hand[i]->getValue() == 1)
            aces++;
    }
    while (score <= 11 && aces) {
        aces--;
        score += 10;
    }
    return (score);
}

size_t Player::getId()
{
    return (this->_id);
}
