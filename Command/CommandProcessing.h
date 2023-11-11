//
// Created by ahmad on 11/10/2023.
//

#ifndef PROJECT_1_COMMANDPROCESSING_H
#define PROJECT_1_COMMANDPROCESSING_H
using namespace std;
#include <iostream>
#include <list>
#include "../GameEngine.h"

class Command{
public:
    string effect;
    string secondParameter;
    void saveEffect(string effect);
    string getCommand();
    string getEffect();
    Command(string command);
    Command(string command, string secondParameter);

    ~Command();

private:
    string command;
};


class CommandProcessing{
public:
    ~CommandProcessing();

    list<Command*> lc;
    Command* readCommand();
    void saveCommand(Command* command);
    Command* getCommand();
    bool validate(Command* command, GameEngine::State state);
private:

};
class FileLineReader{
public:
    void readLineFromFile();

    virtual ~FileLineReader();
};
class FileCommandProcessorAdapter: CommandProcessing{
public:
    Command* readCommand();
    FileLineReader flr;
    string fileName;
    FileCommandProcessorAdapter(string fileName);

    virtual ~FileCommandProcessorAdapter();

private:

};

void testCommandProcessor();
#endif //PROJECT_1_COMMANDPROCESSING_H
