// Part 2
// This is the Players header file

#ifndef COMP345_WARZONE_PROJECT_PLAYER_H
#define COMP345_WARZONE_PROJECT_PLAYER_H

#include <string>
#include <vector>
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
    Order* ordersList;


// public attributes
public:
    Player();

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, Order *ordersList);

    Player(Player &player);


    ~Player();   // deconstruct

    Player& operator=(const Player &player);

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

    Order *getOrdersList1() const;

    void testPlayer();


};


#endif //COMP345_WARZONE_PROJECT_PLAYER_H
