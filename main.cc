#include "imports.h"
#include "game.h"


using std::cout;
using std::endl;

int main(){

    Game gra_testowa;
    std::string Player_name;
    std::cout<<"Insert your name: ";
    std::cin>>Player_name;
    gra_testowa.start(Player_name);


    cout<<"\n\n\nDONE\n\n\n";


}
