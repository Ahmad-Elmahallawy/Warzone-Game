//
// Created by ahmad on 11/10/2023.
//

#ifndef PROJECT_1_COMMANDPROCESSING_H
#define PROJECT_1_COMMANDPROCESSING_H
using namespace std;
#include <iostream>
#include <list>
#include "../GameEngine.h"
#include "../GameLog/LoggingObserver.h"

class Command: public ILoggable, public Subject{
public:
    string effect;
    string secondParameter;
    void saveEffect(string effect);
    string getCommand();
    string getEffect();
    Command(string command);
    Command(string command, string secondParameter);
    string stringToLog();
    ~Command();

private:
    string command;
    LoggingObserver* log1;
};


class CommandProcessing: public ILoggable, public Subject{
public:
    ~CommandProcessing();
    list<Command*> lc;
    Command* readCommand();
    void saveCommand(Command* command);
    Command* getCommand();
    bool validate(Command* command, GameEngine::State state);
    string stringToLog();
    Commands getEnumCommands();

    };
class FileLineReader{
public:
    void readLineFromFile();
};
class FileCommandProcessorAdapter: public CommandProcessing{
public:
    Command* readCommand();
    string fileName;
    FileCommandProcessorAdapter(string fileName);
    FileLineReader flr;
    virtual ~FileCommandProcessorAdapter();

private:

};

void testCommandProcessor();
#endif //PROJECT_1_COMMANDPROCESSING_H
