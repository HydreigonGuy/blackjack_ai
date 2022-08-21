
#include "Card.hpp"

Card::Card(std::string name, int value)
{
    this->_inDeck = true;
    this->_name = name;
    this->_value = value;
}

Card::~Card()
{
}

bool Card::checkIfInDeck()
{
    return (this->_inDeck);
}

void Card::removeFromDeck()
{
    this->_inDeck = false;
}

void Card::returnToDeck()
{
    this->_inDeck = true;
}

std::string Card::getName()
{
    return (this->_name);
}

int Card::getValue()
{
    return (this->_value);
}
