#ifndef _NODE_H_
#define _NODE_H_

class Noncopyable
{
private:
    Noncopyable(const Noncopyable &other);
    const Noncopyable &operator=(const Noncopyable &other);

protected:
    Noncopyable(){};
    ~Noncopyable(){};
};

class Node : Noncopyable
{
public:
    virtual ~Node() = 0;
    virtual double Calc() const = 0;
};
class NumberNode : public Node
{
private:
    const double number_;

public:
    NumberNode(double num) : number_(num){};
    ~NumberNode(){};

public:
    double Calc() const;
};
// BinaryNode
class BinaryNde : public Node
{
protected:
    Node *const left_;
    Node *const right_;

public:
    BinaryNde(Node *left, Node *right) : left_(left), right_(right){};
    ~BinaryNde()
    {
        delete left_;
        delete right_;
    };
};

// UnaryNode
class UnaryNode : public Node
{
protected:
    Node *const child_;

public:
    UnaryNode(Node *child) : child_(child){};
    ~UnaryNode()
    {
        delete child_;
    };
};

class AddNode : public BinaryNde
{
private:
    /* data */
public:
    AddNode(Node *left, Node *right) : BinaryNde(left, right){};
    ~AddNode(){};
    double Calc() const;
};

class SubNode : public BinaryNde
{
private:
    /* data */
public:
    SubNode(Node *left, Node *right) : BinaryNde(left, right){};
    ~SubNode(){};
    double Calc() const;
};

class MultipleNode : public BinaryNde
{
private:
    /* data */
public:
    MultipleNode(Node *left, Node *right) : BinaryNde(left, right){};
    ~MultipleNode(){};
    double Calc() const;
};

class DividedNode : public BinaryNde
{
private:
    /* data */
public:
    DividedNode(Node *left, Node *right) : BinaryNde(left, right){};
    ~DividedNode(){};
    double Calc() const;
};

class UminusNode : public UnaryNode
{
private:
    /* data */
public:
    UminusNode(Node *child) : UnaryNode(child){};
    ~UminusNode(){};
    double Calc() const;
};

#endif // _NODE_H_