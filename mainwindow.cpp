#include "game.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

Game game;
std::vector<Card> cards_on_table;
std::string name = "Player";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    state = 0;
    ui->setupUi(this);

    ui->START_BUTTON->click();
    ui->PICK_1->hide();
    ui->PICK_2->hide();
    ui->PICK_3->hide();
    ui->PICK_4->hide();
    ui->PICK_5->hide();
    ui->PICK_6->hide();
    ui->PICK_7->hide();
    ui->PICK_8->hide();
    ui->PICK_9->hide();
    ui->PICK_10->hide();
    //    ;
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_NEW_ROUND_BUTTON_clicked()
{

    int won = -1;
    if(game.players[0].get_points() >= 1000){
        won = 0;
    }
    if(game.players[1].get_points() >= 1000){
        won = 1;
    }
    if(game.players[2].get_points() >= 1000){
        won = 2;
    }
    if(won!=-1){
        ui->won_button->click();
        ui->player_name_label->setText(QString::fromStdString(game.players[won].name));
        ui->is_playing_for_label->setText("WON!!!");

        return;
    }
    game.deck = Deck();
    game.give_cards();
    game.current_bidder = first_player;
    first_player = (first_player+1)%3;
    game.current_bid = 100;
    ui->SI_1_round_points->setText(QString::number(0));
    ui->SI_2_round_points->setText(QString::number(0));
    ui->Player_round_points->setText(QString::number(0));
    print_hand();
    QString s = QString::number(game.current_bid);
    ui->bid_label->setText(s);
    ui->bidder_label->setText(QString::fromStdString(game.players[game.current_bidder].name));
    if(game.players[1].pass){
        ui->SI_1_bidding_label->setText("passed");
    }
    if(game.players[2].pass){
        ui->SI_2_bidding_label->setText("passed");
    }
    if(game.players[1].pass && game.players[2].pass){
        prepare_bid_value(0);
    }
}
void MainWindow::print_hand(){
    std::vector<std::string> std_names = game.players[0].get_file_names();
    if(std_names.size()>=1){
        ui->card_frame_1->setStyleSheet(QString::fromStdString(std_names[0]));
    }
    else{
         ui->card_frame_1->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=2){
        ui->card_frame_2->setStyleSheet(QString::fromStdString(std_names[1]));
    }
    else{
         ui->card_frame_2->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=3){
        ui->card_frame_3->setStyleSheet(QString::fromStdString(std_names[2]));
    }
    else{
         ui->card_frame_3->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=4){
        ui->card_frame_4->setStyleSheet(QString::fromStdString(std_names[3]));
    }
    else{
         ui->card_frame_4->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=5){
        ui->card_frame_5->setStyleSheet(QString::fromStdString(std_names[4]));
    }
    else{
         ui->card_frame_5->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=6){
        ui->card_frame_6->setStyleSheet(QString::fromStdString(std_names[5]));
    }
    else{
         ui->card_frame_6->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=7){
        ui->card_frame_7->setStyleSheet(QString::fromStdString(std_names[6]));
    }
    else{
         ui->card_frame_7->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=8){
        ui->card_frame_8->setStyleSheet(QString::fromStdString(std_names[7]));
    }
    else{
         ui->card_frame_8->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=9){
        ui->card_frame_9->setStyleSheet(QString::fromStdString(std_names[8]));
    }
    else{
         ui->card_frame_9->setStyleSheet("color: rgb(190, 190, 190);");
    }
    if(std_names.size()>=10){
        ui->card_frame_10->setStyleSheet(QString::fromStdString(std_names[9]));
    }
    else{
         ui->card_frame_10->setStyleSheet("color: rgb(190, 190, 190);");
    }
}

void MainWindow::print_pick(bool hide = false){
    std::vector<std::string> std_names;
    if(!hide){
        std_names = game.players[0].get_file_names();
    }
    if(std_names.size()>=1){
        ui->PICK_1->show();
    }
    else{
         ui->PICK_1->hide();
    }
    if(std_names.size()>=2){
        ui->PICK_2->show();
    }
    else{
         ui->PICK_2->hide();
    }
    if(std_names.size()>=3){
        ui->PICK_3->show();
    }
    else{
         ui->PICK_3->hide();
    }
    if(std_names.size()>=4){
        ui->PICK_4->show();
    }
    else{
         ui->PICK_4->hide();
    }
    if(std_names.size()>=5){
        ui->PICK_5->show();
    }
    else{
         ui->PICK_5->hide();
    }
    if(std_names.size()>=6){
        ui->PICK_6->show();
    }
    else{
         ui->PICK_6->hide();
    }
    if(std_names.size()>=7){
        ui->PICK_7->show();
    }
    else{
         ui->PICK_7->hide();
    }
    if(std_names.size()>=8){
        ui->PICK_8->show();
    }
    else{
         ui->PICK_8->hide();
    }
    if(std_names.size()>=9){
        ui->PICK_9->show();
    }
    else{
         ui->PICK_9->hide();
    }
    if(std_names.size()>=10){
        ui->PICK_10->show();
    }
    else{
         ui->PICK_10->hide();
    }
}

