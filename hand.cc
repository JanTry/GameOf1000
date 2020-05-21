 #include "hand.h"




void Hand::add_card(Card card){
    if(card.value == -1) return;
    if(card.suit == -1) return;
    if(card.suit == SPADE)
        add_by_value(spades, card);
    else if(card.suit == CLUB)
        add_by_value(clubs, card);
    else if(card.suit == DIAMOND)
        add_by_value(diamonds, card);
    else if(card.suit == HEART)
        add_by_value(hearts, card);
    else throw std::invalid_argument("INVALID SUIT FOR CARD ADDITION: ");
}

bool Hand::check_marriage(int suit){
    if(suit == SPADE){
        int spouses = 0;
        for(auto each:spades){
            if(each.value == QUEEN || each.value == KING) spouses++;
        }
        if(spouses == 1) return true;
        else return false;
    }
    if(suit == CLUB){
        int spouses = 0;
        for(auto each:clubs){
            if(each.value == QUEEN || each.value == KING) spouses++;
        }
        if(spouses == 1) return true;
        else return false;
    }
    if(suit == DIAMOND){
        int spouses = 0;
        for(auto each:diamonds){
            if(each.value == QUEEN || each.value == KING) spouses++;
        }
        if(spouses == 1) return true;
        else return false;
    }
    if(suit == HEART){
        int spouses = 0;
        for(auto each:hearts){
            if(each.value == QUEEN || each.value == KING) spouses++;
        }
        if(spouses == 1) return true;
        else return false;
    }
    return false;
}

std::vector<std::string> Hand::get_file_names(){
    std::vector<std::string> names;
    for(auto each:spades){
        names.push_back(each.get_file_name());
    }
    for(auto each:clubs){
        names.push_back(each.get_file_name());
    }
    for(auto each:diamonds){
        names.push_back(each.get_file_name());
    }
    for(auto each:hearts){
        names.push_back(each.get_file_name());
    }
    return names;
}

void Hand::prepare_marriages(){
    int spouses = 0;
    for(auto each:spades){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        mars[4] = true;
    }
    spouses = 0;
    for(auto each:clubs){
        if(each.marriage) spouses++;
    }
    if(spouses == 2){
        mars[6] = true;
    }
    spouses = 0;
    for(auto each:diamonds){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        mars[8] = true;
    }
    spouses = 0;
    for(auto each:hearts){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        mars[10] = true;
    }
}

void Hand::add_by_value(std::vector<Card>& list, Card& card){
    if(list.empty()){
        list.push_back(card);
        return;
    } 
    for(auto i = list.begin(); i != list.end(); ++i){
            if(card.value > i->value){
                list.insert(i, card);
                return;
            }
    }
    list.push_back(card);
}


Card Hand::get_lowest(int suit){
    if(suit == SPADE){
        if(spades.size() == 0) return Card(suit, -1);
        Card card(spades[spades.size() -1].suit , spades[spades.size() -1].value);
        spades.erase(spades.begin() + (spades.size() -1));
        return card;
    }
    else if(suit == CLUB){
        if(clubs.size() == 0) return Card(suit, -1);
        Card card(clubs[clubs.size() -1].suit , clubs[clubs.size() -1].value);
        clubs.erase(clubs.begin() + (clubs.size() -1));
        return card;
    }     
    else if(suit == DIAMOND){
        if(diamonds.size() == 0) return Card(suit, -1);
        Card card(diamonds[diamonds.size() -1].suit , diamonds[diamonds.size() -1].value);
        diamonds.erase(diamonds.begin() + (diamonds.size() -1));
        return card;
    }
    else if(suit == HEART){
        if(hearts.size() == 0) return Card(suit, -1);
        Card card(hearts[hearts.size() -1].suit , hearts[hearts.size() -1].value);
        hearts.erase(hearts.begin() + (hearts.size() -1));
        return card;
    }
    else return Card(suit, -1);
}

Card Hand::get_highest(int suit){
    if(suit == SPADE && !spades.empty()){
        Card card(spades[0].suit , spades[0].value);
        spades.erase(spades.begin());
        return card;
    } 
    else if(suit == CLUB && !clubs.empty()){
        Card card(clubs[0].suit , clubs[0].value);
        clubs.erase(clubs.begin());
        return card;
    }  
    else if(suit == DIAMOND && !diamonds.empty()){
        Card card(diamonds[0].suit , diamonds[0].value);
        diamonds.erase(diamonds.begin());
        return card;
    } 
    else if(suit == HEART && !hearts.empty()){
        Card card(hearts[0].suit , hearts[0].value);
        hearts.erase(hearts.begin());
        return card;
    }    
    else return Card(suit, -1);
}


void Hand::clear(){
    spades.clear();
    clubs.clear();
    diamonds.clear();
    hearts.clear();
}

