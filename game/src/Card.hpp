
#ifndef CARD_HPP_
    #define CARD_HPP_

    #include <string>

    class Card {
        public:
            Card(std::string, int);
            ~Card();
            bool checkIfInDeck();
            void removeFromDeck();
            void returnToDeck();
            std::string getName();
            int getValue();
        private:
            bool _inDeck;
            int _value;
            std::string _name;
    };

#endif /* !CARD_HPP_ */
