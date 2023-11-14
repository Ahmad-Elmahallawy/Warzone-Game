// Part 2
// This is the Players header file

#ifndef COMP345_WARZONE_PROJECT_PLAYER_H
#define COMP345_WARZONE_PROJECT_PLAYER_H

#include <string>
#include <vector>
#include <ostream>
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Cards/Cards.h"

class OrdersList;
class MapLoader;
class Order;
using namespace std;

class Player {

// private attributes
private:
    Hand* hand;
    vector<Territory*> territories; //territories owned by a Players
    string playerName;
    int playerID{};
    OrdersList* ordersList= nullptr;
    int reinforcementPool{};
    string phase;
    vector<Territory*> attackList;
    vector<Territory*> defendList;
    // Static member representing the neutral player
    bool capturedTerritoryThisTurn = false;


// public attributes
public:
    Player();

    Player(Player &player);

    Player(string playerName);
    void setAttackList(Territory* attack);
    void setDefendList(Territory* defend);
        Player* negociatedPlayers[20];

    // Static method to get the neutral player instance

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, int playerId,
           OrdersList *ordersList);


    ~Player();   // deconstruct

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory*> toDefend() const;

    std::vector<Territory*> toAttack() const;

    // Method for issuing orders
    void issueOrder(MapLoader& mapLoader);

    // Method to create Deploy order
    Order* createDeployOrder(MapLoader& mapLoader);

    // Method to create Advance order
    Order* createAdvanceOrder(MapLoader& mapLoader);

    // Method to create Airlift order
    Order* createAirliftOrder(MapLoader& mapLoader);

    // Method to create Blockade order
    Order* createBlockadeOrder(MapLoader& mapLoader);

    // Method to create Bomb order
    Order* createBombOrder(MapLoader& mapLoader);

    // Method to create Negotiate order
    Order* createNegotiateOrder(MapLoader& mapLoader);

    // Method to check if the player has a specific card in hand
    bool hasCardInHand(Card::WarzoneCard cardType) const;

    // getters and setters
    Hand *getHand() const;
    void removeOwnedTerritory(string territoryName);

    void issueOrder();

    const vector<Territory *> &getTerritories() const;

    const string &getPlayerName() const;

    void setHand(Hand *hand);


    void setTerritories(Territory* territories);
    void setPlayerName(const string &playerName);

    void setPlayerID(const int &playerID);

    void setCapturedTerritoryThisTurn(bool update);

    int getReinforcementPool() const;

    void setReinforcementPool(int reinforcementPool);

    bool ownAllTerritoryInContinent();

    void setPhase(string ph);

    string getPhase();

    vector<Territory *> toDefend();

    vector<Territory *> toAttack();

    void printDefendList();

    void printAttackList();


    int getPlayerId() const;

    void setPlayerId(int playerId);

    OrdersList & getOrdersList() ;

    friend ostream &operator<<(ostream &os, const Player &player);

    bool operator=(const Player &rhs) const;

    Player& operator=(const Player& rhs);

    void addPlayerToNegociatedList(Player* p);

    void clearNegociatedList();

    void addTerritory(Territory* territory);

    const vector<Territory *> &getAttackList() const;

    void setAttackList(const vector<Territory *> &attackList);

    const vector<Territory *> &getDefendList() const;

    void setDefendList(const vector<Territory *> &defendList);
};

void testPlayers();

#endif //COMP345_WARZONE_PROJECT_PLAYER_H