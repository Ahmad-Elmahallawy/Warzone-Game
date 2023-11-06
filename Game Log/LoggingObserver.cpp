#include "LoggingObserver.h"

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


