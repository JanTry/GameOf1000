#ifndef HAND
#define HAND

#include "deck.h"

class Hand{

    public:
        Hand() {}
        inline void add_card(Card card);
        inline Card get_highest(int suit); //unimplemented
        inline Card get_lowest(int suit); //unimplemented
        inline void clear();
        inline Card get_all_lowest(); //unimplemented - supposed to be inteligent enought to keep marriages, and so on
        inline int get_value();
        inline int get_better_value();
        inline Card get_real_all_lowest();
        inline Card get_card(int suit, int value);
        bool mars[12] = {false};
        inline void prepare_marriages();
        inline bool check_marriage(int suit);
        inline std::vector<std::string> get_file_names();
        std::vector<Card> spades;
        std::vector<Card> clubs;
        std::vector<Card> diamonds;
        std::vector<Card> hearts;
        int size(){ return spades.size() + clubs.size() + diamonds.size() + hearts.size() ;}
        // inline Card get_lowest_winning(int suit, int value, int trump = -1); //unimplemented
        // inline Card start_a_round(); //unimplemented
        // // inline Card call_trump(int suit); //probably not needed
        // inline int count_value(); //unimplemented. Highly needed. Supposed to count how high can and will go. RNG possible 
        // inline Card start_a_round_to_win(int suit, int highest_value); //unimplemented. Supposed to pick a card that has to win in that color
        // inline Card select_card(int suit, int value); //unimplemented. User based function - pick a card.


    private:
        inline void add_by_value(std::vector<Card>& list, Card& card);
        

        

};

#include "hand.cc"

#endif //HAND
