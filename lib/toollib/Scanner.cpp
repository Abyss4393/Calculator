#include "../include/tools/Scanner.h"
#include <cctype>
Scanner::Scanner(const string &buf) : buf_(buf), curPos_(0)
{
    Accept();
}
Scanner::~Scanner() {}

EStatus Scanner::Status() const
{
    return sus_;
}

double Scanner::Number() const
{
    return num_;
}

void Scanner::SkipWhite()
{
    while (isspace(buf_[curPos_]))
        ++curPos_;
}

void Scanner::Accept()
{
    SkipWhite();
    switch (buf_[curPos_])
    {
    case '+':
        sus_ = PLUS;
        ++curPos_;
        break;
    case '-':
        sus_ = MINUS;
        ++curPos_;
        break;
    case '*':
        sus_ = MULTIPLE;
        ++curPos_;
        break;
    case '/':
        sus_ = DIVIDE;
        ++curPos_;
        break;
    case '(':
        sus_ = LPARENTHESES;
        ++curPos_;
        break;
    case ')':
        sus_ = RPARENTHESES;
        ++curPos_;
        break;
    case '=':
        sus_ = ASSIGN;
        ++curPos_;
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        sus_ = NUMBER;
        char *p;
        num_ = strtod(&buf_[curPos_], &p);
        curPos_ = p - &buf_[0];
        break;
    case '\0':
    case '\r':
    case '\n':
    case EOF:
        sus_ = END;
        break;

    default:
        sus_ = ERROR;
        break;
    }
}
