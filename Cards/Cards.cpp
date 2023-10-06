#include "Cards.h"
#include <iostream>
#include <stdlib.h>

//constructor
Card::Card() {}

//destructor
Card:: ~Card() {}

//constructor with Warzone card parameter
Card::Card(WarzoneCard card) {
    this-> card1 = card;
}

// compy constructor
Card::Card(const Card& card) {
    this-> card1 = card.card1;
}

// operator that assigns a new value to an exisiting object
Card& Card::operator=(const Card& card) {
    this-> card1 = card.card1;
}

//getter method return the card
Card::WarzoneCard Card::getCard() const {
    return this-> card1;
}

// play method
void Card::play(int card, Hand& hand, Deck& deck) {
    Card* cardToRemove = hand.removeFromHand(card);
    deck.returnCard(*cardToRemove);
}


Deck::Deck() {

    for (size_t x = 0; x < 5; x++) {
        vectorDeck.push_back(new Card(Card::WarzoneCard::Bomb));
        vectorDeck.push_back(new Card(Card::WarzoneCard::Reinforcement));
        vectorDeck.push_back(new Card(Card::WarzoneCard::Blockade));
        vectorDeck.push_back(new Card(Card::WarzoneCard::Airlift));
        vectorDeck.push_back(new Card(Card::WarzoneCard::Diplomacy));
    }
}

Deck::~Deck() {}

Deck::Deck(const Deck& deck) {
    for(size_t i = 0; i < deck.vectorDeck.size(); i++) {
        this -> vectorDeck.push_back(new Card(*deck.vectorDeck[i]));
    }
}

Deck& Deck::operator=(const Deck& deck) {
    vectorDeck = deck.vectorDeck;
    return *this;
}

Card* Deck::draw() {

    if(vectorDeck.empty()) {
        std:: cout << "No more cards are in the deck.";
        return 0;
    }
    else {
        int size = vectorDeck.size();
        int randomNum = rand() % size;
        Card* card = vectorDeck.at(randomNum);
        vectorDeck.erase(vectorDeck.begin() + randomNum);
        return card;
    }
}

Card* Deck::removeCard(int i) {

    Card* card = vectorDeck.at(i);

    for(size_t x = 0; x < vectorDeck.size(); x++) {
        if(i == x)
            vectorDeck.erase(vectorDeck.begin() + i);
    }
    return card;
}

void Deck::returnCard(Card& card) {
    this -> vectorDeck.push_back(&card);
}

vector<Card*> Deck::getCard()
{
    return this->vectorDeck;
}

Hand::Hand() {}

Hand::~Hand() {
    for(int i = 0; i < vectorHand.size(); i++) {
        delete vectorHand.at(i);
    }
}

Hand::Hand(const Hand& hand) {
    for(size_t i = 0; i < hand.vectorHand.size(); i++) {
        this -> vectorHand.push_back(new Card(*hand.vectorHand[i]));
    }
}

Hand& Hand::operator=(const Hand& hand) {
    this -> vectorHand = hand.vectorHand;
}

vector<Card*> Hand::getCard() {
    return this -> vectorHand;
}

Card* Hand::removeFromHand(int i) {
    Card* card = vectorHand.at(i);

    for(size_t x = 0; x < vectorHand.size(); x++) {
        if(x == i)
            vectorHand.erase(vectorHand.begin() + i);
    }
    return card;
}

void Hand::returnCard(Card& card) {
    this -> vectorHand.push_back(&card);
}

void Hand::displayHand() {
    if(vectorHand.empty())
        std :: cout << "The hand is empty." << endl;
    else {
        for(size_t i = 0; i < vectorHand.size(); i++) {
            if (i == vectorHand.size() - 1)
                std:: cout << vectorHand.at(i) -> getCard() << " " << endl;
            else
                std:: cout << vectorHand.at(i) -> getCard() << ", " << endl;

        }
    }
}

