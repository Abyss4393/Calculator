#ifndef _PARSER_H_
#define _PARSER_H_

class Node;
class Scanner;

enum Status
{
    OK,
    QUIT,
    S_ERROR
};

class Parser
{
private:
    Scanner &scanner_;
    Node *tree_;
    Status status_;

public:
    Parser(Scanner &scn);
    ~Parser();
    void Parse();
    Node *Expr();
    Node *Term();
    Node *Factor();
    double Calcuate() const;
};

#endif // _PARSER_H_