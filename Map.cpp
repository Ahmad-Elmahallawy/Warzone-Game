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
#include <vector>
using namespace std;
int Territory::viableVertexNumber =0;
Territory::Territory(int xCoordinate, int yCoordinate, std::string territoryName, std::string continent) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    this->territoryName = territoryName;
    this->continent = continent;
    this->vertexNumber = getViableVertexNumber();
}
Territory::Territory() {
    this->xCoordinate = 0;
    this->yCoordinate = 0;
    this->territoryName = "";
    this->continent = "";
}
Territory::~Territory(){

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
void Territory::setXCoordinate(int x) {
    this->xCoordinate = x;
}
void Territory::setYCoordinate(int y) {
    this->yCoordinate = y;
}

void Territory::setTerritoryName(std::string tName) {
    this->territoryName = tName;
}

void Territory::setContinentName(std::string cName) {
    this->continent = cName;
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

bool Map::checkContinent() {
    for (int i = 0; i < this->listOfTerritories.size(); ++i) {
        int count = std::count(this->listOfTerritories.begin(),this->listOfTerritories.end(), this->listOfTerritories[i]);
        if(count>1){
            return false;
        }
    }
    return true;
}

void Map::DFSUtil(Territory& v, std::vector<bool> &visited) {
    visited[v.getVertexNumber()] = true;

    for(Territory& neighbor: adjlist[v.getVertexNumber()]){
        if(!visited[neighbor.getVertexNumber()]){
            DFSUtil(neighbor, visited);
        }
    }
}
bool Map::DFS() {
    std::vector<bool>visited(this->numberOfVertices, false);
    DFSUtil(adjlist->front(), visited);

    for(bool v: visited){
        if(!v){
            return false;
        }
    }
    return true;
}
MapLoader::MapLoader(std::string fileName) {
    this->fileName = fileName;
}
MapLoader::MapLoader(int n,string fileName) {
    this->fileName = fileName;
    this->numberOfTerritories = n;
    try{
        this->gameMap = new Map(n);
    }catch(bad_alloc&){
        cout<<"bad";
    }
}
MapLoader::~MapLoader(){
    delete(this->gameMap);
}
void MapLoader::setNumberOfTerritories(int n) {
    this->numberOfTerritories = n;
}
int MapLoader::getNumberOfTerritories() {
    return this->numberOfTerritories;
}
void MapLoader::firstRun() {
    string myline = "";
    bool past = false;
    std::ifstream myFile;
    myFile.open(fileName);
    string word;
    vector<string> tokens;
    if (myFile.is_open()) {
        while (myFile) {
            if (myline == "[Territories]") {
                past = true;
            }
            std::getline(myFile, myline);
            if (past && myline != "") {
//            std::cout<<myline<<'\n';
                word = "";
                tokens.clear();
                stringstream ss(myline);
                while (!ss.eof()) {
                    getline(ss, word, ',');
                    tokens.push_back(word);
//                    cout<<word<<endl;
                }
                Territory t(stoi(tokens[1]), stoi(tokens[2]),tokens[0],tokens[3]);
                this->gameMap->listOfTerritories.push_back(t);
            }
        }
    }
    myFile.close();
}

void MapLoader::secondRun() {
    string myline = "";
    Territory primary;
    Territory adjacent;
    bool past = false;
    std::ifstream myFile;
    myFile.open(fileName);
    string word;
    vector<string> tokens;
    if(myFile.is_open()){
        while (myFile){
            if (myline == "[Territories]") {
                past = true;
            }
            std::getline(myFile, myline);
            if (past && myline != "") {
//            std::cout<<myline<<'\n';
                word = "";
                tokens.clear();
                stringstream ss(myline);
                while (!ss.eof()) {
                    getline(ss, word, ',');
                    tokens.push_back(word);
//                cout<<word<<endl;
                }
                primary = this->findTerritory(tokens[0]);
                for (int i = 4; i < tokens.size(); ++i) {
                    adjacent = this->findTerritory(tokens[i]);
                    this->gameMap->addEdge(primary,adjacent);
                }
            }
        }
    }
    bool continentCheck = this->gameMap->checkContinent();
    bool connectivityCheck = this->gameMap->DFS();
    if(continentCheck){
        cout<<"Continent test has passed: every territory belongs to only one continent"<<endl;
        if(connectivityCheck){
            cout<<"Connectivity test has passed: Map is a connected graph and every continent is a connected subgraph";
        } else{
            cout<<"Connectivity test has failed: Map is not  a connected graph and not every continent is a connected subgraph";
            exit(0);
        }
    } else{
        cout<<"Continent test has failed: there exists one or more territories that belong to more than one continent"<<endl;
        exit(0);
    }
    this->gameMap->print();

//    cout<<this->gameMap->listOfTerritories.size();
//    for(int j = 0;j<this->gameMap->listOfTerritories.size();j++){
//        cout<<this->gameMap->listOfTerritories[j].getTerritoryName()<<endl;
//    }
    myFile.close();
}

int MapLoader::getNumberOfTerritoriesFromFile() {
    string myline;
    int n = 0;
    std::ifstream myFile;
    myFile.open(this->fileName);
    bool past = false;
    if(myFile.is_open()){
        while (myFile){
            if(myline == "[Territories]"){
                past = true;
            }
            std::getline(myFile,myline);
            if(past && myline != ""){
                n++;
            }
        }
    }
    return n;
}

bool MapLoader::territoryExists(string tName) {//finds out if given territory exists
    bool found = false;
    for(int k = 0;k<this->gameMap->listOfTerritories.size();k++){
        string otherTName = this->gameMap->listOfTerritories[k].getTerritoryName();
        if(tName == otherTName){
            found = true;
        }
    }
    return found;
}

Territory MapLoader::findTerritory(std::string tName) {
    Territory t;
    for(int i = 0;i<this->gameMap->listOfTerritories.size();i++){
        if(tName == this->gameMap->listOfTerritories[i].getTerritoryName()){
            return this->gameMap->listOfTerritories[i];
        }
    }
    t.setTerritoryName("Not found");
    return t;
}