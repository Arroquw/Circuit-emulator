#pragma once
#include "CircuitVisitor.h"

class Node {
public:
    virtual ~Node();
    virtual Node *clone() const = 0;
    virtual void action() const = 0;
    virtual void accept(CircuitVisitor&) = 0;
protected:
    explicit Node(const char*);
    Node();
};

