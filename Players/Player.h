// Part 2
// This is the Players header file

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <ostream>
#include "../Map/Map.h"
#include "../Orders/Orders.h"
#include "../Cards/Cards.h"
//#include "Orders.h"
#include "Player.h"


using namespace std;

class Player {

// private attributes
private:
    Hand *hand;
    vector<Territory *> territories; //territories owned by a Players
    string playerName;
    int playerID;
    orderlist *ordersList;
   // std::Map<std::string,bool>;diplomaticAgreements; fix
    std::vector<Territory *> conqueredTerritories;
    bool conqueredTerritoryThisTurn;
    int id;
    int reinforcementPool;
    vector<Player* >negotiateList;
    static int playerId;// static player ID
    string name;


// public attributes
public:
    Player();

    Player(Player &player);

    Player(Hand *hand, const vector<Territory *> &territories, const std::string &playerName, int playerId,
           orderlist *ordersList);

    ~Player();   // deconstruct

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory *> toDefend() const;

    std::vector<Territory *> toAttack() const;
    std::vector<Territory*> territoriesOwned;
    // getters and setters
    Hand *getHand() const;
    vector<Card *> getCard();
    void issueOrder();
    vector <Territory*> getterriortiesOwned();// getter for terriorties owned
    const vector<Territory *> &getTerritories();

    const string &getPlayerName() const;

    void setHand(Hand *hand);

    void setTerritories(const vector<Territory *> &territories);

    void setPlayerName(const string &playerName);

    void setPlayerID(const int &playerID);

    bool isAlly(const Player &otherPlayer) const;

    int getPlayerId() const;

    void setPlayerId(int playerId);

    orderlist &getOrdersList();

    friend ostream &operator<<(ostream &os, const Player &player);

    bool operator=(const Player &rhs) const;

    Player &operator=(const Player &rhs);

    void issueBombOrder(Territory *target, int numbOfArmies);

    //bool isTerritoryAdjacent(const Territory &target) const;

    void issueDeployOrder(Territory *target, int numbOfarmies);

    bool isUnderDiplomacyWith(const Player &otherPlayer) const;

    void issueAdvanceOrder(Territory *source, Territory *target, int numArmies);

    bool checkConqueredTerritories();

    void addConqueredTerritory(Territory *territory) {
        conqueredTerritories.push_back(territory);
    }

    bool hasConqueredTerritoryThisTurn() const {
        return conqueredTerritoryThisTurn;
    }

    void setConqueredTerritoryThisTurn(bool conquered) {
        conqueredTerritoryThisTurn = conquered;
    }
    int getPlayerID();// getter for playerID
    void swap(int x);
    void addTerriorty(Territory*);// method that adds a territory to the terriorties owned list
    void removeTerritory(int index);
    void addnegotiationlist(Player *p);
    void clearnegotiationlist();
    vector< Player*> getnegotiateList();// getter for negotiate list
    string getName();
    void setName(string name);
    void setTerriorty(vector <Territory*>);// setter for terriorties owned
    bool conquer = false;
    vector<Territory*> terriortiesOwned;
    // Function to get a string representation of territories
    string getTerritoriesString() const {
        string result = "Territories owned by player: ";
        for (const auto& territory : territories) {
            result += territory->getName() + " ";
        }
        return result;
    }

    //int getReinforcementPool(); //Return player's reinforcement pool
    // void setReinforcementPool(int n);
    //void setPlayerStrategy(PlayerStrategy* newPS);
    //PlayerStrategy* getPlayerStrategy() const;
};


void testPlayers();

#endif //COMP345_WARZONE_PROJECT_PLAYER_H//