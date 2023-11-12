// part 2
// this is the Players.cpp file where all the definitions are done
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Players/Player.h"
#include "../Orders/Orders.h"
#include "../Cards/Cards.h"
using namespace std;
// default constructor
int Player:: playerId = 1;
Player::Player() {
    this->hand = new Hand();
    this->territories = {new Territory(), new Territory()};
    this->playerName = "no name";
    this->ordersList = new orderlist();
}

Player::Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, int playerId,
               orderlist *ordersList) : hand(hand), territories(territories), playerName(playerName),
                                         playerID(playerId), ordersList(ordersList) {}

// copy constructor
Player::Player(Player &player) {
    this->playerId = player.playerId;
    this->terriortiesOwned = player.terriortiesOwned;
    for (int i = 0; i <
                    terriortiesOwned.size(); i++) {// for loop to copy all terriorties owned that player has to the other play terriorties
        terriortiesOwned[i] = player.terriortiesOwned[i];
    }
    this->ordersList = player.ordersList;
    this->hand = player.hand;
   // this->ps = player.ps;
    reinforcementPool = 0;
    this->armyUnits = 0;
}

Player::~Player() {
    id = playerId++;// increasing the player id
    cout << "id " << id << endl;
    terriortiesOwned = {};// empty vector
    reinforcementPool = 0;

}

// returns player's territories
vector <Territory*> Player:: getterriortiesOwned() {// returns the terriorties owned
    return terriortiesOwned;
}
// setsTerritories
void Player::setTerritories(const vector<Territory *> &territories) {
    Player::territories = territories;
}

// returns player name
const string &Player::getPlayerName() const {
    return playerName;
}
// sets Player's name
void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

// return's user's orderlist
orderlist& Player::getOrdersList(){
    std::cout << "\nthe orderlist contains :" << std::endl;
    return *ordersList;
}

// returns player hand
Hand* Player::getHand() const
{
    return  this->hand;
}
// sets player's hand
void Player::setHand(Hand *hand) {
    Player::hand = hand;
}
vector<Card *> Player::getCard() {
    // Assuming you have a Hand class, get a card from the hand
    return hand->getCard();
}
int Player:: getPlayerID() {// getter for playerID
    return id;
}

void Player::setTerriorty(vector <Territory*> terriorties) {// setter for terriorties owned
    this->terriortiesOwned= terriorties;
}
void Player::addTerriorty(Territory* Territory) {//adds a terriorty to the player terriortiesowned
    terriortiesOwned.push_back(Territory);
    Territory->setOwner(this);
}
// creates a new order
void Player::issueOrder() {
    order *order = new deploy(*new deploy());
    cout << "player 1 player has issued an order\n";
    ordersList->addOrder(order);

}
void Player::removeTerritory(int index)
{
    cout << " this the index "<< index<< " that will be removed "<<endl;
    if (index == 0) {
        terriortiesOwned.erase(terriortiesOwned.begin());
    }
    else {
        terriortiesOwned.erase(terriortiesOwned.begin() + index);
        cout << this->getName() << " got territories erased" << endl;
        for (int x = 0; x < terriortiesOwned.size();x++) {
            cout << terriortiesOwned[x]->getName()<<endl;
        }
    }
    //this->terriortiesOwned.pop_back();
}
void Player::addnegotiationlist(Player *p)
{
    negotiateList.push_back(p);
}
void Player::clearnegotiationlist()
{
    for (int i = 0; i < negotiateList.size(); i++) {
        negotiateList.pop_back();
    }
}
vector<Player*> Player::getnegotiateList() //getter for negotiate list
{
    return this->negotiateList;
}

string Player::getName()
{
    return name;
}

void Player::setName(string name)
{
    this->name = name;
}
//void Player::checkAndGiveCardForConquest(Deck& deck) {
//    if (conqueredTerritoryThisTurn) {
//        Card* card = deck.draw(); // Draw a card from the deck
//        if (card != nullptr) {
//            hand->returnCard(*card); // Add the card to the player's hand
//            std::cout << "Player " << playerName << " received a card: " << *card << std::endl;
//        }
//        conqueredTerritoryThisTurn = false; // Reset the flag
//    }
//}

void Player::receiveRandomCard() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random card type, excluding 'end'
    Card::WarzoneCard randomCardType = static_cast<Card::WarzoneCard>(rand() % Card::WarzoneCard::end);

    // Create a new Card object with the random type
    Card* newCard = new Card(randomCardType);

    // Add the card to the player's hand
    this->hand->returnCard(*newCard);

    // Optional: Print out the received card
    std::cout << "Received a " << *newCard << " card." << std::endl;
}

// currently just a static territories to defend
vector<Territory*> Player::toDefend() const{

    Territory *t1, *t2, *t3;
    t1 = new Territory();
    t2 = new Territory();
    t3 = new Territory();
    t1->setTerritoryName("Belgium");
    t2->setTerritoryName("Canada");
    t3->setTerritoryName("Italy");
    cout << t1->getTerritoryName() + ", " + t2->getTerritoryName() + ", " + t3->getTerritoryName() << endl;
    return {t1, t2, t3};
}

// currently just a static territories to attack
vector<Territory*> Player::toAttack() const{
    Territory *t1, *t2, *t3;
    t1 = new Territory();
    t2 = new Territory();
    t3 = new Territory();
    t1->setTerritoryName("England");
    t2->setTerritoryName("France");
    t3->setTerritoryName("Mexico");
    cout << t1->getTerritoryName() + ", " + t2->getTerritoryName() + ", " + t3->getTerritoryName();
    return {t1,t2,t3};
}

ostream &operator<<(ostream &os, const Player &player) {
    os << "Player Name: " << player.playerName << ", Player ID: " << player.playerID << '\n';
    os << "Hand: " << *(player.hand) << '\n';

    os << "Territories: ";
    const std::vector<Territory *> vector1 = player.territories;
    for(size_t i = 0; i < player.territories.size(); i++) {
        if (i == player.territories.size() - 1)
            std:: cout << vector1[i]->getTerritoryName();
        else
            std:: cout << vector1[i]->getTerritoryName() << ", ";

    }

    os << '\n';

//    os << "Orders List: " << *(player.ordersList);

    return os;
}

Player& Player::operator=(const Player& rhs) {
    cout << "Player assignment operator called." << endl;
    hand = rhs.hand;
    ordersList = rhs.ordersList;
    territories = rhs.territories;

    return *this;
}

void Player::setArmyUnits(int units) {
    this->armyUnits = units; // Set the army units to the provided value
}