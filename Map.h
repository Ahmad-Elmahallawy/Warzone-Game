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
using namespace std;
class Territory{
public:
    Territory(int xCoordinate,int yCoordinate,string territoryName,string continent);
    int getXCoordinate();
    int getYCoordinate();
    string getTerritoryName();
    string getContinentName();
    int getVertexNumber();
    int getViableVertexNumber();

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
    void addEdge(Territory t1,Territory t2);
    void print();

private:
    list<Territory> *adjlist;
    int numberOfVertices;
};
#endif //COMPP345WARZONE_MAP_H