void MainWindow::on_START_BUTTON_clicked()
{
    game.start(name);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    name = arg1.toStdString();
    ui->player_name_label->setText(arg1);
}



void MainWindow::on_raise_by_10_button_clicked()
{
    game.current_bidder = 0;
    int won = game.make_bids(game.current_bid+10);
    if(game.players[1].pass){
        ui->SI_1_bidding_label->setText("passed");
    }
    if(game.players[2].pass){
        ui->SI_2_bidding_label->setText("passed");
    }
    if(won>=0){
        prepare_bid_value(won);
    }

    QString s = QString::number(game.current_bid);
    ui->bid_label->setText(s);
    ui->bidder_label->setText(QString::fromStdString(game.players[game.current_bidder].name));

}


void MainWindow::on_pass_button_clicked()
{
    int won = game.make_bids(-1);
    if(game.players[1].pass){
        ui->SI_1_bidding_label->setText("passed");
    }
    if(game.players[2].pass){
        ui->SI_2_bidding_label->setText("passed");
    }
    if(won>=0){
        prepare_bid_value(won);
    }
    QString s = QString::number(game.current_bid);
    ui->bid_label->setText(s);
    ui->bidder_label->setText(QString::fromStdString(game.players[game.current_bidder].name));
}


void MainWindow::prepare_bid_value(int player){
    ui->raise_by_10_button->hide();
    ui->pass_button->hide();
    ui->SI_1_bidding_label->hide();
    ui->SI_2_bidding_label->hide();
    ui->bid_label->hide();
    ui->bidder_label->hide();
    ui->current_bid_name_label->hide();
    ui->current_bidder_name_label->hide();

    ui->is_playing_for_label->show();
    ui->is_playing_for_value->show();
    ui->player_name_label->show();
    ui->player_label->show();


    if(player == 0){
        game.give_remaining_cards();
        print_hand();
        ui->raise_amount_by_10_button->show();
        ui->Play_selected_bid_button->show();
    }
    else{
        game.current_bid = game.players[game.current_bidder].set_value(game.current_bid);
        ui->is_playing_for_value->setText(QString::number(game.current_bid));
        ui->player_name_label->setText(QString::fromStdString(game.players[game.current_bidder].name));
        prepare_round(player);
    }

    ui->is_playing_for_value->setText(QString::number(game.current_bid));
    ui->player_name_label->setText(QString::fromStdString(game.players[game.current_bidder].name));
}

void MainWindow::on_raise_amount_by_10_button_clicked()
{
    game.current_bid+=10;
    ui->is_playing_for_value->setText(QString::number(game.current_bid));
}

void MainWindow::prepare_round(int player){
    if(player != 0){
    game.give_remaining_cards();
    print_hand();
    ui->next_trick_button->show();
    }
    ui->card_on_table_SI_1->show();
    ui->card_on_table_SI_2->show();
    ui->card_on_table_player->show();
    ui->TRUMP_FRAME->show();
    game.round_points[0] = 0;
    game.round_points[1] = 0;
    game.round_points[2] = 0;
    trick_winner = player;
    trump = -1;


}

void MainWindow::on_Play_selected_bid_button_clicked()
{

    ui->raise_amount_by_10_button->hide();
    ui->Play_selected_bid_button->hide();

    state = 1;
    print_pick();
    prepare_round(0);


}

