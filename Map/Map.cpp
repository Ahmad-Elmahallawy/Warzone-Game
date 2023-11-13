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
    this->adjacentTerritories = {};
}
Territory::~Territory(){

}
int Territory::getXCoordinate() const{
    return this->xCoordinate;
}
int Territory::getYCoordinate() const{
    return this->yCoordinate;
}
string Territory::getTerritoryName() const{
    return this->territoryName;
}
string Territory::getContinentName() const{
    return this->continent;
}

int Territory::getVertexNumber() const{
    return this->vertexNumber;
}
int Territory::getViableVertexNumber() const{
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

int Territory::getNumberOfArmies() const {
    return this->numberOfArmies;
}

void Territory::setNumberOfArmies(int numArmies) {
    // Setter method to set the number of armies
    this->numberOfArmies = numArmies;
}

void Territory::addArmies(int numArmies) {
    // Add the specified number of armies to the territory
    this->numberOfArmies += numArmies;
}
void Territory::setOwner(Player* newOwner) {
    owningPlayer = newOwner;
}

// Getter for the owner (player) of the territory
Player* Territory::getOwner() const {
    return owningPlayer;
}


void Territory::removeArmies(int numArmies) {
    if (numArmies >= this->numberOfArmies) {
        // If the number of armies to remove is greater than or equal to the current number of armies,
        // set the number of armies to zero.
        this->numberOfArmies = 0;
    } else {
        // Otherwise, subtract the specified number of armies.
        this->numberOfArmies -= numArmies;

        // Ensure the number of armies does not go below zero
        if (this->numberOfArmies < 0) {
            this->numberOfArmies = 0;
            cout << "Can not set below 0";
        }
    }
}

void Territory::setContinentName(std::string cName) {
    this->continent = cName;
}

void Territory::setVertexNumber() {
    this->vertexNumber = getViableVertexNumber();
}

std::ostream& operator<<(std::ostream& os, const Territory& territory) {
    os << "Territory Name: " << territory.getTerritoryName() << ", Continent: " << territory.getContinentName();
    // Include any other information you want to print for a Territory
    return os;
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

std::ostream& operator<<(std::ostream& os, const Map& map){
    os << "Number of vertices: " << map.numberOfVertices;
    return os;
}

// Assignment operator for Map class
Map& Map::operator=(const Map& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    this->listOfTerritories = other.listOfTerritories;
    this->numberOfVertices = other.numberOfVertices;
    // Include any other member variables you want to copy
    return *this;
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
int MapLoader::getNumberOfTerritories() const{
    return this->numberOfTerritories;
}

bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

bool MapLoader::firstRun() {
    if (!fileExists(fileName)) {
        std::cout << "File does not exist." << std::endl;
        return false;
    }
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
    return true;
}

bool MapLoader::secondRun() {
    string myline = "";
    Territory primary;
    Territory adjacent;
    bool past = false;
    std::ifstream myFile;
    myFile.open(fileName);
    string word;
    vector<string> tokens;

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
                        return false;
                    }
                    this->gameMap->addEdge(primary,adjacent);//if both exist then link them via an edge
                    primary.adjacentTerritories.push_back(adjacent);
                }
            }
        }
    }

    bool continentCheck = this->gameMap->checkContinent();
    bool connectivityCheck = this->gameMap->DFS();
    if(continentCheck){
        cout<<"Continent test has passed: every territory belongs to only one continent"<<endl;
        if(connectivityCheck){
            cout<<"Connectivity test has passed: Map is a connected graph and every continent is a connected subgraph"<<endl;
        } else{
            cout<<"Connectivity test has failed: Map is not  a connected graph and not every continent is a connected subgraph";
            return false;
        }
    } else{
        cout<<"Continent test has failed: there exists one or more territories that belong to more than one continent"<<endl;
        return false;
    }
    this->gameMap->print();

    myFile.close();
    return true;
}

int MapLoader::getNumberOfTerritoriesFromFile() const{
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

// Stream insertion operator for MapLoader class
std::ostream& operator<<(std::ostream& os, const MapLoader& loader) {
    os << "MapLoader Contents:" << std::endl;
    os << "File Name: " << loader.fileName << std::endl;
    os << "Number of Territories: " << loader.getNumberOfTerritories() << std::endl;
    return os;
}