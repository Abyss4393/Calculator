#include "../include/node/Node.h"
#include <cmath>
#include <iostream>
using namespace std;

double NumberNode::Calc() const
{
    return number_;
}

double AddNode::Calc() const
{
    return left_->Calc() + right_->Calc();
}

double SubNode::Calc() const
{
    return left_->Calc() - right_->Calc();
}

double MultipleNode::Calc() const
{
    return left_->Calc() * right_->Calc();
}

double DividedNode::Calc() const
{
    if (right_->Calc() != 0)
        return left_->Calc() / right_->Calc();
    else
    {
        cout << "Error the divied is Zro" << endl;
        return HUGE_VAL;
    }
}

double UminusNode::Calc() const
{
    return -child_->Calc();
}