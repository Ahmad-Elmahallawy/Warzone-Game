using namespace std;
#include <bits/stdc++.h>
#include "CommandProcessing.h"

Command::Command(std::string command) : command(command){}

Command::Command(std::string command, std::string secondParameter) : command(command), secondParameter(secondParameter){}

Command::~Command() {

}

void Command::saveEffect(string effect) {
    this->effect = effect;
}

string Command::getCommand() {
    return this->command;
}

string Command::getEffect() {
    return this->effect;
}

FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {

}
Command *CommandProcessing::readCommand() {
    string keyboard;
    cout<<"Please enter a command: "<<endl;
    getline(cin,keyboard);
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

void CommandProcessing::saveCommand(Command* command) {
    lc.push_back(command);
}

Command *CommandProcessing::getCommand() {
    Command* cmd = readCommand();
    saveCommand(cmd);
    return cmd;
}

bool CommandProcessing::validate(Command* command, GameEngine::State state) {
    auto isValidCommand = [&](const std::initializer_list<string>& validCommands) {
        return std::find(validCommands.begin(), validCommands.end(), command->getCommand()) != validCommands.end();
    };

    switch (state) {
        case GameEngine::State::START:
            if (isValidCommand({"loadmap"})) {
                return true;
            }
            break;
        case GameEngine::State::MAP_LOADED:
            if (isValidCommand({"loadmap", "validatemap"})) {

                return true;
            }
            break;
        case GameEngine::State::MAP_VALIDATED:
            if (isValidCommand({"addplayer"})) {
                return true;
            }
            break;
        case GameEngine::State::PLAYERS_ADDED:
            if (isValidCommand({"addplayer", "gamestart"})) {
                return true;
            }
            break;
        case GameEngine::State::WIN:
            if (isValidCommand({"replay", "quit"})) {
                return true;
            }
            break;
        default:
            break;
    }

    cout << "Invalid command: " << command->getCommand() << " in the current state." << endl;
    return false;
}




CommandProcessing::~CommandProcessing() {
    for (auto commandPtr : lc) {
        delete commandPtr;
    }
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