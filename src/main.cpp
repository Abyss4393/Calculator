#include <iostream>
#include <string>
#include "../include/tools/Parser.h"
#include "../include/tools/Scanner.h"
#include "../lib/toollib/Parser.cpp"
#include "../lib/toollib/Scanner.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    cout << ">>";
    string buffer;
    getline(cin, buffer);
    cout << buffer << endl;
}