Card Hand::get_all_lowest(){
    int values[6] = {NINE, JACK, QUEEN, KING, TEN, ACE};
    for(auto each:values){
        if(!mars[4]){
        Card s = get_lowest(SPADE);
        if(s.value == each){
            return s;
        }
        else add_card(s);
        }
        if(!mars[6]){
        Card c = get_lowest(CLUB);
        if(c.value == each){
            return c;
        }
        else add_card(c);
        }
        if(!mars[8]){
        Card d = get_lowest(DIAMOND);
        if(d.value == each){
            return d;
        }
        else add_card(d);
        }
        if(!mars[10]){
        Card h = get_lowest(HEART);
        if(h.value == each){
            return h;
        }
        else add_card(h);
        }
    
    }
    return get_real_all_lowest();
}

Card Hand::get_real_all_lowest(){
    int values[6] = {NINE, JACK, QUEEN, KING, TEN, ACE};
    for(auto each:values){
        Card s = get_lowest(SPADE);
        if(s.value == each){
            return s;
        }
        else add_card(s);
        Card c = get_lowest(CLUB);
        if(c.value == each){
            return c;
        }
        else add_card(c);
        Card d = get_lowest(DIAMOND);
        if(d.value == each){
            return d;
        }
        else add_card(d);
        Card h = get_lowest(HEART);
        if(h.value == each){
            return h;
        }
        else add_card(h);
    }
    return Card(SPADE, -1);
}

int Hand::get_value(){
    int marriages = 0;
    int card_value = 0;
    int spouses = 0;
    for(auto each:spades){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {marriages+=40; mars[4] = true;}
    if(spouses == 1) marriages+=10;
    spouses = 0;
    for(auto each:clubs){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {marriages+=60; mars[6] = true;}
    if(spouses == 1) marriages+=15;
    spouses = 0;
    for(auto each:diamonds){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {marriages+=80; mars[8] = true;}
    if(spouses == 1) marriages+=20;
    spouses = 0;
    for(auto each:hearts){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {marriages+=100; mars[10] = true;}
    if(spouses == 1) marriages+=25;

    int values[6] = {ACE, TEN, KING, QUEEN, JACK, NINE};
    for(size_t i = 0; i < 6; ++i){
        if(spades.size()>i && spades[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(clubs.size()>i && clubs[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(diamonds.size()>i && diamonds[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(hearts.size()>i && hearts[i].value==values[i])
            card_value+=values[i];
        else break;
    }

    return ((int)(card_value * 1.4) + marriages*1.1)*1.2;
}

int Hand::get_better_value(){
    int marriages = 0;
    int card_value = 0;
    int spouses = 0;
    for(auto each:spades){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        marriages+=40; 
        mars[4] = true;
    }
    spouses = 0;
    for(auto each:clubs){
        if(each.marriage) spouses++;
    }
    if(spouses == 2){
        marriages+=60; 
        mars[6] = true;
    }
    spouses = 0;
    for(auto each:diamonds){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        marriages+=80; 
        mars[8] = true;
    }
    spouses = 0;
    for(auto each:hearts){
        if(each.marriage) spouses++;
    }
    if(spouses == 2) {
        marriages+=100; 
        mars[10] = true;
    }

    int values[6] = {ACE, TEN, KING, QUEEN, JACK, NINE};
    for(size_t i = 0; i < 6; ++i){
        if(spades.size()>i && spades[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(clubs.size()>i && clubs[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(diamonds.size()>i && diamonds[i].value==values[i])
            card_value+=values[i];
        else break;
    }
    for(size_t i = 0; i < 6; ++i){
        if(hearts.size()>i && hearts[i].value==values[i])
            card_value+=values[i];
        else break;
    }
   
    return ((int)(card_value * 1.4) + marriages);
}

Card Hand::get_card(int suit, int value){
    if(suit == SPADE)
    for(size_t i = 0 ; i<spades.size();++i){
        if(spades[i].value == value){
            Card p = spades[i];
            spades.erase(spades.begin()+i);
            return p;
        }
    }
    if(suit == CLUB)
    for(size_t i = 0 ; i<clubs.size();++i){
        if(clubs[i].value == value){
            Card p = clubs[i];
            clubs.erase(clubs.begin()+i);
            return p;
        }
    }
    if(suit == DIAMOND)
    for(size_t i = 0 ; i<diamonds.size();++i){
        if(diamonds[i].value == value){
            Card p = diamonds[i];
            diamonds.erase(diamonds.begin()+i);
            return p;
        }
    }
    if(suit == HEART)
    for(size_t i = 0 ; i<hearts.size();++i){
        if(hearts[i].value == value){
            Card p = hearts[i];
            hearts.erase(hearts.begin()+i);
            return p;
        }
    }
    return Card(SPADE, -1);
}
