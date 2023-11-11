
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

FileLineReader::~FileLineReader() {

}

Command* CommandProcessing::readCommand() {
    string keyboard1;
    string keyboard;
    cout<<"If you want to read the command from the console press -console, if you want it from a file type in -file <filename>: " << endl;
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
    cout << "Please enter a command: "<<endl;
    cin >> keyboard;
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

    // Print next valid commands based on the current state
    std::cout << "Next valid commands:" << std::endl;

    switch (state) {
        case GameEngine::State::START:
            if (isValidCommand({"loadmap", "quit"})) {
                std::cout << "loadmap" << std::endl;
                std::cout << "quit" << std::endl;
                return true;
            }
            break;
        case GameEngine::State::MAP_LOADED:
            if (isValidCommand({"loadmap", "validatemap"})) {
                std::cout << "loadmap" << std::endl;
                std::cout << "validatemap" << std::endl;
                return true;
            }
            break;
        case GameEngine::State::MAP_VALIDATED:
            if (isValidCommand({"addplayer"})) {
                std::cout << "addplayer" << std::endl;
                return true;
            }
            break;
        case GameEngine::State::PLAYERS_ADDED:
            if (isValidCommand({"addplayer"})) {
                std::cout << "addplayer" << std::endl;
                return true;
            }
            break;
        case GameEngine::State::WIN:
            if (isValidCommand({"replay", "quit"})) {
                std::cout << "replay" << std::endl;
                std::cout << "quit" << std::endl;
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


