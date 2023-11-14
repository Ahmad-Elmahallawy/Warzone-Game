// part 2
// this is the Players.cpp file where all the definitions are done
#include <iostream>
#include <algorithm>
#include "Player.h"
using namespace std;
// default constructor


// Static method to get the neutral player instance
static Player* getNeutralPlayer();

Player::Player() {
    this->hand = new Hand();
    this->territories = {};
    this->playerName = "no name";
    this->ordersList = new OrdersList();
}


Player::Player(string playerName) {
    this->playerName = playerName;
    this->hand = new Hand();
    this->territories = {};
    this->ordersList = new OrdersList();

}


Player::Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, int playerId,
               OrdersList *ordersList) : hand(hand), territories(territories), playerName(playerName),
                                         playerID(playerId), ordersList(ordersList) {}

// copy constructor
Player::Player(Player &player) {
    hand = new Hand(*player.hand);
    territories = vector<Territory*>(player.territories);
    ordersList = new OrdersList(*player.ordersList);
    playerName = player.playerName;
}


Player::~Player() {
    cout << "Player deleted" << endl;
    delete this->hand;
    cout << "hand deleted" << endl;
    delete this->ordersList;
    cout << "orderslist deleted" << endl;

}

// returns player's territories
const vector<Territory *> &Player::getTerritories() const {
    return territories;
}


// returns player name
const string &Player::getPlayerName() const {
    return playerName;
}

// return's user's orderlist
OrdersList& Player::getOrdersList(){
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

// setsTerritories
void Player::setTerritories(Territory* territories) {
    Player::territories.push_back(territories);
}

// sets Player's name
void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}


// Adds specified number to the player's reinforcement pool
void Player::setReinforcementPool(int num) {
    this->reinforcementPool += num;
}


void Player::setCapturedTerritoryThisTurn(bool update)
{
    this->capturedTerritoryThisTurn = update;
}
// List of territories that are going to be defended
vector<Territory *> Player::toDefend()
{
    return defendList;
}

//Print function for Player's list of territories to be defended
void Player::printDefendList()
{
    // Declare and initialize defendList
    //vector<Territory *> defendList = toDefend();
    for (auto t : defendList)
    {
        std::cout << "Territory Name: " << t->getTerritoryName() << " | ";
        std::cout << "Continent Name: " << t->getContinentName() << " | ";
        std::cout << "Number of Armies: " << t->getNumberOfArmies() << "\n";
    }
}

// Player's list of territories that are going to be attacked
vector<Territory *> Player::toAttack()
{
    return attackList;
}

// Print function for Player's list of territories to be attacked
void Player::printAttackList()
{
    //vector<Territory *> attackList = toAttack();
    for (auto t : attackList)
    {
        std::cout << "Territory Name: " << t->getTerritoryName() << " | ";
        std::cout << "Continent Name: " << t->getContinentName() << " | ";
        std::cout << "Number of Armies: " << t->getNumberOfArmies() << "\n";
    }
}


 //creates a new order
 void Player::issueOrder() {
     Order *order{};
     int amount;
     string sourceID, destID, targetPlayer;
     Territory *source;
     Territory *destination;
     Player otherPlayer;
     string type;
     Player *target;
     cout << "please enter the type of order that you would like to issue"<<endl;
    cin >>type;
    cout << "Please enter the target player name" << endl;
    cin >> targetPlayer;
    cout << "Please enter the amount you of your army that you would like to commit for this" << endl;
    cin >> amount;
    cout << "Please enter territory of target for blockade:" << endl;
    cin >> destID;
    cout<<"please enter your own territory"<< endl;
    cin >> sourceID;
    cout << "\nAdding order to order list" << endl;
     std::transform(type.begin(), type.end(), type.begin(),
                    [](unsigned char c) { return std::tolower(c); });


     // Validate source territory
     for (int i = 0; i < territories.size(); i++) {
         if (territories[i]->getTerritoryName() == sourceID) {
             source = territories[i];
             break;
         }
     }


     if (type == "deploy") {
             order = new Deploy(this, this, amount, destination, source);
         }
         else if (type == "airlift") {
             order = new Airlift(target, this, amount, destination, source);
         }
             //Fix the target player to be neutral not by creating a new player but asign it it to the current neutral player.
         else if (type == "blockade") {
             Player* n = new Player("neutralplaceholder");
             order = new Blockade(n, this, amount, destination, source);
         }
         else if (type == "bomb") {
             order = new Bomb(target, this, amount, destination, source);
         }
         else if (type == "advance") {
             order = new Advance(target, this, amount, destination, source);
         }
         else if (type == "negociate") {
             order = new Negotiate(target, this, amount, destination, source);
         }
         ordersList->addOrder(order);  // adding order to the list
         std::cout << "Order has been added to the list" << endl;

}


//Removes a Territory from the list of owned Territory with the same territory ID
void Player::removeOwnedTerritory(string territoryName) {
    for (int i = 0; i < territories.size(); i++) {
        if (territories.at(i)->getTerritoryName() == territoryName) {
            territories.erase(territories.begin() + i);
        }
    }
}

// Add a territory to the player's list of territories
void Player::addTerritory(Territory* territory) {
    if (territory) {
        // Check if the territory is not already owned by another player
        if (territory->getOwner() && territory->getOwner() != this) {
            std::cout << "Error: Territory '" << territory->getTerritoryName()
                      << "' already belongs to another player." << std::endl;
        } else {
            // Add the territory to the player's list
            territories.push_back(territory);
            // Set this player as the owner of the territory
            territory->setOwner(this);
            std::cout << "Territory '" << territory->getTerritoryName() << "' added to player '"
                      << playerName << "'." << std::endl;
        }
    } else {
        std::cout << "Error: Cannot add a null territory." << std::endl;
    }
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
    if (this != &rhs) {
        delete hand;
        delete ordersList;
        hand = new Hand(*rhs.hand);
        territories = vector<Territory*>(rhs.territories);
        ordersList = new OrdersList(*rhs.ordersList);
        playerName = rhs.playerName;
    }
    return *this;
}

int Player::getReinforcementPool() const {
    return reinforcementPool;
}

void Player::setPhase(string ph)
{
    phase = ph;
}

bool Player::ownAllTerritoryInContinent() {//go through all the territories, keep count of how many different territories in different continents, counter-1 for each
//    for(int i = 0; i < t.getNumberOfTerritories(); i++)
//    {
//        int numOfTerritoriesInContinentMap = getMap()->Continents[i]->territories.size();
//        int playerTerritoryIsInContinentCount;
//
//        for(int j = 0; j < territories.size(); j++)
//        {
//            if(territories.at(j)->getContinentName() == getMap()->Continents[i]->getContinentName())
//            {
//                playerTerritoryIsInContinentCount++;
//            }
//        }
//
//        if(playerTerritoryIsInContinentCount == numOfTerritoriesInContinentMap)
//        {
//            return true;
//        }
//    }
//    return false;
//}
    return false;
}

//Adds a player to the list of negociated PLayers
void Player::addPlayerToNegociatedList(Player* p) {
    int count = 0;
    for (Player* i : negociatedPlayers) {
        if (i == NULL) {
            break;
        }
        count++;
    }
    negociatedPlayers[count] = p;
}


//Empty the array of negociated PLayers
void Player::clearNegociatedList() {
    int count = 0;
    for (Player* i : negociatedPlayers) {
        delete i;
        i = NULL;
    }

}

