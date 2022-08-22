
#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "Deck.hpp"
    #include "Player.hpp"
    #include "GameInfo.hpp"

    #define BOT_ID  1

    class Game {
        public:
            Game();
            Game(size_t);
            ~Game();
            void deal(); // resets everyone's hand and deals cards to all players and dealer
            void shuffleDeck(); // shuffle the deck
            void getStdoutHits(); // handle hits through stdin / stdout
            std::shared_ptr<Card> manualHit(size_t id); // creates a hit for the player who's id is given as parameter and returns the card
            int revealResults(); // makes the dealer turn his card and makes players win / lose
            size_t getDealerScore(); // calculate the score of the dealer's cards
            std::unique_ptr<GameInfo> getGameInfo(); // returns all visible cards at play
            std::vector<std::shared_ptr<Card>> getDealerHand(); // get the dealer's hand
        protected:
        private:
            std::unique_ptr<Deck> _deck;
            std::vector<std::unique_ptr<Player>> _players;
            std::vector<std::shared_ptr<Card>> _dealer_cards;
    };

#endif /* !GAME_HPP_ */
