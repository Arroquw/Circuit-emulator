#pragma once
class Node {
public:
    virtual ~Node();
    virtual Node *clone() const = 0;
    virtual void action() const = 0;
private:

protected:
    explicit Node(const char*);
    Node();
};

