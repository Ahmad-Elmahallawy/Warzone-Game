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
    Command(const Command& other);
    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Command& obj);
    bool operator==(const Command &rhs) const;
    bool operator!=(const Command &rhs) const;

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
    CommandProcessing(const CommandProcessing& other);
    // Stream insertion operator
    CommandProcessing();
    friend std::ostream& operator<<(std::ostream& os, const CommandProcessing& obj);
    bool operator==(const CommandProcessing &rhs) const;
    bool operator!=(const CommandProcessing &rhs) const;

};
class FileLineReader{
public:
    FileLineReader();
    Command* readLineFromFile(string filename);
    ~FileLineReader();
    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const FileLineReader& obj);
    bool operator==(const FileLineReader& other) const;
    // Copy constructor
    FileLineReader(const FileLineReader& other);
};
class FileCommandProcessorAdapter: public CommandProcessing{
public:
    Command* readCommand();
    string fileName;
    FileCommandProcessorAdapter(string fileName);
    FileLineReader* flr;
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other);
    ~FileCommandProcessorAdapter();
    bool operator==(const FileCommandProcessorAdapter &rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const FileCommandProcessorAdapter& obj);
    bool operator!=(const FileCommandProcessorAdapter &rhs) const;

private:

};

void testCommandProcessor();
#endif //PROJECT_1_COMMANDPROCESSING_H









