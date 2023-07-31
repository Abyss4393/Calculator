
#ifndef _PARSER_H_
#define _PARSER_H_
class Scanner;

class Parser
{
private:
    Scanner &scanner_;

public:
    Parser(Scanner &scn);
    ~Parser();
    void Parse();
    double Calcuate() const;
};

#endif // _PARSER_H_