
#ifndef DECK_HPP_
    #define DECK_HPP_

    #include <vector>
    #include <algorithm>
    #include <random>
    #include <chrono>
    #include <memory>

    #include "Card.hpp"

    class Deck {
        public:
            Deck();
            ~Deck();
            void shuffle(); // shuffle the deck (does not put cards back in deck)
            std::shared_ptr<Card> drawTopCard(); // take the top card
            void reassemble(); // return cards to deck
        private:
            std::vector<std::shared_ptr<Card>> _cards;
    };

#endif /* !DECK_HPP_ */
