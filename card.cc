


 bool Card::operator<(const Card& other_card) const{
     if(trump && !other_card.trump) return false;
     if(other_card.trump && !trump) return true;
     return value < other_card.value;
 }

 bool Card::operator>(const Card& other_card) const{
     if(trump && !other_card.trump) return true;
     if(other_card.trump && !trump) return false;
     return value > other_card.value;
 }

 bool Card::operator==(const Card& other_card) const{
     return (value==other_card.value && suit == other_card.suit);
 }

 std::string Card::get_file_name(){
     std::string name = "image: url(:/cards/";
     if(value == NINE) name+="9";
     if(value == JACK) name+="J";
     if(value == QUEEN) name+="Q";
     if(value == KING) name+="K";
     if(value == TEN) name+="10";
     if(value == ACE) name+="A";
     if(suit == SPADE) name+="S";
     if(suit == CLUB) name+="C";
     if(suit == DIAMOND) name+="D";
     if(suit == HEART) name+="H";
     name +=".png);";
     return name;
 }
