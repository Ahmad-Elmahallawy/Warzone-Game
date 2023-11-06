#ifndef PROJECT_1_LOGGINGOBSERVER_H
#define PROJECT_1_LOGGINGOBSERVER_H

#include <ostream>

using namespace std;

class ILoggable {
public:

    virtual ~ILoggable(); // destuctor
    virtual string stringToLog() = 0; // returns a string to be output to the log file
    friend ostream& operator<<(ostream& os, const ILoggable& i1); // insertion operator

protected:

    ILoggable(); // constuctor
    ILoggable(const ILoggable& i1); // copy constructor
    ILoggable& operator=(const ILoggable* i1); //assignment operator

};


class Observer {
public:
    
    virtual ~Observer(); // destructor
    virtual void update(ILoggable* i1) = 0; // update view whose observer observers
    friend ostream& operator<<(ostream& os, Observer& o1); //insertion operator

protected:

    Observer(); //default constructor
    Observer(const Observer& o1); // copy constructor
    Observer& operator=(const Observer& o1); // assignment operator

};

class Subject;

class LoggingObserver: public Observer{

public:

    LoggingObserver(); // default constructor
    LoggingObserver(Subject* s1); // defined constructor
    LoggingObserver(const LoggingObserver& log1); // copy constructor=
    ~LoggingObserver() override; // destructor
    friend ostream& operator<<(ostream& os, const LoggingObserver& log1); // insertion operator
    LoggingObserver& operator=(const LoggingObserver& log1); // assignment operator
    void update(ILoggable* i1); // to update the views

private:

    Subject* s1; // a subject that is attached to the observer
    
};

void testLoggingObserver();

#endif //PROJECT_1_LOGGINGOBSERVER_H
