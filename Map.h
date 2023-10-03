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
using namespace std;
class Territory{
public:
    Territory(int xCoordinate,int yCoordinate,string territoryName,string continent);
    Territory();
    ~Territory();
    int getXCoordinate();
    void setXCoordinate(int x);
    int getYCoordinate();
    void setYCoordinate(int y);
    string getTerritoryName();
    void setTerritoryName(string tName);
    string getContinentName();
    void setContinentName(string cName);
    int getVertexNumber();
    int getViableVertexNumber();
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
};
class Map{
public:
    Map(int v);
    bool validate();
    bool checkContinent();
    bool DFS();
    void DFSUtil(Territory& v, std::vector<bool>& visited);
    void addEdge(Territory t1,Territory t2);
    vector<Territory> listOfTerritories;
    void print();

private:
    list<Territory> *adjlist;
    int numberOfVertices;
};
class MapLoader{
public:
    void loadMap();
    Map *gameMap;
    MapLoader(string fileName);
    MapLoader(int n,std::string fileName);
    ~MapLoader();
    int getNumberOfTerritoriesFromFile();
    bool territoryExists(string tName);
    Territory findTerritory(string tName);
    void setNumberOfTerritories(int n);
    void firstRun();
    void secondRun();
    int getNumberOfTerritories();
    string fileName;
private:
    int numberOfTerritories;
};
#endif //COMPP345WARZONE_MAP_H
