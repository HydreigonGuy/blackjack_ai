
#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "Deck.hpp"
    #include "Player.hpp"

    class Game {
        public:
            Game();
            Game(size_t);
            ~Game();
            void deal();
            void shuffleDeck();
            void getStdoutHits();
            int revealResults();
            size_t getDealerScore();
        protected:
        private:
            std::unique_ptr<Deck> _deck;
            std::vector<std::unique_ptr<Player>> _players;
            std::vector<std::shared_ptr<Card>> _dealer_cards;
    };

#endif /* !GAME_HPP_ */
