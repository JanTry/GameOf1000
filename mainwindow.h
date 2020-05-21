#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "game.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void print_hand();
    void print_pick(bool);

    void prepare_bid_value(int);

    void on_NEW_ROUND_BUTTON_clicked();

    void on_START_BUTTON_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_raise_by_10_button_clicked();


    void on_pass_button_clicked();

    void on_raise_amount_by_10_button_clicked();

    void on_Play_selected_bid_button_clicked();

    void end_trick_handle(int starting_player);

    void prepare_round(int);

    void handle_trick(int starting_player);

    void resolve_round();

    void on_PICK_1_clicked();
    void on_PICK_2_clicked();
    void on_PICK_3_clicked();
    void on_PICK_4_clicked();
    void on_PICK_5_clicked();
    void on_PICK_6_clicked();
    void on_PICK_7_clicked();
    void on_PICK_8_clicked();
    void on_PICK_9_clicked();
    void on_PICK_10_clicked();

    void on_next_trick_button_clicked();

private:
    int state = 0;
    int trick_winner = 0;
    int pot = 0;
    int trump = -1;
    int first_player = 0;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
