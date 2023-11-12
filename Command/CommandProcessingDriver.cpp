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
    string commandComp;
    vector<string> commandComponents;
    stringstream sscm(keyboard);
    while(!sscm.eof()){
        getline(sscm,commandComp,' ');
        commandComponents.push_back(commandComp);
    }
    if(!commandComponents.empty() && (commandComponents[0] != "-console" && commandComponents[0] != "-file")){
        do {
            std::cout << "That is not a valid command" << std::endl;
            std::cout << "If you want to read the command from the console press -console, if you want it from a file type in -file <filename>" << std::endl;
            std::getline(std::cin, keyboard);

            std::istringstream sscm(keyboard);
            std::string commandComp;

            // Clear the vector before pushing new elements
            commandComponents.clear();

            while (std::getline(sscm, commandComp, ' ')) {
                commandComponents.push_back(commandComp);
            }
        } while (!commandComponents.empty() && (commandComponents[0] != "-console" && commandComponents[0] != "-file"));
    }

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
