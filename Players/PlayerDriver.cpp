//#include "Player.h"
//using namespace std;
//
//int testPlayers()()
//{
//    cout << "\n***********************************************************" << endl;
//    cout << "CREATING TERRITORIES" << endl;
//    cout << "***********************************************************\n" << endl;
//    Territory* t1 = new Territory();
//    t1->setPlayerID(1);
//    t1->setTerritoryID(1);
//    t1->setTerritoryName("Wadiya");
//    t1->setContinentName("Aladeen");
//    t1->setNumOfArmies(3);
//    t1->displayTerritory();
//    cout << "\n" << endl;
//    Territory* t2 = new Territory();
//    t2->setTerritoryPlayerID(1);
//    t2->setTerritoryID(2);
//    t2->setTerritoryName("China");
//    t2->setContinentName("Asia");
//    t2->setNumOfArmies(3);
//    t2->displayTerritory();
//    cout << "\n" << endl;
//    Territory* t3 = new Territory();
//    t3->setTerritoryPlayerID(1);
//    t3->setTerritoryID(3);
//    t3->setTerritoryName("Philippines");
//    t3->setContinentName("Asia");
//    t3->setNumOfArmies(3);
//    t3->displayTerritory();
//    cout << "\n" << endl;
//    Territory* t4 = new Territory();
//    t4->setTerritoryPlayerID(1);
//    t4->setTerritoryID(4);
//    t4->setTerritoryName("Bangladesh");
//    t4->setContinentName("Asia");
//    t4->setNumOfArmies(3);
//    t4->displayTerritory();
//    cout << "\n" << endl;
//    Territory* t5 = new Territory();
//    t5->setTerritoryPlayerID(1);
//    t5->setTerritoryID(5);
//    t5->setTerritoryName("Afghanistan");
//    t5->setContinentName("Asia");
//    t5->setNumOfArmies(3);
//    t5->displayTerritory();
//    cout << "\n" << endl;
//    Territory* t6 = new Territory();
//    t6->setTerritoryPlayerID(1);
//    t6->setTerritoryID(6);
//    t6->setTerritoryName("Morocco");
//    t6->setContinentName("Africa");
//    t6->setNumOfArmies(3);
//    t6->displayTerritory();
//    cout << "\n***********************************************************" << endl;
//    cout << "CREATING MAP" << endl;
//    cout << "***********************************************************\n" << endl;
//    Map* m1 = new Map();
//    m1->setName("Player 1's map");
//    m1->Territories.push_back(t1);
//    m1->Territories.push_back(t2);
//    m1->Territories.push_back(t3);
//    m1->Territories.push_back(t4);
//    m1->Territories.push_back(t5);
//    m1->Territories.push_back(t6);
//    cout << "\n***********************************************************" << endl;
//    cout << "SETTING UP PLAYER'S" << endl;
//    cout << "***********************************************************\n" << endl;
//    cout << "PLAYER 1" << endl;
//    Player* p1 = new Player();
//    Deck *d1 = new Deck();
//    d1->initializeDeck();
//
//    Hand *h1 = new Hand();
//    p1->setHand(h1);
//    d1->draw(h1);
//    d1->draw(h1);
//    d1->draw(h1);
//    d1->draw(h1);
//    d1->draw(h1);
//    d1->draw(h1);
//
//    cout << endl;
//
//    cout << "ASSIGNING MAP TO PLAYER 1" << endl;
//    cout << "PLAYER 1 WILL CONTROL THE FOLLOWING TERRITORIES" << endl;
//    cout << "***********************************************************" << endl;
//    p1->setTerritoryList(m1->Territories);
//    p1->printTerritoryList();
//
//    cout << "***********************************************************" << endl;
//    cout << "\nASSIGNING CARDS TO PLAYER 1" << endl;
//    cout << "PLAYER 1 WILL HOLD THE FOLLOWING CARDS IN HIS HAND" << endl;
//    for (int i=0; i < p1->getHand()->HandCards.size(); i++) {
//        cout << p1->getHand()->HandCards[i]->getCardType() <<endl;
//    }
//
//    cout << "***********************************************************" << endl;
//    cout << "\nPLAYER 1'S COMMANDS" << endl;
//    cout << "***********************************************************" << endl;
//    p1->issueOrder("bomb");
//    p1->issueOrder("trap");
//    p1->issueOrder("deploy");
//    p1->issueOrder("negotiate");
//    p1->issueOrder("missile");
//    p1->issueOrder("advance");
//    cout << "***********************************************************" << endl;
//
//    cout << "\nPLAYER 1'S ATTACK LIST" << endl;
//    cout << "***********************************************************" << endl;
//    p1->toAttack();
//    p1->printAttackList();
//    cout << "***********************************************************" << endl;
//
//    cout << "\nPLAYER 1'S DEFEND LIST" << endl;
//    cout << "***********************************************************" << endl;
//    p1->toDefend();
//    p1->printDefendList();
//    cout << "***********************************************************" << endl;
//
//    return 0;
//}