//
// Created by oimbs on 11/6/2023.
//
using namespace std;
#include <bits/stdc++.h>
#include "CommandProcessing.h"

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
    string keyboard;
    cout<<"Please enter a command: "<<endl;
    cin>>keyboard;
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




