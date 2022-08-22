
#ifndef GAMEINFO_HPP_
    #define GAMEINFO_HPP_

    #include "Card.hpp"

    #include <memory>
    #include <vector>

    class GameInfo {
        public:
            GameInfo();
            ~GameInfo();
            std::vector<std::vector<std::shared_ptr<Card>>> _player_hands;
            std::shared_ptr<Card> _dealer_card;
            int getHighLowValue();
        protected:
        private:
    };

#endif /* !GAMEINFO_HPP_ */
