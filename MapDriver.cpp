#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
using namespace std;
#include "Map.h"

int getNumberOfTerritoriesFromFile(string fileName);
void testLoadMaps() {
    int n = getNumberOfTerritoriesFromFile(R"(C:\Users\oimbs\CLionProjects\WarzonePart1\Alberta.map)");
    MapLoader loader(n,R"(C:\Users\oimbs\CLionProjects\WarzonePart1\Alberta.map)");
    loader.firstRun();
    loader.secondRun();
    loader.~MapLoader();
}
int getNumberOfTerritoriesFromFile(string fileName){
    string myline;
    int n = 0;
    std::ifstream myFile;
    myFile.open(fileName);
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
    myFile.close();
    return n;
}
