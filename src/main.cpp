#include "../include/tools/Parser.h"
#include "../include/tools/Scanner.h"
#include "../lib/toollib/Parser.cpp"
#include "../lib/toollib/Scanner.cpp"
#include "../lib/Node.cpp"

int main(int argc, char *argv[])
{
    Status status = OK;
    do
    {
        cout << ">>";
        string buffer;
        getline(cin, buffer);
        cout << buffer << endl;
        Scanner scn(buffer);
        Parser parser(scn);
        parser.Parse();
        parser.Calcuate();
    } while (status != QUIT);
}
