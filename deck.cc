// #include "deck.h"

Deck::Deck(){
    int values[] = {NINE, JACK, QUEEN, KING, TEN, ACE};
    int suits[] = {SPADE, CLUB, DIAMOND, HEART};

    for(int suit:suits){
        for(int value:values){
            cards.push_back(Card(suit, value));
        }
    }

}


Card Deck::get_card(){
    Card p = Card(cards[index].suit, cards[index].value); 
    index++; 
    
    return p;
}

void Deck::shuffle(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    index = 0;

}
