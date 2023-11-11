using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include "../GameEngine.h"
#include "CommandProcessing.h"

void testCommandProcessor(){
    Command* cmd;
    string keyboard;
    bool isValid;
    cout<<"If you want to read the command from the console press -console, if you want it from a file type in -file <filename>"<<endl;
    getline(cin,keyboard);
    if(keyboard != "-console"){
        vector<string> readFromFileComponents;
        string fileReadComponent;
        stringstream ssfr(keyboard);
        while(!ssfr.eof()){
            getline(ssfr,fileReadComponent,' ');
            readFromFileComponents.push_back(fileReadComponent);
        }
        FileCommandProcessorAdapter fcpa(readFromFileComponents[1]);
        cmd = fcpa.readCommand();
        isValid = fcpa.validate(cmd,GameEngine::State::START);
        if(isValid){
            cout<<"Command is valid.";
        }
    }else{
        CommandProcessing cp;
        cmd = cp.getCommand();
        isValid = cp.validate(cmd,GameEngine::State::START);
        if(isValid){
            cout<<"Command is valid.";
        }else{
            cout<<"Command is not valid.";
        }
    }
}
