#include <stdlib.h>
#include <iostream>
#include "Cards.h"

using namespace std;

void testCards() {
    Deck *deck = new Deck();

    Hand *hand = new Hand();

    Card *card1 = deck->draw();
    Card *card2 = deck->draw();
    Card *card3 = deck->draw();
    Card *card4 = deck->draw();
    Card *card5 = deck->draw();

    hand->returnCard(*card1);
    hand->returnCard(*card2);
    hand->returnCard(*card3);
    hand->returnCard(*card4);
    hand->returnCard(*card5);
    cout << *hand << endl;

//method just to make sure our hand gets cards

    deck->getDeckSize();

    int handSize = hand->getCard().size();

//looping to play all cards randomly until the hand is empty

    for (size_t i = 0; i < handSize; i++) {
        srand(time(0));
        int randomNum = rand() % hand->getCard().size();
        hand->getCard()[randomNum]->play(randomNum, *hand, *deck);
    }

    deck->getDeckSize();
    hand->getHandSize();
    cout << *hand << endl;

    delete deck;
    delete hand;
    delete card1;
    delete card2;
    delete card3;
    delete card4;
    delete card5;
}