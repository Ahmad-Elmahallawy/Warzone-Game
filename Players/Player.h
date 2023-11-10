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

    Player(Hand *hand, const vector<Territory *> &territories, const string &playerName, int playerId,
           orderlist *ordersList);

    ~Player();   // deconstruct

    // toDefend() and toAttack() methods return a list of territories
    std::vector<Territory *> toDefend() const;

    std::vector<Territory *> toAttack() const;

    // getters and setters
    Hand *getHand() const;

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
    int getReinforcementPool(); //Return player's reinforcement pool
    void setReinforcementPool(int n);
    vector< Player*> getnegotiateList();// getter for negotiate list
    string getName();
    void setName(string name);
    void setTerriorty(vector <Territory*>);// setter for terriorties owned
    //void setPlayerStrategy(PlayerStrategy* newPS);
    PlayerStrategy* getPlayerStrategy() const;
    bool conquer = false;
    vector<Territory*> terriortiesOwned;
};

class PlayerStrategy  {

protected:
    Player* p;
    string type;
    PlayerStrategy();
    PlayerStrategy(string type);
    PlayerStrategy(const PlayerStrategy& p);
    PlayerStrategy& operator=(PlayerStrategy& ps);

public:
    // Set a player to the strategy
    void setPlayer(Player* inputPlayer);
    // Destructor
    virtual ~PlayerStrategy();
    // Issue order
    virtual bool issueOrder(vector<Player*> AddedPlayerList) = 0;
    virtual vector<Territory*> toAttack() = 0;
    virtual vector<Territory*> toDefend() = 0;
    string getType();
    friend ostream& operator<<(ostream& os, PlayerStrategy& player);
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
    NeutralPlayerStrategy& operator&=(NeutralPlayerStrategy& p);
    NeutralPlayerStrategy();
    NeutralPlayerStrategy(const NeutralPlayerStrategy& p);
    ~NeutralPlayerStrategy();
    bool issueOrder(vector<Player*> AddedPlayerList);
    vector<Territory*> toAttack();
    vector<Territory*> toDefend();
    friend ostream& operator<<(ostream& os, NeutralPlayerStrategy& player);
};
void testPlayers();

#endif //COMP345_WARZONE_PROJECT_PLAYER_H//