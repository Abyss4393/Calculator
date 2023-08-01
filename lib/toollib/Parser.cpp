#include "../include/tools/Scanner.h"
#include "../include/node/Node.h"
#include "../include/tools/Parser.h"

#include <cassert>

Parser::Parser(Scanner &scn) : scanner_(scn), tree_(0) {}
Parser::~Parser() {}

Node *Parser::Expr()
{
    Node *root = Term();
    Node *r;
    switch (scanner_.Status())
    {
    case PLUS:
        scanner_.Accept();
        r = Expr();
        root = new AddNode(root, r);
        break;
    case MINUS:
        scanner_.Accept();
        r = Expr();
        root = new SubNode(root, r);
        break;
    default:
        break;
    }

    return root;
}

Node *Parser::Term()
{
    Node *root = Factor();
    Node *r;
    switch (scanner_.Status())
    {
    case MULTIPLE:
        scanner_.Accept();
        r = Term();
        root = new MultipleNode(root, r);
        break;
    case DIVIDE:
        scanner_.Accept();
        r = Term();
        root = new DividedNode(root, r);
        break;
    default:
        break;
    }

    return root;
}
Node *Parser::Factor()
{
    Node *root;

    switch (scanner_.Status())
    {
    case LPARENTHESES:
        scanner_.Accept();
        root = Expr();
        if (scanner_.Status() == RPARENTHESES)
            scanner_.Accept();
        else
        {
            status_ = S_ERROR;
            root = 0;
            throw new exception("missing ')'");
        }

        break;
    case NUMBER:
        root = new NumberNode(scanner_.Number());
        scanner_.Accept();
        break;
    case MINUS:
        scanner_.Accept();
        root = new UminusNode(Factor());
        break;
    default:
        status_ = Status::S_ERROR;
        break;
    }

    return root;
}
void Parser::Parse()
{
    Expr();
}

double Parser::Calcuate() const
{
    assert(tree_ != 0);
    return tree_->Calc();
}