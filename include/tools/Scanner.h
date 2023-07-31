#include <iostream>
#include <string>
using namespace std;
#ifndef _SCANNER_H_
#define _SCANNER_H_

class Scanner
{
private:
    const string buf_;
public:
    Scanner(const string &buf): buf_(buf){};
    ~Scanner(){};
};

\

#endif // _SCANNER_H_