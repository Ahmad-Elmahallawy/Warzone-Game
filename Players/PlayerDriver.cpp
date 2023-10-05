#include "Player.h"
using namespace std;

void testPlayer()
{
    cout << "SETTING UP PLAYER'S" << endl;
    cout << "***********************************************************\n" << endl;
    cout << "PLAYER 1" << endl;
    Player* p1 = new Player();
    cout << endl;

//    cout << "***********************************************************" << endl;
//    cout << "\nASSIGNING CARDS TO PLAYER 1" << endl;
//    cout << "PLAYER 1 WILL HOLD THE FOLLOWING CARDS IN HIS HAND" << endl;
//    for (int i=0; i < p1->getHand()->HandCards.size(); i++) {
//        cout << p1->getHand()->HandCards[i]->getCardType() <<endl;
//    }


    cout << "\nPLAYER 1'S COMMANDS" << endl;
    cout << "***********************************************************" << endl;
    p1->issueOrder();
    p1->issueOrder();
    p1->issueOrder();

    cout << endl;

    cout << "\nPLAYER 1'S ATTACK LIST" << endl;
    cout << "***********************************************************" << endl;
    p1->toAttack();
    cout << "***********************************************************" << endl;

    cout << "\nPLAYER 1'S DEFEND LIST" << endl;
    cout << "***********************************************************" << endl;
    p1->toDefend();

}
