// Part 2
// This is the player header file

#ifndef COMP345_WARZONE_PROJECT_PLAYER_H
#define COMP345_WARZONE_PROJECT_PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {

// private attributes
private:
    Hand* hand;
    vector<Territory*> territories; //territories owned by a player
    string playerName;
    Order* ordersList;


// public attributes
public:
    Player();

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, Order *ordersList);
    // default constructor

    ~Player();   // deconstruct

    Player& operator=(const Player &player);

    void setName(string name);

    string getName();

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory*> toDefend() const;

    std::vector<Territory*> toAttack() const;

    Hand *getHand();

    void issueOrder();

    const vector<Territory *> &getTerritories() const;

    const string &getPlayerName() const;

    void setHand(Hand *hand);

    void setTerritories(const vector<Territory *> &territories);

    void setPlayerName(const string &playerName);

    Order *getOrdersList1() const;



};


#endif //COMP345_WARZONE_PROJECT_PLAYER_H
