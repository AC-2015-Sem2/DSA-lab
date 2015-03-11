#include "CmdLine.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

CmdLine::CmdLine(ifstream* newIn, ofstream* newOut)
    : mIn(newIn), mOut(newOut) {
    mList = new SingleList();
    }

CmdLine::~CmdLine() {
    delete mList;
}

void CmdLine::act(string* line) {
    // line = [cmd] [prameter]

    int cmdEnd = line->find_first_of(" ");

    // if line has no parameter x
    if (cmdEnd == -1) {
            // -1 == string::npos

        if (!line->compare("DF")) {
            mList->delFirst();
        } else if (!line->compare("DL")) {
            mList->delLast();
        } else if (!line->compare("DOOM_THE_LIST")) {
            mList->delAll();
        } else if (!line->compare("PRINT_ALL")) {
            mList->printAll(mOut);
        }
    } else {
        // if it has a parameter

        // separate command from parameter
        // can use tokens in C
        string cmd = line->substr(0, cmdEnd);

        // check if command has the needed parameter
        if (cmdEnd+1 < line->length()) {
            string sX = line->substr(cmdEnd+1);
            int x = atoi(sX.c_str());

            if (!cmd.compare("AF")) {
                mList->addFirst(x);
            } else if (!cmd.compare("AL")) {
                mList->addLast(x);
            } else if (!cmd.compare("DE")) {
                mList->del(x);
            } else if (!cmd.compare("PRINT_F")) {
                mList->printFirst(mOut, x);
            } else if (!cmd.compare("PRINT_L")) {
                mList->printLast(mOut, x);
            } else {
                *mOut << "Unknown command\n";
            }
        } else {
            *mOut << "Missing parameter\n";
        }
    }

}

void CmdLine::act(char* cstr) {
    string line(cstr);

    this->act(&line);
}

int CmdLine::processInput() {
    if (mIn->is_open()) {
        string line;

        while (getline(*mIn, line)) {
            this->act(&line);
        }
    } else {
        return 1;
    }

    return 0;
}
