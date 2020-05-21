#ifndef CARD
#define CARD

#include "imports.h"

class Card{

    public:
        //Both suit and value are publicly known to all players who can see the card
        //No point in writing getters to them
        int suit; //card color
        int value; //card value
        bool trump; //Not Donald though
        bool marriage; //King or Queen
        inline std::string get_file_name();
        Card(int suit, int value): suit{suit} , value{value} , trump{false} , marriage{(value == KING || value == QUEEN)} {  }
        
        void set_trump(){ trump = true; }
        void unset_trump(){ trump = false; }
        inline bool operator<(const Card& other_card) const;
        inline bool operator>(const Card& other_card) const;
        inline bool operator==(const Card& other_card) const;

};

#include "card.cc"

#endif //CARD
