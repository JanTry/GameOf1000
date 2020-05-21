#ifndef GAME
#define GAME

#include "player.h"

class Game{
    public:
        Game() {}
        inline void start(std::string Name);
        inline void print_points(int player_id);
        int play_round();
        int give_cards();
        int make_bids(int);
        int current_bid;
        std::vector<Player> players;
        int current_bidder = 0;
        inline void give_remaining_cards();
        int round_points[3];
        int bider;
        Deck deck;
        int starting_round;
        inline bool higher(Card A, Card B, int trump);


//        int round_id = 0;



};
#include "game.cc"



#endif //GAME
