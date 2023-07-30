#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    cout << ">>";
    string buffer;
    getline(cin, buffer);
    cout << buffer << endl;
}
