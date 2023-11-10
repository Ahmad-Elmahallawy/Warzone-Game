// part 2
// this is the Players.cpp file where all the definitions are done
#include <iostream>
#include "Player.h"
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
int Player:: getPlayerID() {// getter for playerID
    return id;
}
int Player::getReinforcementPool() {
    return reinforcementPool;
}
void Player::setReinforcementPool(int n) {
    this->reinforcementPool = n;
}
void Player::setTerriorty(vector <Territory*> terriorties) {// setter for terriorties owned
    this->terriortiesOwned= terriorties;
}
void Player::addTerriorty(Territory* t) {//adds a terriorty to the player terriortiesowned
    terriortiesOwned.push_back(t);
    t->setOwner(this);
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

    os << "Orders List: " << *(player.ordersList);

    return os;
}

Player& Player::operator=(const Player& rhs) {
    cout << "Player assignment operator called." << endl;
    hand = rhs.hand;
    ordersList = rhs.ordersList;
    territories = rhs.territories;

    return *this;
}
PlayerStrategy::PlayerStrategy() {
}

PlayerStrategy::PlayerStrategy(string type): type(type) {
}

PlayerStrategy::PlayerStrategy(const PlayerStrategy& ps): p(nullptr), type(ps.type) {
    p = new Player(*ps.p);
}

PlayerStrategy& PlayerStrategy::operator=(PlayerStrategy& ps)

{
    this->p = ps.p;
    this->type = ps.type;
    return *this;
}

PlayerStrategy::~PlayerStrategy() {
}

string PlayerStrategy::getType() {
    return type;
}

void PlayerStrategy::setPlayer(Player* inputPlayer) {
    p = inputPlayer;
}
NeutralPlayerStrategy& NeutralPlayerStrategy::operator&=(NeutralPlayerStrategy& p)
{
    PlayerStrategy :: operator=(p);
    return*this;
}
//Neutral Player class
NeutralPlayerStrategy::NeutralPlayerStrategy() : PlayerStrategy("Neutral") {}

NeutralPlayerStrategy::NeutralPlayerStrategy(const NeutralPlayerStrategy& nPlayer) : PlayerStrategy(nPlayer) {}

NeutralPlayerStrategy::~NeutralPlayerStrategy() {}

bool NeutralPlayerStrategy::issueOrder(vector<Player*> AddedPlayerList) {
    // Never issue an order
    cout << "---------------Neutral Player is issuing orders---------------"<< endl;
    cout << "[Neutral] Finish issuing issue an order" << endl;
    return false;
}
vector<Territory*> NeutralPlayerStrategy::toAttack() {
    // Neutral player never attacks
    return vector<Territory*>();
}
vector<Territory*> NeutralPlayerStrategy::toDefend() {
    // Neutral player never defends
    return vector<Territory*>();
}

/*void Player::issueBombOrder(Territory* target, int numbOfArmies) {
    if (target->getTerritoryOwner() == this) {
        // Handle the case where the target territory belongs to the same player.
        std::cout << "Bomb order is invalid: Target territory belongs to the same player." << std::endl;
    } else if (isUnderDiplomacyWith(*target->getTerritoryOwner())) {
        // Handle the case where there's a diplomatic agreement with the target player.
        std::cout << "Bomb order is invalid: Diplomatic agreement with the target player." << std::endl;
    } else {
        // Create a Bomb order if no diplomatic agreement and the target territory doesn't belong to the same player.
        bomb* bombOrder = new bomb(this, target, numbOfArmies);

        if (bombOrder->validate()) {
            // Add the bomb order to the player's orders list.
            this->ordersList->addOrder(bombOrder);
        } else {
            // Handle the case where the order is invalid.
            delete bombOrder;
        }
    }
}
 void Player::issueDeployOrder(Territory* target, int numbOfarmies) {
    order* deployOrder = new deploy(this, *target, numbOfarmies);
    if (deployOrder->validate()) {
        // Add the deploy order to the player's orders list (you should have a list for orders)
        ordersList->addOrder(deployOrder);
    } else {
        // Handle the case where the order is invalid
        delete deployOrder;
    }
}

 */