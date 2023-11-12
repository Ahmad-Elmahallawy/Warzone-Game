#ifndef PROJECT_1_COMMANDPROCESSOR_H
#define PROJECT_1_COMMANDPROCESSOR_H

using namespace std;
#include <iostream>
#include <list>
#include "../GameEngine.h"
#include "../GameLog/LoggingObserver.h"

class Command : public ILoggable, public Subject{
public:
    string effect;
    string secondParameter;
    void saveEffect(string effect);
    string getCommand();
    string getEffect();
    Command();
    Command(string command);
    Command(string command, string secondParameter);
    string stringToLog();

private:
    string command;
    LoggingObserver* log1;
};


class CommandProcessor : public ILoggable, public Subject{
public:

    Commands getEnumCommands();
    Command* readCommand();
    void saveCommand(Command* command);
    Command* getCommand();
    bool validate(Command* command, GameEngine::State state);
    string stringToLog();

private:
    list<Command*> lc;
};
class FileLineReader{
public:
    void readLineFromFile();
};
class FileCommandProcessorAdapter: CommandProcessor{
public:
    Command* readCommand();
    FileLineReader flr;
    string fileName;
    FileCommandProcessorAdapter(string fileName);
private:

};

void testCommandProcessor();

#endif //PROJECT_1_COMMANDPROCESSOR_H