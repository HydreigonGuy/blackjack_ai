
#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <vector>
    #include <iostream>
    #include <memory>

    #include "Card.hpp"

    #define PLAYERS_AND_CARDS_TO_SDTOUT true

    class Player {
        public:
            Player(size_t);
            ~Player();
            void draw(std::shared_ptr<Card>);
            void returnHand();
            size_t getScore();
            size_t getId();
            size_t handSize();
            std::vector<std::shared_ptr<Card>> getHand();
        private:
            std::vector<std::shared_ptr<Card>> _hand;
            size_t _id;
    };

#endif /* !PLAYER_HPP_ */
