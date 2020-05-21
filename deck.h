#ifndef DECK
#define DECK

#include "card.h"

class Deck{

    public:
        inline Deck();
        inline void shuffle(); 
        inline Card get_card();

    private:
        int index = -1;
        std::vector<Card> cards;
        // std::queue<Card> card_queue;
        


        

};

#include "deck.cc"



#endif //DECK
