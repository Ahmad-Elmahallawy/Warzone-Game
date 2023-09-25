//
// Created by ahmad on 9/24/2023.
//
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

// public attributes
public:
    Player(); // default constructor

    ~Player();   // deconstruct

    Player& operator=(const Player &player);

    void setName(string name);

    string getName();

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory*> toDefend() const;

    std::vector<Territory*> toAttack() const;

    Hand *getHand();

    void issueOrder();


};


#endif //COMP345_WARZONE_PROJECT_PLAYER_H
