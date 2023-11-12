//
// Created by khale on 2023-11-10.
//

#include "LoggingObserver.h"
#include "../Orders/Orders.h"
#include "../Command/CommandProcessor.h"
#include "../GameEngine.h"
#include "../Map/Map.h"
#include "../Cards/Cards.h"

void testLoggingObserver() {
    GameEngine* ge1 = new GameEngine();
    cout << stateToString(ge1->getCurrentState());


    LoggingObserver* o1 = new LoggingObserver(ge1->getCommandProcessor());
    LoggingObserver* o2 = new LoggingObserver(ge1);

    ge1->transition(ge1->getCommandProcessor()->getEnumCommands());
    ge1->transition(ge1->getCommandProcessor()->getEnumCommands());



    Player p1;
    Player p2;

    Territory* t1 = new Territory();
    Territory* t2 = new Territory();
    Territory* t3 = new Territory();
    Territory* t4 = new Territory();

    t1->setTerritoryName("bahaa");
    t2->setTerritoryName("waw");
    t3->setTerritoryName("neehaw");
    t4->setTerritoryName("lil");

    p1.setTerritories(t1);
    p1.setTerritories(t4);
    p2.setTerritories(t2);
    p2.setTerritories(t3);

    OrdersList temp = p1.getOrdersList();
    OrdersList temp2 = p2.getOrdersList();
    LoggingObserver* log2 = new LoggingObserver(&temp);

    Order* deploy = new Deploy();
    Order* blockade = new Blockade();
    Order* advance = new Advance();
    Order* airlift = new Airlift();
    Order* negotiate = new Negotiate();
    Order* bomb = new Bomb();

    LoggingObserver* log3 = new LoggingObserver(deploy);
    LoggingObserver* log4 = new LoggingObserver(blockade);
    LoggingObserver* log5 = new LoggingObserver(advance);
    LoggingObserver* log6 = new LoggingObserver(airlift);
    LoggingObserver* log7 = new LoggingObserver(negotiate);
    LoggingObserver* log8 = new LoggingObserver(bomb);

    temp.addOrder(deploy);
    temp.addOrder(blockade);
    temp.addOrder(advance);
    temp2.addOrder(airlift);
    temp2.addOrder(negotiate);
    temp2.addOrder(bomb);

    Card* c1 = new Card(Card::Bomb);
    Card* c2 = new Card(Card::Blockade);
    Card* c3 = new Card(Card::Airlift);
    Card* c4 = new Card(Card::Diplomacy);

    Hand* h1 = p1.getHand();
    h1->returnCard(*c1);
    h1->returnCard(*c2);
    h1->returnCard(*c3);
    h1->returnCard(*c4);

    deploy->execute();
    blockade->execute();
    advance->execute();
    bomb->execute();
    airlift->execute();
    negotiate->execute();

}
