
#include "Game.hpp"

Game::Game()
{
    this->_deck = std::make_unique<Deck>();
    this->_players.push_back(std::make_unique<Player>(1));
}

Game::Game(size_t player_count)
{
    this->_deck = std::make_unique<Deck>();
    for (size_t i = 0; i < player_count; i++)
        this->_players.push_back(std::make_unique<Player>(i + 1));
}

Game::~Game()
{
}

void Game::deal()
{
    this->_dealer_cards.clear();
    for (size_t i = 0; i < this->_players.size(); i++) {
        this->_players[i]->returnHand();
        this->_players[i]->draw(this->_deck->drawTopCard());
    }
    this->_dealer_cards.push_back(this->_deck->drawTopCard());
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        std::cout << "The dealer has been delt : " << this->_dealer_cards[0]->getName() << std::endl;
    for (size_t i = 0; i < this->_players.size(); i++)
        this->_players[i]->draw(this->_deck->drawTopCard());
    this->_dealer_cards.push_back(this->_deck->drawTopCard());
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        std::cout << "Cards have been delt." << std::endl;
}

void Game::shuffleDeck()
{
    this->_deck->shuffle();
}

void Game::getStdoutHits()
{
    std::string resp;

    for (size_t i = 0; i < this->_players.size(); i++) {
        resp = "";
        while (resp != "n" && this->_players[i]->getScore() < 21) {
            std::cout << "Player " << this->_players[i]->getId() << ", would you like to hit? Current score: " << this->_players[i]->getScore() << " (y/n)" << std::endl;
            std::cin >> resp;
            if (resp == "y") {
                this->_players[i]->draw(this->_deck->drawTopCard());
            } else if (resp != "n") {
                std::cout << "Invalid input, please just put \"y\" for yes or \"n\" for no." << std::endl;
            }
        }
        if (this->_players[i]->getScore() > 21)
            std::cout << "Player " << this->_players[i]->getId() << " busts!" << std::endl;
    }
}

int Game::revealResults()
{
    int ret = 0;

    if (PLAYERS_AND_CARDS_TO_SDTOUT) {
        for (size_t i = 0; i < this->_players.size(); i++)
            std::cout << "Player " << this->_players[i]->getId() << " has a score of " << this->_players[i]->getScore() << std::endl;
        std::cout << "Dealer turns his card to reveal : " << this->_dealer_cards[1]->getName() << std::endl;
    }
    while (getDealerScore() < 17) {
        this->_dealer_cards.push_back(this->_deck->drawTopCard());
        if (PLAYERS_AND_CARDS_TO_SDTOUT)
            std::cout << "Dealer draws : " << this->_dealer_cards[this->_dealer_cards.size() - 1]->getName() << std::endl;
    }
    std::cout << "Dealer's score is : " << getDealerScore() << std::endl;
    if (getDealerScore() > 21 && PLAYERS_AND_CARDS_TO_SDTOUT) {
            std::cout << "Dealer busts!" << std::endl;
    }
    if (PLAYERS_AND_CARDS_TO_SDTOUT)
        for (size_t i = 0; i < this->_players.size(); i++) {
            std::cout << "******************************" << std::endl;
            std::cout << "Results for Player " << this->_players[i]->getId() << std::endl;
            if (this->_players[i]->getScore() > 21 || (this->_players[i]->getScore() < this->getDealerScore() && this->getDealerScore() < 22)
            || (this->getDealerScore() == 21 && this->_dealer_cards.size() == 2 && this->_players[i]->handSize() > 2)) {
                std::cout << "LOSS" << std::endl;
            } else if (this->_players[i]->getScore() == this->getDealerScore() &&
            !(this->_players[i]->getScore() == 21 && this->_players[i]->handSize() == 2 && this->_dealer_cards.size() > 2)) {
                std::cout << "Push" << std::endl;
            } else {
                std::cout << "Win" << std::endl;
                if (this->_players[i]->getScore() == 21 && this->_players[i]->handSize() == 2)
                    std::cout << "Blackjack Win (x1.5)" << std::endl;
            }
        }
    for (size_t i = 0; i < this->_players.size(); i++)
        if (this->_players[i]->getId() == BOT_ID) {
            if (this->_players[i]->getScore() > 21 || (this->_players[i]->getScore() < this->getDealerScore() && this->getDealerScore() < 22)
            || (this->getDealerScore() == 21 && this->_dealer_cards.size() == 2 && this->_players[i]->handSize() > 2)) {
                ret = -2;
            } else if (this->_players[i]->getScore() == this->getDealerScore() &&
            !(this->_players[i]->getScore() == 21 && this->_players[i]->handSize() == 2 && this->_dealer_cards.size() > 2)) {
                ret = 0;
            } else {
                ret = 2;
                if (this->_players[i]->getScore() == 21 && this->_players[i]->handSize() == 2)
                    ret = 3;
            }
        }
    return (ret);
}

size_t Game::getDealerScore()
{
    size_t score = 0;
    size_t aces = 0;

    for (size_t i = 0; i < this->_dealer_cards.size(); i++) {
        score += this->_dealer_cards[i]->getValue();
        if (this->_dealer_cards[i]->getValue() == 1)
            aces++;
    }
    while (score <= 11 && aces) {
        aces--;
        score += 10;
    }
    return (score);
}

std::unique_ptr<GameInfo> Game::getGameInfo()
{
    std::unique_ptr<GameInfo> info = std::make_unique<GameInfo>();

    info->_dealer_card = this->_dealer_cards[1];
    for (size_t i = 0; i < this->_players.size(); i++) {
        info->_player_hands.push_back(this->_players[i]->getHand());
    }
    return (info);
}

std::vector<std::shared_ptr<Card>> Game::getDealerHand()
{
    return (this->_dealer_cards);
}

std::shared_ptr<Card> Game::manualHit(size_t id)
{
    this->_players[id]->draw(this->_deck->drawTopCard());
    return (this->_players[id]->getHand()[this->_players[id]->handSize() - 1]);
}
