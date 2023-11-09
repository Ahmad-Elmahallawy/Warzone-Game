#ifndef PROJECT_1_FILEWRITER_H
#define PROJECT_1_FILEWRITER_H

#include <string>;
#include <fstream>;

using namespace std;

class FileWriter {
public:
    FileWriter();
    FileWriter(const FileWriter& obj);
    ~FileWriter();
    FileWriter(string s1); // user-defined constructor
    friend ostream& operator<<(ostream& os, const FileWriter& f1);
    FileWriter& operator=(const FileWriter& f1);

    void openFile();
    void openNewFile();
    void closeFile();
    void writeTofile(string text);
    void println();

private:
    string path;
    fstream fs1;
};


#endif //PROJECT_1_FILEWRITER_H