void MainWindow::handle_trick(int starting_player){

    cards_on_table.clear();
    pot = 0;

    if(starting_player == 1){
        cards_on_table.push_back(game.players[starting_player].get_trick_start(trump));
        ui->card_on_table_SI_1->setStyleSheet(QString::fromStdString(cards_on_table[0].get_file_name()));
        pot+=cards_on_table[0].value;
        if(game.players[starting_player].call){
            ui->TRUMP_FRAME->setStyleSheet(QString::fromStdString(cards_on_table[0].get_file_name()));
            trump = cards_on_table[0].suit;
            game.round_points[starting_player] += cards_on_table[0].suit;
        }
        cards_on_table.push_back(game.players[(starting_player+1)%3].get_response_card(cards_on_table[0].suit, cards_on_table[0].value, trump, cards_on_table[0].suit));
        ui->card_on_table_SI_2->setStyleSheet(QString::fromStdString(cards_on_table[1].get_file_name()));
        pot+=cards_on_table[1].value;
    }
    else if(starting_player == 2){
        cards_on_table.push_back(game.players[starting_player].get_trick_start(trump));
        ui->card_on_table_SI_2->setStyleSheet(QString::fromStdString(cards_on_table[0].get_file_name()));
        pot+=cards_on_table[0].value;
        if(game.players[starting_player].call){
            ui->TRUMP_FRAME->setStyleSheet(QString::fromStdString(cards_on_table[0].get_file_name()));
            trump = cards_on_table[0].suit;
            game.round_points[starting_player] += cards_on_table[0].suit;
        }
    }
    state = 4;
    print_pick();
    return;
}
void MainWindow::end_trick_handle(int starting_player){
//    ui->player_turn->hide();
    if(starting_player == 0){
        pot+=cards_on_table[0].value;
        if((cards_on_table[0].value == QUEEN || cards_on_table[0].value == KING) && game.players[starting_player].check_marriage(cards_on_table[0].suit)) {
            ui->TRUMP_FRAME->setStyleSheet(QString::fromStdString(cards_on_table[0].get_file_name()));
            trump = cards_on_table[0].suit;
            game.round_points[starting_player] += cards_on_table[0].suit;

        }
        Card first = cards_on_table[0];
        cards_on_table.push_back(game.players[(starting_player+1)%3].get_response_card(cards_on_table[0].suit, cards_on_table[0].value, trump, cards_on_table[0].suit));
        Card second = cards_on_table[1];
        ui->card_on_table_SI_1->setStyleSheet(QString::fromStdString(cards_on_table[1].get_file_name()));
        if(game.higher(first, second, trump)){
            Card third = game.players[(starting_player+2)%3].get_response_card(first.suit, first.value, trump, first.suit);
            cards_on_table.push_back(third);
            ui->card_on_table_SI_2->setStyleSheet(QString::fromStdString(cards_on_table[2].get_file_name()));

    //        std::cout<<"Player "<<game.players[(starting_player+2)%3].name <<" : "
            pot+=third.value;
            if(game.higher(first, third, trump)) trick_winner = starting_player;
            else trick_winner = (starting_player+2)%3;
        }
        else{
            Card third = game.players[(starting_player+2)%3].get_response_card(second.suit, second.value, trump, first.suit);
            cards_on_table.push_back(third);
            ui->card_on_table_SI_2->setStyleSheet(QString::fromStdString(cards_on_table[2].get_file_name()));
    //        std::cout<<"Player "<<game.players[(starting_player+2)%3].name <<" : ";
            pot+=third.value;
            if(game.higher(second, third, trump)) trick_winner = (starting_player+1)%3;
            else trick_winner = (starting_player+2)%3;
        }

    }
    if(starting_player == 2){
        pot+=cards_on_table[1].value;
        Card first = cards_on_table[0];
        Card second = cards_on_table[1];
        if(game.higher(first, second, trump)){
            Card third = game.players[(starting_player+2)%3].get_response_card(first.suit, first.value, trump, first.suit);
            cards_on_table.push_back(third);
            ui->card_on_table_SI_1->setStyleSheet(QString::fromStdString(cards_on_table[2].get_file_name()));

            pot+=third.value;
            if(game.higher(first, third, trump)) trick_winner = starting_player;
            else trick_winner = (starting_player+2)%3;
        }
        else{
            Card third = game.players[(starting_player+2)%3].get_response_card(second.suit, second.value, trump, first.suit);
            cards_on_table.push_back(third);
            ui->card_on_table_SI_1->setStyleSheet(QString::fromStdString(cards_on_table[2].get_file_name()));
            pot+=third.value;
            if(game.higher(second, third, trump)) trick_winner = (starting_player+1)%3;
            else trick_winner = (starting_player+2)%3;
        }
    }
    if(starting_player == 1){
        pot+=cards_on_table[2].value;
        if(game.higher(cards_on_table[0], cards_on_table[1], trump)){
            if(game.higher(cards_on_table[0], cards_on_table[2], trump)){
                trick_winner = starting_player;
            } else{
                trick_winner = (starting_player + 2)%3;
            }
        }
        else{
            if(game.higher(cards_on_table[1], cards_on_table[2], trump)){
                trick_winner = (starting_player + 1)%3;
            }
            else{
                trick_winner = (starting_player + 2)%3;
            }
        }
    }
    pot = cards_on_table[0].value + cards_on_table[1].value + cards_on_table[2].value;
    game.round_points[trick_winner] += pot;
    ui->SI_1_round_points->setText(QString::number(game.round_points[1]));
    ui->SI_2_round_points->setText(QString::number(game.round_points[2]));
    ui->Player_round_points->setText(QString::number(game.round_points[0]));
    ui->SI_1_turn->hide();
    ui->player_turn->hide();
    ui->SI_2_turn->hide();
    if(trick_winner == 0){
        ui->player_turn->show();
    }
    if(trick_winner == 1){
        ui->SI_1_turn->show();
    }
    if(trick_winner == 2){
        ui->SI_2_turn->show();
    }

     ui->next_trick_button->show();
}

