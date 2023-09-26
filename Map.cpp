//
// Created by oimbs on 9/14/2023.
//
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
#include <bits/stdc++.h>
using namespace std;

Territory::Territory(int xCoordinate, int yCoordinate, std::string territoryName, std::string continent) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    this->territoryName = territoryName;
    this->continent = continent;
    this->vertexNumber = getViableVertexNumber();
}
int Territory::getXCoordinate() {
    return this->xCoordinate;
}
int Territory::getYCoordinate(){
    return this->yCoordinate;
}
string Territory::getTerritoryName() {
    return this->territoryName;
}
string Territory::getContinentName() {
    return this->continent;
}

int Territory::getVertexNumber() {
    return this->vertexNumber;
}

int Territory::getViableVertexNumber() {
    return Territory::viableVertexNumber++;
}
Map::Map(int v) {
    this->adjlist = new list<Territory> [v];
    this->numberOfVertices = v;
}

void Map::addEdge(Territory t1, Territory t2) {
    adjlist[t1.getVertexNumber()].push_back(t2);
}

void Map::print() {
    for(int i = 0;i<this->numberOfVertices;i++){
        cout<<i<<"-->";
        for(auto x:this->adjlist[i]){
            cout<<x.getTerritoryName()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}




