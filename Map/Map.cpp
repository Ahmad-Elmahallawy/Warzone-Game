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
#include "../Players/Player.h"
using namespace std;
int Territory::viableVertexNumber =0;//a variable that is used to assign vertex numbers to territories
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

void Territory::setVertexNumber() {
    this->vertexNumber = getViableVertexNumber();
}
Map::Map(Map const &m) {
    this->listOfTerritories = m.listOfTerritories;
    this->numberOfVertices = m.numberOfVertices;

}
Map::Map(int v) {
    this->adjlist = new list<Territory> [v];//instantiating the adjacency list representing the graph
    this->numberOfVertices = v;
}

Map::~Map() {
    delete[] this->adjlist;
}

void Map::addEdge(Territory t1, Territory t2) {
    adjlist[t1.getVertexNumber()].push_back(t2);//method to link two territores(nodes) with an edge
}

void Map::print() {
    for(int i = 0;i<this->numberOfVertices;i++){
        cout<<i<<"-->";
        for(auto x:this->adjlist[i]){//for each loop to go through every vertex and print their adjacent nodes
            cout<<x.getTerritoryName()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Map::checkContinent() {
    for (int i = 0; i < this->listOfTerritories.size(); ++i) {
        int count = std::count(this->listOfTerritories.begin(),this->listOfTerritories.end(), this->listOfTerritories[i]);
        if(count>1){//checks if a given Territory appears more than once in the map
            return false;
        }
    }
    return true;
}

void Map::DFSUtil(Territory& v, std::vector<bool> &visited) {
    if(v.getVertexNumber() >= visited.size()){//if there is a vertex with a vertex number greater than the array size do not access it and return
        return;
    }
    visited[v.getVertexNumber()] = true;//node has been visited
    for(auto neighbor: adjlist[v.getVertexNumber()]){
        if(!visited[neighbor.getVertexNumber()]){//if any of the adjacent nodes of this territory are not visited then visit them
            DFSUtil(neighbor, visited);
        }
    }
}
bool Map::DFS() {
    std::vector<bool>visited(this->numberOfVertices, false);
    DFSUtil(adjlist->front(), visited);//start DFS from the beginning

    for(bool v: visited){//if any of the nodes have not been visited return false else return true
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
        this->gameMap = new Map(n);//instantiate Map object which contains the graph
    }catch(bad_alloc&){
        cout<<"bad";
    }
}
MapLoader::~MapLoader(){
    delete this->gameMap;
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
    myFile.open(fileName);//opening file
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
                while (!ss.eof()) {//seperates line into words given they are comma seperated and add them to array
                    getline(ss, word, ',');
                    tokens.push_back(word);
                }
                Territory t(stoi(tokens[1]), stoi(tokens[2]),tokens[0],tokens[3]);
                this->gameMap->listOfTerritories.push_back(t);//create territory based on information in array and push it into another array
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
//    for(int j = 0;j<this->gameMap->listOfTerritories.size();j++){
//        cout<<this->gameMap->listOfTerritories[j].getTerritoryName()<<endl;
//    }
    if(myFile.is_open()){
        while (!myFile.eof()){
            if (myline == "[Territories]") {
                past = true;
            }
            std::getline(myFile, myline);
            if (past && myline != "") {
//                std::cout<<myline<<'\n';
                word = "";
                tokens.clear();
                stringstream ss(myline);
                while (!ss.eof()) {
                    getline(ss, word, ',');
                    tokens.push_back(word);
//                    cout<<word<<endl;
                }
                primary = this->findTerritory(tokens[0]);//searches for territory to check if it exists
                for (int i = 4; i < tokens.size(); ++i) {
                    adjacent = this->findTerritory(tokens[i]);//searches for adjacent territory to check if it exists
                    if(adjacent.getTerritoryName() == "Not found"){
                        cout<<"Graph is not connected, invalid map file";
                        exit(0);
                    }
                    this->gameMap->addEdge(primary,adjacent);//if both exist then link them via an edge
                }
            }
        }
    }
//    for(int j = 0;j<this->gameMap->listOfTerritories.size();j++){
//        cout<<this->gameMap->listOfTerritories[j].getTerritoryName()<<endl;
//    }
    bool continentCheck = this->gameMap->checkContinent();
    bool connectivityCheck = this->gameMap->DFS();
    if(continentCheck){
        cout<<"Continent test has passed: every territory belongs to only one continent"<<endl;
        if(connectivityCheck){
            cout<<"Connectivity test has passed: Map is a connected graph and every continent is a connected subgraph"<<endl;
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
            if(past && myline != ""){//goes through every line in file if it contains a territory it increments variable representing number of vertices
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
    t.setVertexNumber();
    return t;
}