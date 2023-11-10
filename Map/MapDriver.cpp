#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
using namespace std;
#include "Map.h"

int getNumberOfTerritoriesFromFile(string fileName);
int testLoadMaps(string filename) {//goes through map file twice and creates graph and map object
    int n = getNumberOfTerritoriesFromFile(filename);//number of territrories
    return n;
//    MapLoader loader(n,filename);
//   loader.firstRun();
//   loader.secondRun();
//    loader.~MapLoader();

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