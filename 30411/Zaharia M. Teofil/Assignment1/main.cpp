#include "CmdLine.hpp"
#include <iostream>
using namespace std;


int main() {
    ifstream in("input.dat");
    ofstream out("output.dat");

    CmdLine cl(&in, &out);
    cl.processInput();

    in.close();
    out.close();
    return 0;
}
