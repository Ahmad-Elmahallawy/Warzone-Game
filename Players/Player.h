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

using namespace std;

class Player {

// private attributes
private:
    Hand* hand;
    vector<Territory*> territories; //territories owned by a Players
    string playerName;
    int playerID;
    OrdersList* ordersList= nullptr;


// public attributes
public:
    Player();

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, Order *ordersList);

    Player(Player &player);

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, int playerId,
           OrdersList *ordersList) : hand(hand), territories(territories), playerName(playerName),
                                    ordersList(ordersList) {}


    ~Player();   // deconstruct


    void setName(string name);

    string getName();

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory*> toDefend() const;

    std::vector<Territory*> toAttack() const;


    // getters and setters
    Hand *getHand() const;

    void issueOrder();

    const vector<Territory *> &getTerritories() const;

    const string &getPlayerName() const;

    void setHand(Hand *hand);

    void setTerritories(const vector<Territory *> &territories);

    void setPlayerName(const string &playerName);

    void setPlayerID(const int &playerID);


    int getPlayerId() const;

    void setPlayerId(int playerId);

    OrdersList & getOrdersList() ;

    friend ostream &operator<<(ostream &os, const Player &player);

    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;
};

void testPlayers();

#endif //COMP345_WARZONE_PROJECT_PLAYER_H
