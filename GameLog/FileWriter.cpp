#include "FileWriter.h"

FileWriter::FileWriter() : path("C:\\Users\\khale\\COMP345-Warzone\\gamelog.txt") {}

FileWriter::FileWriter(string s1) : path(s1) {}

FileWriter::~FileWriter() {}

FileWriter::FileWriter(const FileWriter &obj)  {
    path = obj.path;
}

ostream& operator<<(ostream& os, const FileWriter& f1) {
    os << "This is a File Writer object with this path- " << f1.path << "- and file status - " << (f1.fs1.is_open() ? "is open." : "is closed.");
    return os;
}

FileWriter& FileWriter::operator=(const FileWriter &f1) {
    path = f1.path;
    return *this;
}

void FileWriter::openFile() {
    fs1.open(path, ios::out | ios::app);
}

void FileWriter::closeFile() {
    fs1.close();
}

void FileWriter::writeTofile(std::string text) {
    fs1 << text;
    fs1.flush();
}

void FileWriter::println() {
    fs1 << endl;
}


