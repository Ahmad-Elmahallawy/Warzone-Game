#include "Cards.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void testCards() {
    Deck* deck = new Deck();

    Hand* hand = new Hand();

    Card* card1 = deck -> draw();
    Card* card2 = deck -> draw();
    Card* card3 = deck -> draw();
    Card* card4 = deck -> draw();
    Card* card5 = deck -> draw();

    hand-> returnCard(*card1);
    hand-> returnCard(*card2);
    hand-> returnCard(*card3);
    hand-> returnCard(*card4);
    hand-> returnCard(*card5);

//method just to make sure our hand gets cards
    cout << "The hand currently has:" << endl;
    hand-> displayHand();

    deck->getDeckSize();

    int handSize = hand->getCard().size();

//looping to play all cards randomly until the hand is empty

    for(size_t i = 0; i < handSize; i++) {
        srand (time(0));
        int randomNum = rand() % hand->getCard().size();
        cout << randomNum << " batee5" << endl;
        hand -> getCard()[randomNum]->play(randomNum, *hand, *deck);
        hand->displayHand();
    }

    deck->getDeckSize();
    hand -> getHandSize();
    hand -> displayHand();

    delete deck;
    delete hand;
    delete card1, card2, card3, card4, card5;
}