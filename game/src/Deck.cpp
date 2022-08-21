
#include "Deck.hpp"

Deck::Deck()
{
    int value = 1;

    for (std::string color : {"Spades", "Clubs", "Hearts", "Diamonds"}) {
        for (std::string number : {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}) {
            this->_cards.push_back(std::make_shared<Card>(number + " of " + color, value));
            if (value < 10)
                value++;
        }
        value = 1;
    }
}

Deck::~Deck()
{
}

std::shared_ptr<Card> Deck::drawTopCard()
{
    for (size_t i = 0; i < this->_cards.size(); i++)
        if (this->_cards[i]->checkIfInDeck()) {
            this->_cards[i]->removeFromDeck();
            return (this->_cards[i]);
        }
    return (std::make_shared<Card>("Error", -1));
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    std::shuffle(std::begin(this->_cards), std::end(this->_cards), e);
}

void Deck::reassemble()
{
    for (size_t i = 0; i < this->_cards.size(); i++)
        this->_cards[i]->returnToDeck();
}
