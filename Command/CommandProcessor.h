
#ifndef PROJECT_1_COMMANDPROCESSOR_H
#define PROJECT_1_COMMANDPROCESSOR_H
//
// Created by oimbs on 11/6/2023.
//
using namespace std;
#include <iostream>
#include <list>
enum State;
class Command{
public:
    string effect;
    string secondParameter;
    void saveEffect(string effect);
    string getCommand();
    string getEffect();
    Command(string command);
    Command(string command, string secondParameter);
private:
    string command;
};
class CommandProcessor{
public:
    list<Command*> lc;
    Command* readCommand();
    void saveCommand(Command* command);
    Command* getCommand();
    bool validate(Command* command, State state);
private:

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

#endif PROJECT_1_COMMANDPROCESSOR_H
