#ifndef PLAYER
#define PLAYER

#include "imports.h"
#include "hand.h"

class Player{
    public:
        std::string name;
        Player(std::string name, bool real_player = false): name{name}, real_player{real_player}, points{0} {}
        inline Card get_response_card(int suit, int value, int trump, int proper_suit);
        Card get_card(int suit, int value){ return hand.get_card(suit, value); }
        inline int bid(int current_bid);
        void add_card(Card card){ hand.add_card(card); }
        inline bool add_points(int value, bool bidder);
        int get_points(){ return points; }
        inline int set_value(int minimal_value);
        inline Card get_trick_start(int trump);
        Card get_all_lowest(){ return hand.get_all_lowest(); }
        bool call = false;
        bool real_player;
        inline std::string card_name(int suit, int value);
        inline Card get_number_card(int);
        inline int suit_of_name(std::string suit_name);
        inline int value_of_name(std::string value_name);
        inline Card give_away();
        void prepare_hand(){ hand.prepare_marriages(); }
        int size(){ return hand.size(); }
        bool check_marriage(int suit) { return hand.check_marriage(suit); }
        bool pass = false;
        std::vector<std::string> get_file_names() { return hand.get_file_names(); }

    private:
        std::vector<Card> cards_to_start;
//        unsigned ID;
        Hand hand;
        int points = 0;

        
};

#include "player.cc"

#endif //PLAYER
