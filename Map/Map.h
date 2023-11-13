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
    vector<Territory> adjacentTerritories;
    void setContinentName(string cName);
    int getNumberOfArmies() const;
    void setNumberOfArmies(int numArmies);
    void addArmies(int numArmies);
    void removeArmies(int numArmies);
    Player* getOwner() const;
    void setOwner(Player* newOwner);
    int getVertexNumber() const;
    void setVertexNumber();
    int getViableVertexNumber() const;
    friend std::ostream& operator<<(std::ostream& os, const Territory& territory);
    bool operator==(const Territory& other) const {
        return this->territoryName == other.territoryName;
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

private:
    list<Territory> *adjlist;
    int numberOfVertices;
};
class MapLoader{
public:
    Map *gameMap;
    MapLoader();
    MapLoader(string fileName);
    MapLoader(int n,std::string fileName);
    ~MapLoader();
    int getNumberOfTerritoriesFromFile() const;
    bool territoryExists(string tName);//finds out if given territory exists
    Territory findTerritory(string tName);
    void setNumberOfTerritories(int n);
    bool firstRun();
    bool secondRun();
    int getNumberOfTerritories() const;
    string fileName;
private:
    int numberOfTerritories;
};

int testLoadMaps(string filename);

#endif //COMPP345WARZONE_MAP_H