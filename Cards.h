#ifndef CARDS_H
#define CARDS_H
#include <vector>

using namespace std;
class Deck;
class Hand;

class Card {
public:
    enum WarzoneCard {  Bomb,  Reinforcement, Blockade, Airlift, Diplomacy, end };

// constructor
    Card(); 

//destructor for cards
    ~Card();

//constructor that takes a WarzoneCard parameter
    Card(WarzoneCard wc);

//copy constructor initialied used to copy exisiting object     
    Card(const Card&); 


    Card& operator=(const Card&);

// getter method
    WarzoneCard getCard() const;

//the play method that removes a card from the hand and returns it to the deck
    void play(int card, Hand& h, Deck& d); 

//friend ostream& operator<<(ostream& display, const Card&);

private:
    WarzoneCard card1;
};

class Deck {

public:

//constructor
    Deck();
    ~Deck(); 
    Deck(const Deck& d);
    Deck& operator=(const Deck& d);

// returns a copy of the vector of pointers that make up the deck
    vector<Card*>getCard();

//randomly draws a card from the deck and it puts it in the hand
    Card* draw();

//used in the draw and play methods to remove a card from hand
    Card* removeCard(int i);

//returns a card to deck 
    void returnCard(Card& c);

//friend ostream& operator<<(ostream& display, const Deck& d);

private:

    vector<Card*> vectorDeck;
};

class Hand {

public:

    Hand();
    ~Hand();
    Hand(const Hand& h);
    Hand& operator=(const Hand&);

    vector<Card*>getCard();

//used in the draw and play methods to remove card from hand
    Card* removeFromHand(int i);

//returns card to the hand vector
    void returnCard(Card& c);

//to show/print hand cards
void displayHand();

//friend ostream& operator<<(ostream& display, const Hand& h);

private:
    vector<Card*> vectorHand;

};

void testCards();

#endif //CARDS_H
