#include "LoggingObserver.h"
#include "FileWriter.h"

ILoggable::ILoggable() {} // default constructor

ILoggable::ILoggable(const ILoggable &i1) {} // copy constructor

ILoggable::~ILoggable() {} // DESTRUCTOR

ostream& operator<<(ostream& os, const ILoggable& i1) {
    os << "This is an ILoggable object";
    return os;
}

ILoggable& ILoggable::operator=(const ILoggable *i1) {
    return *this;
}

Subject::Subject() {}

Subject::~Subject() {}

Subject::Subject(const Subject& s1) {}

void Subject::Attach(Observer* o1) {
    listObservers.push_back(o1);
}

void Subject::Detach(Observer* o1) {
    listObservers.remove(o1);
}

void Subject::Notify(ILoggable *i1) {
    for (Observer* observer : listObservers) {
        observer->Update(i1);
    }
}

ostream& operator<<(ostream& os, const Subject& s1) {
    list<Observer*> l1 = s1.listObservers;
    os << "The observers of this subject are: ";
    for(Observer* observer : l1) {
        os << observer << ", ";
    }
    return os;
}

Subject& Subject::operator=(const Subject& s1) {
    return *this;
}

Observer::Observer() {}

Observer::Observer(const Observer &o1) {}

Observer::~Observer() {}

Observer& Observer::operator=(const Observer& c) {
    return *this;
}

ostream& operator<<(ostream& os, const Observer& o1) {
    os << "This is an abstract observer!";
    return os;
}

LoggingObserver::LoggingObserver() {
    s1 = nullptr;
}

LoggingObserver::LoggingObserver(const LoggingObserver& other) {
    s1 = other.s1;
    if (s1 != nullptr) {
        s1->Attach(this);
    }
}

LoggingObserver::LoggingObserver(Subject *s12) {
    s1 = s12;
    if(s1 != nullptr)
        s1 ->Attach(this);

}

LoggingObserver::~LoggingObserver() {
    if(s1 != nullptr)
        s1->Detach(this);
}

ostream& operator<<(ostream& os, const LoggingObserver& log1) {
    os << "This Log observer object observes this subject - " << log1.s1 << "." << endl;
    return os;
}

LoggingObserver& LoggingObserver::operator=(const LoggingObserver &log1) {
    if(s1 != nullptr)
        s1->Detach(this);
    s1 = log1.s1;
    if(s1 != nullptr)
        s1->Attach(this);
    return *this;
}

void LoggingObserver::Update(ILoggable *i1) {
    string s1 = i1->stringToLog();

    FileWriter fw1;
    fw1.openFile();
    fw1.writeTofile(s1);
    fw1.println();
    fw1.writeTofile("/--------------/");
    fw1.println();
    fw1.closeFile();
}

