
#ifndef GAMECC
#define GAMECC
#include "game.h"

void Game::start(std::string Name){

    players.push_back(Player(Name, true));
    players.push_back(Player("SI_1"));
    players.push_back(Player("SI_2"));
//    int i = -1;
    starting_round = -1;
}

bool Game::higher(Card A, Card B, int trump){ //return if A is higher then B, where A is 1st on the table
    if(A.suit == B.suit){
        return A.value > B.value;
    }
    if(B.suit == trump){
        return false;
    }
    return true;
}

int Game::give_cards(){
    players[0].pass = false;
    players[1].pass = false;
    players[2].pass = false;
    current_bid = 100;
    starting_round = (starting_round+1)%3;
//    int dealer = starting_round;
    bider = (starting_round+1)%3;
    deck.shuffle();
    for( int i = 0; i < 7 ; ++i){
        for( int j = 0 ; j < 3; ++j){
            players[j].add_card(deck.get_card());
        }
    }
    if(bider == 1){
        int bid = players[bider].bid(current_bid);
        if(bid == -1) { players[bider].pass = true; }
        else {current_bid = bid; current_bidder = bider;}
        bider = (bider+1)%3;
    }
    if(bider == 2){
        int bid = players[bider].bid(current_bid);
        if(bid == -1) { players[bider].pass = true; }
        else {current_bid = bid; current_bidder = bider;}
        bider = (bider+1)%3;
    }
    return 0;
}

int Game::make_bids(int value){
    bider = (bider+1)%3;
    if(value<100){
        players[0].pass = true;
    }
    else{
        current_bid = value;
        current_bidder = 0;
    }
    int passed = players[0].pass + players[1].pass + players[2].pass;
//    int dealer = starting_round;
    for(; passed != 2; bider = (bider+1)%3){
        if(players[bider].pass) continue;
        if(players[bider].real_player){
            return -1;
        }
        else{
        int bid = players[bider].bid(current_bid);
        std::cout<<bid<<std::endl;
        if(bid == -1) { players[bider].pass = true; passed++; }
        else {current_bid = bid; current_bidder = bider;}
        }
    }
    return current_bidder;
}

void Game::give_remaining_cards(){
    players[current_bidder].add_card(deck.get_card());
    players[current_bidder].add_card(deck.get_card());
    players[current_bidder].add_card(deck.get_card());
    if(!players[current_bidder].real_player){
        players[(current_bidder +1)%3].add_card(players[current_bidder].give_away());
        players[(current_bidder +2)%3].add_card(players[current_bidder].give_away());
    }
}

//int Game::



#endif

