#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>
using namespace std;
#include "Map.h"
int Territory::viableVertexNumber =0;
int main() {

    Territory t1(1,2,"Dukhan","Asia");
    Territory t2(3,4,"zikreet","Asia");
//    t1.addAdjacentTerritory(t2);
//    cout << t1.getAdjacentTerritory();

    Map m1(5);
    m1.addEdge(t1,t2);
    m1.addEdge(t2,t1);
    m1.print();

}
//map loader class code
//std::ifstream myfile;
//myfile.open(R"(C:\Users\oimbs\OneDrive\Documents\Alberta.map)");
//int noOfLines = 0;
//std::string myline;
//bool past = false;
//if(myfile.is_open()){
//while(myfile){
//if(myline == "[Territories]"){
//past = true;
//}
//std::getline(myfile,myline);
//std::cout<<myline<<'\n';
//if(past && myline != ""){
//noOfLines++;
//}
//}
//}
//cout<<noOfLines;
//return 0;