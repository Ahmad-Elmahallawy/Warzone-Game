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

void Player::issueOrder(MapLoader& mapLoader) {
    std::cout << "Player " << getPlayerName() << ", it's your turn to issue orders." << std::endl;

    // Loop to allow the player to issue multiple orders
    while (true) {
        std::cout << "Choose an order type (1: Deploy, 2: Advance, 3: Airlift, 4: Blockade, 5: Bomb, 6: Negotiate, 0: End turn): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Exit the loop if the player chooses to end the turn
        }

        Order* order = nullptr;

        // Based on the user's choice, create the corresponding order
        switch (choice) {
            case 1: {
                // Deploy order
                order = createDeployOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            case 2: {
                // Advance order
                order = createAdvanceOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            case 3: {
                // Airlift order
                order = createAirliftOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            case 4: {
                // Blockade order
                order = createBlockadeOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            case 5: {
                // Bomb order
                order = createBombOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            case 6: {
                // Negotiate order
                order = createNegotiateOrder(mapLoader);
                ordersList->addOrder(order);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue; // Restart the loop if the choice is invalid
        }


    }
    std::cout << "End of turn for Player " << getPlayerName() << "." << std::endl;
}

Order* Player::createDeployOrder(MapLoader& mapLoader) {
    // Implement logic to get parameters for Deploy order from the user
    int armies;
    std::string targetTerritory;
    std::cout << "Enter the number of armies to deploy: ";
    std::cin >> armies;
    std::cout << "Enter the target territory name: ";
    std::cin >> targetTerritory;

    // Find the target territory object based on its name
    Territory t = mapLoader.findTerritory(targetTerritory);
    Territory* target = &t;

    // Check if the target territory exists
    if (target) {
        return new Deploy(this, this, armies, target, target);
    } else {
        std::cout << "Error: Target territory not found." << std::endl;
        return nullptr;  // Return nullptr to indicate failure
    }
}

Order* Player::createAdvanceOrder(MapLoader& mapLoader) {
    // Implement logic to get parameters for Advance order from the user
    std::string sourceTerritory, targetTerritory;
    int armies;
    std::cout << "Enter the source territory name: ";
    std::cin >> sourceTerritory;
    std::cout << "Enter the target territory name: ";
    std::cin >> targetTerritory;

    // Find the source and target territories based on their names
    Territory s = mapLoader.findTerritory(sourceTerritory);
    Territory* source = &s;
    Territory t = mapLoader.findTerritory(targetTerritory);
    Territory* target = &t;
    // Check if the source and target territories exist
    if (source && target) {
        std::cout << "Enter the number of armies to advance: ";
        std::cin >> armies;
        return new Advance(this, this, armies, target, source);
    } else {
        std::cout << "Error: Source or target territory not found." << std::endl;
        return nullptr;  // Return nullptr to indicate failure
    }
}

Order* Player::createAirliftOrder(MapLoader& mapLoader) {
    // Check if the player has the Airlift card in their hand
    bool hasAirliftCard = hasCardInHand(Card::WarzoneCard::Airlift);
    if (hasAirliftCard) {
        // Implement logic to get parameters for Airlift order from the user
        std::string sourceTerritory, targetTerritory, pName;
        int armies;
        std::cout << "Enter the source territory name: ";
        std::cin >> sourceTerritory;
        std::cout << "Enter the target territory name: ";
        std::cin >> targetTerritory;
        std::cout << "Enter the target player name: ";
        std::cin >> pName;
        Player* p = new Player(pName);
        Territory f = mapLoader.findTerritory(targetTerritory);
        Territory* find = &f;
        if(find->getOwner()->getPlayerName() != p->playerName)
        {
            cout << "Name is worng";
            return nullptr;
        }
        // Find the source and target territories based on their names
        Territory s = mapLoader.findTerritory(sourceTerritory);
        Territory* source = &s;
        Territory t = mapLoader.findTerritory(targetTerritory);
        Territory* target = &t;

        // Check if the source and target territories exist
        if (source && target) {
            std::cout << "Enter the number of armies to airlift: ";
            std::cin >> armies;
            return new Airlift(p, this, armies, target, source);
        } else {
            std::cout << "Error: Source or target territory not found." << std::endl;
            return nullptr;  // Return nullptr to indicate failure
        }
    } else {
        std::cout << "You don't have the Airlift card to issue this order." << std::endl;
        return nullptr;  // Return nullptr to indicate failure
    }
}

Order* Player::createBlockadeOrder(MapLoader& mapLoader) {
    // Check if the player has the Blockade card in their hand
    bool hasBlockadeCard = hasCardInHand(Card::WarzoneCard::Blockade);
    if (hasBlockadeCard) {
        // Implement logic to get parameters for Blockade order from the user
        std::string targetTerritory;
        std::cout << "Enter the target territory name: ";
        std::cin >> targetTerritory;

        // Find the target territory object based on its name
        Territory t = mapLoader.findTerritory(targetTerritory);
        Territory* target = &t;
        // Check if the target territory exists
        if (target) {
            return new Blockade(this, this, 0,target, target);
        } else {
            std::cout << "Error: Target territory not found." << std::endl;
            return nullptr;  // Return nullptr to indicate failure
        }
    } else {
        std::cout << "You don't have the Blockade card to issue this order." << std::endl;
        return nullptr;  // Return nullptr to indicate failure
    }
}

Order* Player::createBombOrder(MapLoader& mapLoader) {
    // Check if the player has the Bomb card in their hand
    bool hasBombCard = hasCardInHand(Card::WarzoneCard::Bomb);
    if (hasBombCard) {
        // Implement logic to get parameters for Bomb order from the user
        std::string sourceTerritory, targetTerritory, pName;
        std::cout << "Enter the source territory name: ";
        std::cin >> sourceTerritory;
        std::cout << "Enter the target territory name: ";
        std::cin >> targetTerritory;
        std::cout << "Enter the target player name: ";
        std::cin >> pName;
        Player* p = new Player(pName);
        Territory f = mapLoader.findTerritory(targetTerritory);
        Territory* find = &f;
        if(find->getOwner()->getPlayerName() != p->playerName)
        {
            cout << "Name is worng";
            return nullptr;
        }
        // Find the source and target territories based on their names
        Territory s = mapLoader.findTerritory(sourceTerritory);
        Territory* source = &s;
        Territory t = mapLoader.findTerritory(targetTerritory);
        Territory* target = &t;

        // Check if the target territory exists
        if (target) {
            return new Bomb(p, this,0, target, source);
        } else {
            std::cout << "Error: Target territory not found." << std::endl;
            return nullptr;  // Return nullptr to indicate failure
        }
    } else {
        std::cout << "You don't have the Bomb card to issue this order." << std::endl;
        return nullptr;  // Return nullptr to indicate failure
    }
}

Order* Player::createNegotiateOrder(MapLoader& mapLoader) {
    // Check if the player has the Diplomacy card in their hand
    bool hasDiplomacyCard = hasCardInHand(Card::WarzoneCard::Diplomacy);
    if (hasDiplomacyCard) {
        std::string sourceTerritory, targetTerritory, pName;
        // Implement logic to get parameters for Negotiate order from the user
        std::cout << "Enter the source territory name: ";
        std::cin >> sourceTerritory;
        std::cout << "Enter the target territory name: ";
        std::cin >> targetTerritory;
        std::cout << "Enter the target player name: ";
        std::cin >> pName;
        Player* p = new Player(pName);
        Territory f = mapLoader.findTerritory(targetTerritory);
        Territory* find = &f;
        if(find->getOwner()->getPlayerName() != p->playerName)
        {
            cout << "Name is worng";
            return nullptr;
        }

        // Find the source and target territories based on their names
        Territory s = mapLoader.findTerritory(sourceTerritory);
        Territory* source = &s;
        Territory t = mapLoader.findTerritory(targetTerritory);
        Territory* target = &t;

        // Check if the target player exists
        if (target) {
            return new Negotiate(p, this, 0 , target,source);
        } else {
            std::cout << "Error: Target player not found." << std::endl;
            return nullptr;  // Return nullptr
        }}}


bool Player::hasCardInHand(Card::WarzoneCard cardType) const {
    // Iterate through the player's hand to check if the specified card type is present
    for (const Card* card : hand->getCard()) {
        if (card->getCard() == cardType) {
            return true; // Card found in hand
        }
    }
    return false; // Card not found in hand
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
