// #include "player.h"

std::string Player::card_name(int suit, int value){
    std::string result ="";
    if(value == NINE) result+="9";
    if(value == JACK) result+="Jack";
    if(value == QUEEN) result+="Queen";
    if(value == KING) result+="King";
    if(value == TEN) result+="10";
    if(value == ACE) result+="Ace";
    result+=" of ";
    if(suit == SPADE) result+="Spades\n";
    if(suit == CLUB) result+="Clubs\n";
    if(suit == DIAMOND) result+="Diamonds\n";
    if(suit == HEART) result+="Hearts\n";
    return result;
}
int Player::suit_of_name(std::string suit_name){
    if(suit_name == "Spades") return SPADE;
    if(suit_name == "Clubs") return CLUB;
    if(suit_name == "Diamonds") return DIAMOND;
    if(suit_name == "Hearts") return HEART;
    return -1;
}
int Player::value_of_name(std::string value_name){
    if(value_name == "9") return NINE;
    if(value_name == "Jack") return JACK;
    if(value_name == "Queen") return QUEEN;
    if(value_name == "King") return KING;
    if(value_name == "10") return TEN;
    if(value_name == "Ace") return ACE;
    return -1;
}

Card Player::get_response_card(int suit, int value, int trump, int proper_suit){

        Card w = hand.get_highest(proper_suit);
        if(w.value == -1){
            if(trump != -1){
                if(suit == trump && proper_suit != trump){
                    return get_response_card(suit, value, trump, suit);
                }
                Card t = hand.get_lowest(trump);
                if(t.value != -1) return t;
            }
            return hand.get_all_lowest();
        }
        if(w.value < value){
            hand.add_card(w);
            w = hand.get_lowest(suit);
        }
        return w;

}

int Player::bid(int current_bid){
    if(real_player){
        while(true){
            int val;
            std::cin>>val;
            if(val >= current_bid){
                return val;
            }
            if(val < 100){
                return -1;
            }
        }
    }
    int p = hand.get_value();
    if(p >= current_bid+10){
        p = (p/10) * 10;
        return current_bid+10;
    }
    return -1;
}

bool Player::add_points(int value, bool bidder){
    int last_digit = value%10;
    value = value/10;
    if(last_digit>5){
        value+=1;
    }
    value = value*10;
    if(points > 900 && !bidder) return false;
    points+=value;
    if(points >= 1000){
        if(bidder) return true;
        points = 990;
        return false;
    }
    return false;
}

int Player::set_value(int minimal_value){
    int p = hand.get_better_value();
    if(p > minimal_value){
        p = (p/10) * 10;
        return p;
    }
    else return minimal_value;
}


Card Player::get_trick_start(int trump = -1){
    call = false;

    
    if(cards_to_start.size()>0){
        Card p = cards_to_start[0];
        cards_to_start.erase(cards_to_start.begin());
        return p;
    }
    int suits[4] = {HEART,  DIAMOND, CLUB, SPADE};

    int suits_per_10[4] = { HEART/10, DIAMOND/10, CLUB/10, SPADE/10};

    for(auto suit:suits){
        Card ace = hand.get_highest(suit);
        if(ace.value == ACE){
            if(trump!= -1){
                return ace;
            }
            cards_to_start.push_back(ace);
            Card ten = hand.get_highest(suit);
            if(ten.value == TEN){
                cards_to_start.push_back(ten);
            }
            else hand.add_card(ten);
        }
        else hand.add_card(ace);
    }

    if(cards_to_start.size()>0){
        Card p = cards_to_start[0];
        cards_to_start.erase(cards_to_start.begin());
        return p;
    }

    for(auto suit:suits_per_10){
        Card p = hand.get_card(suit*10, QUEEN);
        if(p.value ==QUEEN && hand.check_marriage(suit*10)){
            call = true;
            if(p.value != QUEEN){
                call = false; 
            }
            else{
                return p;
            }
        }
        else hand.add_card(p);
    }

    

    for(auto suit:suits){
        Card p = hand.get_highest(suit);
        if(p.value>=0){
            return p;
        }
    }

    return Card(SPADE, -1);

}

Card Player::give_away(){

    return get_all_lowest();
}

Card Player::get_number_card(int number){
    size_t p  = number;
    if(p > hand.spades.size()){
        p -= hand.spades.size();
    }
    else{
        return hand.get_card(hand.spades[p-1].suit,hand.spades[p-1].value);
    }
    if(p > hand.clubs.size()){
        p -= hand.clubs.size();
    }else{
        return hand.get_card(hand.clubs[p-1].suit,hand.clubs[p-1].value);
    }
    if(p > hand.diamonds.size()){
        p -= hand.diamonds.size();
    }else{
        return hand.get_card(hand.diamonds[p-1].suit,hand.diamonds[p-1].value);
    }
    return hand.get_card(hand.hearts[p-1].suit,hand.hearts[p-1].value);
}
