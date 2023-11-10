//
// Created by oimbs on 9/14/2023.
//

#ifndef COMPP345WARZONE_MAP_H
#define COMPP345WARZONE_MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>

#include <fstream>
#include <vector>
class Player;
//#include "Players/Player.h"
using namespace std;
class Territory{
public:
    Territory(int xCoordinate,int yCoordinate,string territoryName,string continent);
    Territory();
    ~Territory();
    int getXCoordinate() const;
    void setXCoordinate(int x);
    int getYCoordinate() const;
    void setYCoordinate(int y);
    string getTerritoryName() const;
    void setTerritoryName(string tName);
    string getContinentName() const;
    void setContinentName(string cName);
    int getVertexNumber() const;
    void setVertexNumber();
    Player * getTerritoryOwner();
    void setTerritoryOwner(Player *player);
    int getViableVertexNumber() const;
    // Add a new territory to the territory's neighbors
    void addNeighbor(Territory* n);
    // Get a neighbor of the territory (by name)
    Territory* getNeighbor(string name);
    // Set an owner for the territory
    void setOwner(Player* newOwner);
    string getName() const;
    // Set a name for the territory
    void setName(string newName);
    int getNumOfArmies() const;
    // Return the owner of the territory
    Player* getOwner() const;
    // Set the number of armies for the territory
    void setNumOfArmies(int newArmies);
    // Check if this territory is adjacent to another territory
    bool isAdjacent(const Territory& other) const;
    // Method to add an adjacent territory
    void addAdjacentTerritory(Territory* adjacent);
    friend std::ostream& operator<<(std::ostream& os, const Territory& territory);
    bool operator==(const Territory& other) const {
        return this->territoryName == other.territoryName;
        // Set a list of neighbors for the territory
        //void setNeighbors(unordered_map<string, Territory*> newNeighbors);             //fix
        // Return the neighbors of the territory
        // unordered_map<string, Territory*> getNeighbors() const;
        // Return the number of armies that is on the territory
        //int getArmySize();
        //void setArmySize(int size);
    }
private:
    int xCoordinate;//horizontal coordinate of territory on the map
    int yCoordinate;//vertical coordinate of territory on the map
    string territoryName;
    string continent;//could be enum to ensure that only one continent chosen
    static int viableVertexNumber;
    int vertexNumber;
    int numberOfArmies;
    Player *owningPlayer;
    string name_;
    vector<Territory*> adjacentTerritories;
   // unordered_map<string, Territory*> neighbors_;
};
class Map{
public:
    Map(int v);
    ~Map();
    Map(Map const &m);
    bool validate();
    bool checkContinent();
    bool DFS();
    void DFSUtil(Territory& v, std::vector<bool>& visited);
    void addEdge(Territory t1,Territory t2);
    vector<Territory> listOfTerritories;
    void print();
    friend std::ostream& operator<<(std::ostream& os, const Map& map);
    Map& operator=(const Map& other);
    //bool isTerritoryAdjacent(const Territory& target) const;
    bool isAdjacent(const Territory& t1, const Territory& t2) const;
private:
    list<Territory> *adjlist;
    int numberOfVertices;
};
class MapLoader{
public:
   static Map *gameMap;
    MapLoader(string fileName);
    MapLoader(int n,std::string fileName);
    ~MapLoader();
    int getNumberOfTerritoriesFromFile() const;
    bool territoryExists(string tName);//finds out if given territory exists
    Territory findTerritory(string tName);
    void setNumberOfTerritories(int n);
    void firstRun();
    void secondRun();
    int getNumberOfTerritories() const;
    string fileName;

private:
    int numberOfTerritories;
};

void testLoadMaps();

#endif //COMPP345WARZONE_MAP_H