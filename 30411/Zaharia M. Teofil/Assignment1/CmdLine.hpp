#ifndef CMDLINE_HPP
#define CMDLINE_HPP

#include "SingleList.hpp"
#include <fstream>
#include <string>
using std::ofstream;
using std::ifstream;
using std::string;

class CmdLine {
public:
    CmdLine(ifstream* newIn, ofstream* newOut);
    ~CmdLine();

    void act(string* line);
    void act(char* cstr);

    int processInput(); // 0 = OK, 1 = error
private:
    SingleList* mList;
    ifstream* mIn;
    ofstream* mOut;
};

#endif // CMDLINE_HPP
