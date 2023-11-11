#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
using namespace std;
#include "Map.h"

int getNumberOfTerritoriesFromFile(string fileName);
int testLoadMaps(string filename) {//goes through map file twice and creates graph and map object
    try {
        int n = getNumberOfTerritoriesFromFile(filename);
        // Rest of your code here
        return n;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cerr.flush();
        // Handle the exception or exit the program if needed
        exit(0);
    }
//    MapLoader loader(n,filename);
//   loader.firstRun();
//   loader.secondRun();
//    loader.~MapLoader();

}
int getNumberOfTerritoriesFromFile(string fileName) {
    string myline;
    int n = 0;
    std::ifstream myFile;

    try {
        myFile.open(fileName);

        if (!myFile.is_open()) {
            throw std::runtime_error("Failed to open file: " + fileName);
        }

        bool past = false;
        while (myFile) {
            if (myline == "[Territories]") {
                past = true;
            }
            std::getline(myFile, myline);
            if (past && myline != "") {
                n++;
            }
        }
        myFile.close();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cerr.flush();
    }

    return n;
}