void MainWindow::resolve_round(){


    if(game.round_points[game.current_bidder] >= game.current_bid){
        game.players[game.current_bidder].add_points(game.current_bid, true);
    }
    else{
        game.players[game.current_bidder].add_points(-game.current_bid,false);
    }
    game.players[(game.current_bidder +1)%3].add_points( game.round_points[(game.current_bidder +1)%3],false);
    game.players[(game.current_bidder +2)%3].add_points( game.round_points[(game.current_bidder +2)%3],false);
    game.round_points[0] = 0;
    game.round_points[1] = 0;
    game.round_points[2] = 0;
    ui->player_points->setText(QString::number(game.players[0].get_points()));
    ui->SI_1_points->setText(QString::number(game.players[1].get_points()));
    ui->SI_2_points->setText(QString::number(game.players[2].get_points()));
    ui->NEW_ROUND_BUTTON->show();
    ui->is_playing_for_label->hide();
    ui->is_playing_for_value->hide();
    ui->player_label->hide();
    ui->player_name_label->hide();
    ui->card_on_table_SI_1->setStyleSheet("color: rgb(190, 190, 190);");
    ui->card_on_table_SI_2->setStyleSheet("color: rgb(190, 190, 190);");
    ui->card_on_table_player->setStyleSheet("color: rgb(190, 190, 190);");
    ui->card_on_table_SI_1->hide();
    ui->card_on_table_SI_2->hide();
    ui->card_on_table_player->hide();
    ui->SI_1_turn->hide();
    ui->SI_2_turn->hide();
    ui->player_turn->hide();
    ui->TRUMP_FRAME->setStyleSheet("color: rgb(190, 190, 190);");
}






void MainWindow::on_PICK_1_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(1));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(1));
        state = 3;
        ui->next_trick_button->show();
    }
    else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(1));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_2_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(2));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(2));
        state = 3;
        ui->next_trick_button->show();
    }
    else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(2));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_3_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(3));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(3));
        state = 3;
        ui->next_trick_button->show();
    }
    else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(3));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_4_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(4));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(4));
        state = 3;
        ui->next_trick_button->show();
    }else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(4));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_5_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(5));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(5));
        state = 3;
        ui->next_trick_button->show();
    }else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(5));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_6_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(6));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(6));
        state = 3;
        ui->next_trick_button->show();
    }else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(6));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_7_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(7));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(7));
        state = 3;
        ui->next_trick_button->show();
    }else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(7));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_8_clicked()
{
    if(state != 1 && state != 2 && state !=4 ){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(8));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(8));
        state = 3;
        ui->next_trick_button->show();
    }else if(state ==4){
        cards_on_table.push_back(game.players[0].get_number_card(8));
        state = 3;
        ui->card_on_table_player->setStyleSheet(QString::fromStdString(cards_on_table[cards_on_table.size()-1].get_file_name()));
        end_trick_handle(trick_winner);
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_9_clicked()
{
    if(state != 1 && state != 2){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(9));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(9));
        state = 3;
        ui->next_trick_button->show();
    }
    print_hand();
    print_pick(state==3);
}
void MainWindow::on_PICK_10_clicked()
{
    if(state != 1 && state != 2){
        return;
    }
    if(state == 1){
        game.players[1].add_card(game.players[0].get_number_card(10));
        state = 2;
    }
    else if(state ==2){
        game.players[2].add_card(game.players[0].get_number_card(10));
        state = 3;
        ui->next_trick_button->show();
    }
    print_hand();
    print_pick(state==3);
}


void MainWindow::on_next_trick_button_clicked()
{
    if(game.players[0].size() >0){
    ui->card_on_table_player->setStyleSheet("color: rgb(190, 190, 190);");
    ui->card_on_table_SI_1->setStyleSheet("color: rgb(190, 190, 190);");
    ui->card_on_table_SI_2->setStyleSheet("color: rgb(190, 190, 190);");
    handle_trick(trick_winner);
    }
    else{
        resolve_round();
    }
}
