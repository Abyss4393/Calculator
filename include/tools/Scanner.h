#include <iostream>
#include <string>
using namespace std;
#ifndef _SCANNER_H_
#define _SCANNER_H_

enum EStatus
{
    END,
    ERROR,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLE,
    DIVIDE,
    LPARENTHESES,
    RPARENTHESES,
    IDENTIFIER,
    ASSIGN
};

class Scanner
{
private:
    const string buf_;
    unsigned int curPos_;
    EStatus sus_;
    double num_;

    void SkipWhite();

public:
    Scanner(const string &buf);
    ~Scanner();
    void Accept();
    double Number() const;
    EStatus Status() const;
};
#endif // _SCANNER_H_