//
// Created by oimbs on 11/6/2023.
//
using namespace std;
#include <bits/stdc++.h>
#include "CommandProcessing.h"
#include "../GameEngine.h"

Command::Command(std::string command) : command(command){}

Command::Command(std::string command, std::string secondParameter) : command(command), secondParameter(secondParameter){}

void Command::saveEffect(string effect) {
    this->effect = effect;
}

string Command::getCommand() {
    return this->command;
}

string Command::getEffect() {
    return this->effect;
}

Command* CommandProcessor::readCommand() {
    string keyboard1;
    string keyboard;
    cout<<"If you want to read the command from the console press -console, if you want it from a file type in -file <filename>";
    cin>>keyboard1;
    if(keyboard1 != "-console"){
        vector<string> readFromFileComponents;
        string fileReadComponent;
        stringstream ssfr(keyboard1);
        while(!ssfr.eof()){
            getline(ssfr,fileReadComponent,' ');
            readFromFileComponents.push_back(fileReadComponent);
        }
        FileCommandProcessorAdapter fcpa(readFromFileComponents[1]);
        Command* cmd1;
        cmd1 = fcpa.readCommand();
        return cmd1;
    }
    cout<<"Please enter a command: "<<endl;
    cout<<keyboard;
    vector<string> commandComponents;
    string component;
    stringstream ss(keyboard);
    while (!ss.eof()) {//seperates line into words given they are space seperated and add them to array
        getline(ss, component, ' ');
        commandComponents.push_back(component);
    }

    Command* cmd;

    if(commandComponents.size() == 1){
        cmd = new Command(commandComponents[0]);
    }else {
        cmd = new Command(commandComponents[0],commandComponents[1]);
    }

    return cmd;
}

void CommandProcessor::saveCommand(Command* command) {
    lc.push_back(command);
}

Command *CommandProcessor::getCommand() {
    Command* cmd = readCommand();
    saveCommand(cmd);
    return cmd;
}

bool CommandProcessor::validate(Command *command, State state) {
    std::array<string,13> validCommands = {"start","loadmap","validatemap","addplayer","assigncountries","issueorder","endissueorder","executeorders","endexecorders","win","end","play","execorder"};
    bool validCommand = false;
    for(int i = 0;i<validCommands.size();i++){
        if(command->getCommand() == validCommands[i]){
            validCommand = true;
        }
    }
    if(!validCommand){
        cout<<"Command: "+command->getCommand()+" is not in the valid list of command."<<endl;
        return false;
    }
    for(const auto &transition: GameEngine::stateTransitions[state]){
        if(commandToString(transition.command) == command->getCommand()){
            return true;
        }
    }
    cout << "Invalid state transition." << endl;
    return false;
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(std::string fileName) :fileName(fileName){}

Command* FileCommandProcessorAdapter::readCommand() {
    string fileInput;
    std::ifstream myFile;
    myFile.open(fileName);//opening file
    std::getline(myFile,fileInput);
    string component;
    vector<string> commandComponents;
    stringstream ss(fileInput);
    while (!ss.eof()) {//seperates line into words given they are space seperated and add them to array
        getline(ss, component, ' ');
        commandComponents.push_back(component);
    }
    Command* cmd;

    if(commandComponents.size() == 1){
        cmd = new Command(commandComponents[0]);
    }else {
        cmd = new Command(commandComponents[0],commandComponents[1]);
    }

    return cmd;
}




