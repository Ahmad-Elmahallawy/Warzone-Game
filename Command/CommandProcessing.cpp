using namespace std;
#include <bits/stdc++.h>
#include "CommandProcessing.h"

Command::Command(std::string command) : command(command){
    this->log1 = new LoggingObserver(this);
}

Command::Command(std::string command, std::string secondParameter) : command(command), secondParameter(secondParameter){
    this->log1 = new LoggingObserver(this);
}

Command::~Command() {

}

void Command::saveEffect(string effect) {
    this->effect = effect;
    Notify(this);
}

string Command::getCommand() {
    return this->command;
}

string Command::getEffect() {
    if(this->command== "start")
        effect = "start begins the game!";
    else if(this->command == "loadmap")
        effect = "Loading up the map!";
    else if(this-> command == "validatemap")
        effect = "The map is being validated.";
    else if(this-> command == "addplayer")
        effect = "A player is added.";
    else if(this-> command == "gamestart")
        effect = "The game session has started!";
    else if(this-> command == "replay")
        effect = "You start over!";
    else if(this->command == "quit")
        effect = "The game is over. :(";
    else
        effect = "No effect took place.";
    return this->effect;
}
string Command::stringToLog() {
    string s1 = "Command's Effect: " + this->effect;
    return s1;
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
    command->saveEffect(command->getEffect());
    Notify(this);}

Command *CommandProcessing::getCommand() {
    Command* cmd = readCommand();
    saveCommand(cmd);
    return cmd;
}
string CommandProcessing::stringToLog() {
    Command* c1 = this->lc.back();
    string commandName;


    // Check if the command type is present in the map
    if(c1->getCommand() == "loadmap")
        commandName = "loadmap";
    else if(c1->getCommand() == "start")
        commandName = "start";
    else if(c1->getCommand() == "validatemap")
        commandName = "validatemap";
    else if(c1->getCommand() == "addplayer")
        commandName = "addplayer";
    else if(c1->getCommand() == "gamestart")
        commandName = "gamestart";
    else if(c1->getCommand() == "replay")
        commandName = "replay";
    else if(c1->getCommand() == "quit")
        commandName = "quit";
    else
        commandName = " ";

    string temp;
    if(commandName == " ")
        temp += "Invalid command! ";
    else
        temp += "Command: " + commandName + " has been saved!";
    return temp;
}

Commands CommandProcessing::getEnumCommands() {
    Command* command = this->getCommand();
    return commandToEnum(command->getCommand());
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