// part 2
// this is the Players.cpp file where all the definitions are done
#include <iostream>
#include "Player.h"

// default constructor
Player::Player() {
    this->hand = new Hand();
    this->territories = vector<Territory *>();
    this->playerName = "no name";
    this->ordersList = new Order();
}

// non-default constructor
Player::Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, Order *ordersList) : hand(
        hand), territories(territories), playerName(playerName), ordersList(ordersList) {}

// copy constructor
Player::Player(Player &player) {
    hand = new Hand(*player.hand);
    territories = vector<Territory*>(player.territories);
    ordersList = new Order(*player.ordersList);
    playerName = player.playerName;

}

Player::~Player() {

}

const vector<Territory *> &Player::getTerritories() const {
    return territories;
}

const string &Player::getPlayerName() const {
    return playerName;
}


Order *Player::getOrdersList1() const {
    return ordersList;
}

Hand* Player::getHand() const
{
    return  this->hand;
    //return *hand;
}

void Player::setHand(Hand *hand) {
    Player::hand = hand;
}

void Player::setTerritories(const vector<Territory *> &territories) {
    Player::territories = territories;
}

void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

int Player::getPlayerId() const {
    return playerID;
}

void Player::setPlayerId(int playerId) {
    playerID = playerId;
}

Order *Player::getOrdersList() const {
    return ordersList;
}

void Player::setOrdersList(Order *ordersList) {
    Player::ordersList = ordersList;
}

// creates a new order
void Player::issueOrder() {
    OrderList orderList;
    Order *order = new Order();

    orderList.add_order_list(order);//no addOrder for type order its for type orderlist

    cout << "an new order is added";
}

// currently just a static territories to defend
vector<Territory*> Player::toDefend() const{
    return {new Territory(), new Territory()};
}

// currently just a static territories to attack
vector<Territory*> Player::toAttack() const{
    return {new Territory(), new Territory(), new Territory()};
}

// Assignment operator overload
Player& Player::operator=(const Player &player)
{
    cout << "Player assignment operator called." << endl;
    hand = player.hand;
    ordersList = player.ordersList;
    vector<Territory*> ownedTerritories = player.territories;//territories?
}



